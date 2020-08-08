#pragma once

#include <string>
#include <windows.h>

#include <iostream>
#include <Common/Macros.h>

class DLL Console
{
public:
	static HANDLE g_Console;
	static CONSOLE_SCREEN_BUFFER_INFO g_ScreenInfo; // We will restore the original color of the console after displaying a text
	static WORD g_OriginalScreenColor;
public:
	static void LoadConsole();

	static void Write(const std::string& text);
	static void DebugText(const std::string& text);
	static void WarnText(const std::string& text);
	static void ErrorText(const std::string& text);
	static void UnloadConsole();
};

