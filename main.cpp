/*
* 
* ------------------------------\
*          Platinum             |
*  Bedrock Dedicated Server     |
*  mod for enhancements and     |
*  more customization.          |
* ------------------------------/
* 
* This is Free Software: You can edit and distribute it
* under the MIT license.
* author: PlatinumBDS's contributors
* link: https://github.com/Imrglop/PlatinumBDS
*/

#include "main.h"
#include "Mod/include_all.h"
#include "Sig/SignatureScanner.h"
#include <vector>
#include <Psapi.h>
#include "Settings/settings.h"
#include "Mod/Module.h"

#define PLATINUM_SEPERATE_THREAD false

namespace mods
{
    Knockback kb;
    HurtTime hurtTime;
    BasicAntiCheat basicAC;
    SeedHider sh;
}

std::vector<Module*> modules = { &mods::kb, &mods::hurtTime, &mods::basicAC, &mods::sh };

ModuleData data;
ModuleFunctions funcs;

SignatureScanner scanner = NULL;

bool scanSigs() {
    using namespace settings;
    funcs.KnockbackRules_useLegacyKnockback = scanner.scan(
        getFunction("KnockbackRules::useLegacyKnockback", false)
    );
    funcs.Mob_knockback = scanner.scan(
        getFunction("Mob::knockback", false)
    );
    funcs.Mob_hurtEffects_setHurtTime = scanner.scan(
        getFunction("Mob::hurtEffects:set-hurt-time", false)
    );

    std::string movePlayerFunc = getFunction("MovePlayerPacket::_read", false);
    if (movePlayerFunc != "") {
        funcs.MovePlayerPacket__read = scanner.scan(movePlayerFunc);
    }
    
    std::string func = getFunction("LevelSettings::LevelSettings:set-seed", false);
    if (func != "") {
        funcs.LevelSettings_LevelSettings_setSeed = scanner.scan(func);
    }

    int amountOfZeroFunctions = 0;
    size_t sizeOfFunctions = sizeof(funcs);
    size_t amountOfFunctions = sizeOfFunctions / sizeof(uintptr_t);

    for (size_t i = 0; i < amountOfFunctions; i++) {
        uintptr_t* lpFuncs = reinterpret_cast<uintptr_t*>(&funcs);
        if (lpFuncs[i] == NULL) {
#if defined(PLATINUM_DBG)
            ldbg("Missing function (index: " << i << ")");
#endif
            amountOfZeroFunctions++;
        }
    }

    llog("Functions: (" << (amountOfFunctions - amountOfZeroFunctions) << " / " << 
        amountOfFunctions << ")");

    if (amountOfZeroFunctions != 0) {
        lwarn(amountOfZeroFunctions << " missing function(s). Not all modules will work.");
    }

    return true;
}

HANDLE output = NULL;

HANDLE getConsoleOutput() {
    if (output == NULL) {
        output = GetStdHandle(STD_OUTPUT_HANDLE);
    }
    return output;
}

DWORD 
#if PLATINUM_SEPERATE_THREAD
__stdcall
#endif
init(void* lpParam) {
    // -------------- GENERAL INIT --------------

    llog("Initializing.. (Thread ID: " << GetCurrentThreadId() << ")");
    auto status = MH_Initialize();
    if (status != MH_OK) {
        llog("Error loading MinHook! status = " << status);
        return EXIT_FAILURE;
    }

    settings::init(".");

    // -------------- INITIALIZE APPLICATION INFORMATION --------------

    HMODULE* pHModule = reinterpret_cast<HMODULE*>(lpParam);
    HMODULE hModule = *pHModule;
    data.base = (uintptr_t)GetModuleHandle(NULL);
    MODULEINFO info;
    GetModuleInformation(GetCurrentProcess(), (HMODULE)data.base, &info, sizeof(MODULEINFO));
    data.functionEnd = data.base + info.SizeOfImage;
    scanner = SignatureScanner(data.base, data.functionEnd);
    scanSigs();

    // -------------- INITIALIZE MODULES --------------

    auto settings = settings::getSettings();

    bool modsEnabled = settings->getBool("mod-enabled");

    if (modsEnabled) {
        for (Module* mod : modules) {
            if (settings::getModuleBool(mod->nid, "enabled")) {
                if (!mod->enable()) {
                    lerr("Mod " << mod->name << " failed to load.");
                }
                else {
                    llog("Loaded " << mod->name << ".");
                }
            }
        }
        llog("Enabled mods.");

    // -------------- INITIALIZE HOOKS --------------

        status = MH_EnableHook(MH_ALL_HOOKS);
        if (status != MH_OK) {
            lerr("Error enabling hooks! status = " << status);
            return EXIT_FAILURE;
        }
    }
    else {
        llog("Mods are disabled. Edit settings to enable them.");
    }

    return EXIT_SUCCESS;

    // ----------------------------------------------
}

int __stdcall DllMain(HMODULE hModule, DWORD ulCallReason)
{
    if (ulCallReason == DLL_PROCESS_ATTACH) {
#if PLATINUM_SEPERATE_THREAD == TRUE
        CreateThread(nullptr, 0, init, reinterpret_cast<void*>(&hModule), 0, nullptr);
#else
        init(reinterpret_cast<void*>(&hModule));
#endif
    }
    else if (ulCallReason == DLL_PROCESS_DETACH) {
        MH_Uninitialize();
    }
    return TRUE;
}

ModuleData& main::getData()
{
    return std::ref(data);
}

ModuleFunctions& main::getFunctions() {
    return std::ref(funcs);
}