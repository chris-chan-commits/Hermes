#pragma once

#include "Core.h"
#include <iostream>
#include <fstream>
#include <sstream>

namespace beye
{
	std::string BLIND_EYE_API ReadFile(const std::string& filename);
	void BLIND_EYE_API WriteFile(const std::string& filename, const std::string& contents);
	bool FileExists(const std::string& filename);
}