#include <iostream>
#include <GL/glew.h>
#include <Core/Window.h>
#include <Core/Console.h>
#include <Renderer/Shader.h>

int arr[4][2] = {
	{-0.5f,-0.5f},
	{-0.5f,0.5f},
	{0.5f,0.5f},
	{0.5f,-0.5f}
};

void RenderFunction();

Shader m_Shader;

int main(int argc, char** argv)
{
	
	Console::LoadConsole();
	Window* gameWindow = new Window(0, 0, 800, 600, "OpenEngine v0.1a");
	
	m_Shader.LoadShader("./Shaders/BasicShader/basicShader");
	gameWindow->SetRenderFunction(&RenderFunction);
	gameWindow->RenderWindow();
	std::cout << "std::cin.get() is returned at the end, press any key to terminate the program now.." << std::endl;
	//return std::cin.get();
	return 0;
}

void RenderFunction()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.2f, 0.19f, 0.65f, 1.0f);
	m_Shader.UseShader();
	glBegin(GL_QUADS);
	glVertex3f(-0.5f, 0.5f, 0.0f);
	glVertex3f(0.5f, 0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glEnd();
}