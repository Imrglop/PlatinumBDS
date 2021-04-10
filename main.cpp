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

#define PLATINUM_SEPERATE_THREAD FALSE

namespace mods
{
    Knockback kb;
    HurtTime hurtTime;
    BasicAntiCheat basicAC;
}

std::vector<Module*> modules = { &mods::kb, &mods::hurtTime, &mods::basicAC };

ModuleData data;
ModuleFunctions funcs;

SignatureScanner scanner = NULL;

bool scanSigs() {
    using namespace settings;
    funcs.KnockbackRules_useLegacyKnockback = scanner.scan(
        getFunction("KnockbackRules::useLegacyKnockback")
    );
    funcs.Mob_knockback = scanner.scan(
        getFunction("Mob::knockback")
    );
    funcs.Mob_hurtEffects_setHurtTime = scanner.scan(
        getFunction("Mob::hurtEffects:set-hurt-time")
    );
    //funcs.ItemUseInventoryTransaction_handle = scanner.scan(
    //    getFunction("ItemUseInventoryTransaction::handle")
    //);
    
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
#if PLATINUM_SEPERATE_THREAD == TRUE
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
        llog("Mods are disabled. Edit settings.txt to enable them.");
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