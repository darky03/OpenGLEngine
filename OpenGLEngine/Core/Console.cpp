#include "Console.h"
HANDLE Console::g_Console;
CONSOLE_SCREEN_BUFFER_INFO Console::g_ScreenInfo;
WORD Console::g_OriginalScreenColor;
void Console::LoadConsole()
{
	Console::g_Console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(Console::g_Console, &Console::g_ScreenInfo);
	g_OriginalScreenColor = Console::g_ScreenInfo.wAttributes;
}
void Console::Write(const std::string& text)
{
	std::string tempText = text;
	std::cout << tempText << std::endl;
}
void Console::DebugText(const std::string& text)
{
	SetConsoleTextAttribute(Console::g_Console, (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY));
	std::string tempText = "[Debug]: " + text;
	std::cout << tempText << std::endl;
	SetConsoleTextAttribute(Console::g_Console, Console::g_OriginalScreenColor);
	
}
void Console::WarnText(const std::string& text)
{
	SetConsoleTextAttribute(Console::g_Console,(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY));
	std::string tempText = "[Warning]: " + text ;
	std::cout << tempText << std::endl;
	SetConsoleTextAttribute(Console::g_Console, Console::g_OriginalScreenColor);
}
void Console::ErrorText(const std::string& text)
{
	SetConsoleTextAttribute(Console::g_Console, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::string tempText = "[Error]: " + text;
	std::cout << tempText << std::endl;
	SetConsoleTextAttribute(Console::g_Console, Console::g_OriginalScreenColor);
}
void Console::UnloadConsole()
{
	CloseHandle(Console::g_Console);
}