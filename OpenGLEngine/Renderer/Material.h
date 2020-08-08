#pragma once

#include "Shader.h"

class Material
{
private:
	Shader* m_Shader;
public:
	Material();
	void SetShader(Shader* shader);
	Shader* GetShader();

	void ApplyShader();

	~Material();
};

