#include "BlindEyeIO.h"

namespace beye
{
	std::string BLIND_EYE_API ReadFile(const std::string& filename)
	{
		std::ifstream file(filename);
		if (!file.is_open())
		{
			throw std::runtime_error("Failed to open file!");
			return NULL;
		}

		std::string line;
		std::string buffer;

		while (std::getline(file, line))
		{
			buffer += line + '\n';
		}

		file.close();

		return buffer;
	}
	void WriteFile(const std::string& filename, const std::string& contents)
	{
		std::ofstream file(filename);
		if (!file.is_open())
		{
			throw std::runtime_error("Failed to create file: " + filename + "!");
			return;
		}

		file.write(contents.c_str(), strlen(contents.c_str()));

		file.close();
	}
	bool FileExists(const std::string& filename)
	{
		std::ifstream file(filename);
		if (!file.is_open())
		{
			return false;
		}

		file.close();
		return true;
	}
}