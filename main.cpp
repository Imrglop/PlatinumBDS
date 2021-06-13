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
bool _isLegacyVersion = false;

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

    funcs.ServerNetworkHandler_handle_SpawnExperienceOrbPacket = scanner.scan(
        getFunction("ServerNetworkHandler::handle(SpawnExperienceOrbPacket)", false)
    );

    funcs._getSeed_return_address = scanner.scan(
        getFunction("_getSeed return address", false)
    );

    funcs.LevelData_getSeed = scanner.scan(
        getFunction("LevelData::getSeed", false)
    );

    if (getFunction("__player_vtable_direct", false) == "true") {
        std::string str = getFunction("Player::`vftable'");
        funcs.Player_vtable = data.base + std::stoul(str, nullptr, 16);
#ifdef PLATINUM_DBG
        ldbg("player::`vftable'=" << funcs.Player_vtable);
#endif
    }
    else {
        uintptr_t sigRes = scanner.scan(getFunction("Player::`vftable'", false));
        if (sigRes != 0) {
#ifdef PLATINUM_DBG
            ldbg("sigres: " << (void*)sigRes);
#endif
            int offset = *reinterpret_cast<int*>(sigRes + 3); // lea .., [<this value>], offset will wrap around
            funcs.Player_vtable = sigRes + offset + 7;
        }
    }

    // -------------- SUCCESS CHECK --------------

    int amountOfZeroFunctions = 0;
    size_t sizeOfFunctions = sizeof(funcs);
    size_t amountOfFunctions = sizeOfFunctions / sizeof(uintptr_t);
    uintptr_t* lpFuncs = reinterpret_cast<uintptr_t*>(&funcs);

    for (size_t i = 0; i < amountOfFunctions; i++) {
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

size_t numEnabledMods = 0;

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

    _isLegacyVersion = settings::getSettings()->getBool("legacy-bds-version");

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
            mod->enabled = settings::getModuleBool(mod->nid, "enabled");
            if (mod->enabled) {
                if (!mod->enable()) {
                    mod->enabled = false;
                    lerr("Mod " << mod->name << " failed to load.");
                }
                else {
                    llog("Loaded " << mod->name << ".");
                    numEnabledMods++;
                }
            }
#ifdef PLATINUM_DBG
            else {
                ldbg(mod->nid << ": not enabled");
            }
#endif
        }
        llog("Enabled " << numEnabledMods << " modules.");

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
        for (Module* mod : modules) {
            if (mod->enabled) {
                mod->disable();
                llog("Unloaded " << mod->name);
            }
        }
        MH_Uninitialize();
        if (numEnabledMods > 0) {
            llog("Disabled " << numEnabledMods << " modules.");
        }
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

bool main::isLegacyVersion() {
    return _isLegacyVersion;
}