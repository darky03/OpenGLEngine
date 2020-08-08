#pragma once

#include <Common/Macros.h>

#include <string>
#include <fstream>

class DLL File
{
private:
	std::fstream m_File;
public:
	File();
	void Open(const std::string& filepath);
	void Rewind();
	bool IsEOF();
	bool Exists();
	std::string ReadLine();
	std::string ReadFile();
	void Close();
	~File();
};

