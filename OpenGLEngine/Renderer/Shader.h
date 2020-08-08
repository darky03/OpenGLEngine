#pragma once

#include <Common/Macros.h>
#include <Common/Constants.h>
#include <Core/Console.h>
#include <CoreTools/File.h>
#include <GL/glew.h>

#include <string>
#include <iostream>

class DLL Shader
{
private:
	GLuint m_Shaders[NUM_SHADERS];
	GLuint m_Program;
	//Shader sources and lengths
	GLint m_ShaderSourceLength[NUM_SHADERS];
	const GLchar* m_ShaderSources[NUM_SHADERS];

	GLint status;
	//Shader information after compiling the shader
	GLchar m_ShaderInfo[2048];
	//Program information after linking the program
	GLchar m_ProgramInfo[2048];
public:
	static File m_File;
	static std::string LoadShader(const std::string& shaderPath,bool& result);
private:
	void CreateShader(const std::string& shaderPath, int shaderType);
public:
	Shader();
	Shader(const std::string& shaderPath);
	void LoadShader(const std::string& shaderPath);
	void UseShader();
	~Shader();
};

