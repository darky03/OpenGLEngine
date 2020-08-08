#include "Material.h"


Material::Material()
{
	this->m_Shader = NULL;
}
void Material::SetShader(Shader* shader)
{
	this->m_Shader = shader;
}
Shader* Material::GetShader()
{
	return this->m_Shader;
}
void Material::ApplyShader()
{
	if (this->m_Shader != NULL)
	{
		this->m_Shader->UseShader();
	}
}
Material::~Material()
{

}