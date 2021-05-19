#include "Game.h"
#include <Core\Graphics\Renderer\Renderer.h>

#include "Core/Graphics/Window.h"

#ifdef _WIN32
#include "Platform/Win32/Win32Window.h"
#endif

Impara::Win32Window g_Window;

namespace Impara
{
	Game::Game()
	{
		// Create the stack allocator
		m_Alloc = new ImparaAllocator(1600 * sizeof(byte), 160 * sizeof(byte));

#ifdef _WIN32
		// Create a win32 window
		g_Window.Initialize(1280, 720, "");
#endif

		Impara::Renderer::Initialize(Impara::API::OPENGL);
	}
	Game::~Game()
	{
		delete m_Alloc;
	}
	void Game::Run()
	{

		while (m_Running)
		{
			// Update all of the layers
			// Layers(such as an application layer) that are pushed to the application, are updated here
			m_LayerManager.UpdateLayers();
		
			// Poll events, and swap buffers
			g_Window.Update();


			// If the window is closing, set the running status to false
			if (g_Window.Closing())
			{
				m_Running = false;
			}
		}
	}
	void Game::PushLayer(Layer* layer)
	{
		m_LayerManager.PushLayer(layer);
	}
	void Game::PopLayer(Layer* layer)
	{
		m_LayerManager.PopLayer(layer);
	}
}