#pragma once

#include <iostream>
#include <stdio.h>
#include "Lore.h"

namespace LoreFrameworks {
	class Logger
	{
	public:
		static Logger& Get()
		{
			static Logger instance;
			return instance;
		}

		void Info(STRING msg, ...);
		void Warn(STRING msg, ...);
		void Error(STRING msg, ...);

		// NOTE: This function exists the program after a key is pressed
		void Fatal(STRING msg, ...);
	};
}