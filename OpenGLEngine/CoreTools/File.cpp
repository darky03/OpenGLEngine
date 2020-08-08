#include "File.h"


File::File()
{
}
void File::Open(const std::string& filepath)
{
	if (!this->m_File.is_open())
	{
		this->m_File.open(filepath, std::fstream::app | std::fstream::in);
	}
}
bool File::Exists()
{
	if (this->m_File.is_open() && this->m_File.good()) {
		return true;
	}
	return false;
}
void File::Rewind()
{
	if (this->m_File.is_open())
	{
		this->m_File.seekg(0);
		this->m_File.seekp(0);
	}
}
bool File::IsEOF()
{
	return this->m_File.eof();
}
std::string File::ReadLine()
{
	std::string result;
	std::getline(this->m_File, result);
	return result;
}
std::string File::ReadFile()
{
	std::string result;
	std::string line;
	this->Rewind();
	while (!this->m_File.eof())
	{
		std::getline(this->m_File, line);
		result += line + "\r\n";
	}
	return result;
}
void File::Close()
{
	if (this->m_File.is_open())
	{
		this->m_File.close();
	}
}
File::~File()
{
	this->Close();
}