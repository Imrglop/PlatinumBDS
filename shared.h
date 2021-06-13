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

#if defined(_DEBUG)
#	define PLATINUM_DBG
#endif

#pragma once
#include <iostream>
#include <MinHook.h>
#include <Windows.h>

HANDLE getConsoleOutput();
void setConsoleColor(WORD attributes);
typedef unsigned char byte;

#define _PLOG(l, x) std::cout<<"["<<l<<"] [INFO] ("<<__func__<<":"<<__LINE__<<") " << x << std::endl
#define _PERR(l, x) setConsoleColor(0xC); std::cout<<"["<<l<<"] [ERROR] ("<<__func__<<":"<<__LINE__<<") " << x << std::endl; setConsoleColor(0x7)
#define _PWARN(l, x) setConsoleColor(0xE); std::cout<<"["<<l<<"] [WARN] ("<<__func__<<":"<<__LINE__<<") " << x << std::endl; setConsoleColor(0x7)
#if defined(PLATINUM_DBG)
#	define _PDBG(l, x) setConsoleColor(0xB); std::cout<<"["<<l<<"] [DEBUG] ("<<__func__<<":"<<__LINE__<<") " << x << std::endl; setConsoleColor(0x7)
#endif

#define llog(x) _PLOG("Platinum", x)
#define lerr(x) _PERR("Platinum", x)
#define lwarn(x) _PWARN("Platinum", x)
#if defined(PLATINUM_DBG)
#	define ldbg(x) _PDBG("Platinum", x)
#endif