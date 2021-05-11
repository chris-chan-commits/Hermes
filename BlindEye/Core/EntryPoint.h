#pragma once

#include "Application.h"

extern "C" int main()
{
	beye::Application* app = CreateApplication();

	app->Run();


	return 0;
}