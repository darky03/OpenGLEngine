#include "Shader.h"

File Shader::m_File;

Shader::Shader()
{

}

std::string Shader::LoadShader(const std::string& shaderPath,bool& fileresult)
{
	fileresult = false;
	std::string result = "";
	Shader::m_File.Open(shaderPath);
	if (Shader::m_File.Exists()) {
		fileresult = true;
		result = Shader::m_File.ReadFile();
		Shader::m_File.Close();
	}
	return result;
}
Shader::Shader(const std::string& shaderPath)
{
	this->LoadShader(shaderPath);
}
void Shader::LoadShader(const std::string& shaderPath)
{
	bool fileResult;
	std::string m_Source[NUM_SHADERS];

	this->CreateShader(shaderPath + ".vs", VERT_SHADER);
	this->CreateShader(shaderPath + ".fs", FRAG_SHADER);
	this->m_Program = glCreateProgram();
	glAttachShader(this->m_Program, this->m_Shaders[VERT_SHADER]);
	glAttachShader(this->m_Program, this->m_Shaders[FRAG_SHADER]);
	glLinkProgram(this->m_Program);
	glGetProgramiv(this->m_Program, GL_LINK_STATUS, &this->status);
	if (this->status == GL_FALSE)
	{
		glGetProgramInfoLog(this->m_Program, sizeof(m_ProgramInfo), NULL, m_ProgramInfo);
		Console::ErrorText("Program linking failed (Shader: " + shaderPath + ")");
		Console::DebugText(m_ProgramInfo);
	}

}
void Shader::CreateShader(const std::string& shaderPath, int shaderType)
{
	bool fileResult = false;
	std::string m_Source;
	m_Source = Shader::LoadShader(shaderPath, fileResult);

	if (fileResult)
	{
		memset(m_ShaderInfo,'\0' , sizeof(m_ShaderInfo));
		
		if(shaderType == VERT_SHADER)
			this->m_Shaders[shaderType] = glCreateShader(GL_VERTEX_SHADER);
		else if(shaderType == FRAG_SHADER)
			this->m_Shaders[shaderType] = glCreateShader(GL_FRAGMENT_SHADER);

		this->m_ShaderSources[shaderType] = m_Source.c_str();
		this->m_ShaderSourceLength[shaderType] = m_Source.length();

		//Link the source code to shader on runtime
		glShaderSource(this->m_Shaders[shaderType], 1, &this->m_ShaderSources[shaderType], &this->m_ShaderSourceLength[shaderType]);
		//Compile the shader
		glCompileShader(this->m_Shaders[shaderType]);
		//Get the shaders compile status parameter
		glGetShaderiv(this->m_Shaders[shaderType], GL_COMPILE_STATUS, &this->status);

		if (this->status == GL_FALSE)
		{
			glGetShaderInfoLog(this->m_Shaders[shaderType], sizeof(m_ShaderInfo), NULL, m_ShaderInfo);
			Console::ErrorText("Shader (" + std::to_string(shaderType) + ") compilation failed!");
			Console::DebugText(m_ShaderInfo);
		}
	}
	else
	{
		Console::ErrorText("Could not find shader source at path '" + shaderPath + "'");
	}
}
void Shader::UseShader()
{
	glUseProgram(this->m_Program);
}
Shader::~Shader()
{
	glDeleteShader(this->m_Shaders[VERT_SHADER]);
	glDeleteShader(this->m_Shaders[FRAG_SHADER]);
	glDeleteProgram(this->m_Program);
}