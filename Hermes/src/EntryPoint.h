#pragma once

#include "Application/Application.h"

Hermes::Application* CreateApplication();

extern "C" int main (int argc, char** argv)
{
	auto application = CreateApplication();
	
	application->Run(); // Run the application

	delete application;
}