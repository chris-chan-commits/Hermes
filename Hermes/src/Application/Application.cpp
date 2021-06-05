#include "Application.h"

#ifdef HERMES_PLATFORM_WINDOWS
#include "Platform/Windows32Window.h"
#else
#error Currently does not support other window apis!
#endif

#include "Renderer/Renderer.h"

namespace Hermes {
	Application::Application()
	{

	}

	Application::~Application()
	{

	}
	void Application::Run()
	{
		_InitializeWindow();
		LowLevelRenderer::Get().Initialize(RendererApi::OpenGL);

		for (Extension* extension : m_ExtensionManager.GetExtensions())
		{
			extension->OnAttach();
		}

		while (m_Running)
		{
			LowLevelRenderer::Get().BeginRender();
			
			//TODO: Extension updates to be handled in the extension manager class
			for (Extension* extension : m_ExtensionManager.GetExtensions())
			{
				extension->OnTick();
			}

			// Update the window
			m_Window->Update();
		
			if (m_Window->ShouldClose())
			{
				m_Running = FALSE;
			}
		}
	}
	void Application::_InitializeWindow()
	{
		#ifdef HERMES_PLATFORM_WINDOWS
		m_Window = new Windows32Window;
		m_Window->Initialize(1280, 720, "Hello Hermes!", RendererApi::OpenGL);
		#endif
	}
	void Application::PushExtension(Extension* extension)
	{
		m_ExtensionManager.PushExtension(extension);
	}
	void Application::PopExtension(Extension* extension)
	{
		m_ExtensionManager.PopExtension(extension);
	}
}