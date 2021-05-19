#pragma once

#include "Core/DLL.h"
#include <string>

namespace Impara
{
	class IMPARA_API Window
	{
	public:
		virtual void Initialize(int width, int height, const std::string& name) = 0;
		virtual void Update() = 0;
		virtual bool Closing() = 0;
	};
}