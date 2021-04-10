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

#define WIN32_LEAN_AND_MEAN

#pragma once
#include <iostream>
#include <MinHook.h>
#include <Windows.h>

HANDLE getConsoleOutput();
void setConsoleColor(WORD attributes);
typedef unsigned char byte;

#define _PLOG(l, x) std::cout<<"["<<l<<"] [INFO] ("<<__func__<<":"<<__LINE__<<") " << x << std::endl
#define _PERR(l, x) std::cout<<"["<<l<<"] [ERROR] ("<<__func__<<":"<<__LINE__<<") " << x << std::endl
#define _PWARN(l, x) std::cout<<"["<<l<<"] [WARN] ("<<__func__<<":"<<__LINE__<<") " << x << std::endl
#define _PDBG(l, x) std::cout<<"["<<l<<"] [DEBUG] ("<<__func__<<":"<<__LINE__<<") " << x << std::endl
#define llog(x) _PLOG("Platinum", x)
#define lerr(x) setConsoleColor(0xC); _PERR("Platinum", x); setConsoleColor(0x7)
#define lwarn(x) setConsoleColor(0xE); _PWARN("Platinum", x); setConsoleColor(0x7)
#define ldbg(x) setConsoleColor(0xB); _PDBG("Platinum", x); setConsoleColor(0x7)