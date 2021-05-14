#pragma once

#include "Core.h"
#include <string>
#include <thread>
#include "LayerManager.h"
#include "Window.h"
#include "Scripting System\ScriptSystem.h"
#include "Scripting System\Script.h"
#include "EventManager.h"

namespace beye
{
	class BLIND_EYE_API Application
	{
	public:
		Application(const std::string& name = "Blind Eye Application");
		virtual ~Application();

		void Run();

		void AttachLayer(Layer* layer);
		void DetachLayer(Layer* layer);
	private:
		EventManager m_EventManager;
		LayerManager m_LayerManager;
		bool m_Running = true;
		std::string m_Name;
		Ref<Window> m_Window;
	};
}

beye::Application* CreateApplication();