#pragma once

#include <iostream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <Common/Macros.h>
#include <Core/Console.h>

//typedef void (*RenderFn)();
class DLL Window
{
private:
	GLFWwindow* m_Window;
private:
	void (*fn_Render)();
public:
	Window();
	Window(int x, int y, int w, int h, const std::string& title);
	void SetRenderFunction(void (*p)());
	void RenderWindow();
	~Window();
};

