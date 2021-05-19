#pragma once

#include "Game.h"

// Define in client
Impara::Game* CreateGame();

extern "C" int main(int argc, char* argv[])
{
	Impara::Game* game = CreateGame();
	game->Run();

	delete game;
}