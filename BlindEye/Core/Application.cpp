#include "Application.h"
#include "BlindEyeIO.h"
#include "Time/Time.h"

namespace chrono = std::chrono;

namespace beye
{
	Application::Application(const std::string& name) :
		m_Name(name)
	{
		BE_CORE_INFO("Blind Eye is initializing!");
	
		int width = 0;
		int height = 0;
		std::string title = "";
		bool vsync = false;

		if (FileExists("engine.ini"))
		{
			std::stringstream filecontents(ReadFile("engine.ini"));
			std::string line;
			bool foundWidth = false;
			bool foundHeight = false;
			bool foundTitle = false;
			bool foundVsync = false;
			while (std::getline(filecontents, line, '\n'))
			{
				if (line[0] == 'W')
				{
					line.erase(line.begin(), line.begin() + 6);
					width = std::stoi(line);
					foundWidth = true;
				}
				if (line[0] == 'H')
				{
					line.erase(line.begin(), line.begin() + 7);
					height = std::stoi(line);
					foundHeight = true;
				}
				if (line[0] == 'T')
				{
					line.erase(line.begin(), line.begin() + 6);
					title = line;
					foundTitle = true;
				}
				if (line[0] == 'V')
				{
					line.erase(line.begin(), line.begin() + 6);
					vsync = std::stoi(line);
					foundVsync = true;
				}
			}

			if (!foundWidth || !foundHeight || !foundTitle || !foundVsync)
			{
				BE_CORE_ERROR("Engine configuration file is not proper.");
				BE_CORE_PAUSE();
				std::exit(-1);
			}
		}
		else
		{
			width = 1280;
			height = 720;
			title = name;
		}

		#ifdef BE_PLATFORM_WINDOWS
		m_Window = CreateRef<Win32Window>();
		m_Window->Initialize(width, height, title, vsync);
		#endif
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		#ifdef BE_PLATFORM_WINDOWS
		m_EventManager.PushEvent(new Win32WindowResizeEvent(m_Window));
		#endif
		m_EventManager.PushEvent(new TimeUpdateEvent());
		
		while (m_Running)
		{
			for (Layer* layer : m_LayerManager.GetLayers())
			{
				layer->OnUpdate();
			}

			for (Event* event : m_EventManager.GetEvents())
			{
				event->OnUpdate();
			}

			for (Script* script : ScriptSystem::Get().GetScripts())
			{
				script->OnUpdate();
			}
			
			if (m_Window->Closing())
			{
				m_Running = false;
			}



			m_Window->Poll();
		}
	}

	void Application::AttachLayer(Layer* layer)
	{
		m_LayerManager.PushLayer(layer);
	}

	void Application::DetachLayer(Layer* layer)
	{
		m_LayerManager.PopLayer(layer);
	}
}
