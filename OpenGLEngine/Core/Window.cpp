#include "Window.h"

Window::Window()
{
	this->m_Window = NULL;
	this->fn_Render = NULL;
}
Window::Window(int x, int y, int w, int h, const std::string& title)
{
	if (!glfwInit())
	{
		Console::ErrorText(std::string(__FUNCTION__) + " , Failed to Initialize GLFW");
		return;
	}

	this->m_Window = glfwCreateWindow(w, h, title.c_str(), NULL, NULL);
	if (!this->m_Window)
	{
		Console::ErrorText(std::string(__FUNCTION__) + "glfwCreateWindow failed to create a window");
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(this->m_Window);

	if (glewInit() != GLEW_OK)
	{
		Console::ErrorText(std::string(__FUNCTION__) + " , Failed to Initialize GLEW");
		return;
	}

	glfwSwapInterval(1);
	Console::DebugText(std::string(__FUNCTION__) + " , GLFW Window creation was succesfull, entering the rendering loop..");
	
}
void Window::RenderWindow()
{
	while (!glfwWindowShouldClose(this->m_Window))
	{
		if (this->fn_Render != NULL)
		{
			this->fn_Render();
		}
		glfwSwapBuffers(this->m_Window);
		glfwPollEvents();
	}
}
void Window::SetRenderFunction(void (*p)())
{
	this->fn_Render = p;
}
Window::~Window()
{
	if (this->m_Window != NULL)
	{
		glfwDestroyWindow(this->m_Window);
	}
}