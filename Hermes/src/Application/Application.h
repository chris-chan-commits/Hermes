#pragma once

#include <iostream>

#include "Core.h"
#include "ExtensionManager/ExtensionManager.h"
#include "types.h"
#include "Window/IWindow.h"

namespace Hermes {
	class HERMES_API Application
	{
	public:
		/*- Constructor -*/
		Application();

		/*- Destructor -*/
		~Application();

		void Run();

		void PushExtension(Extension* extension);
		void PopExtension(Extension* extension);
	private:
		void _InitializeWindow();
	private:
		IWindow* m_Window;
		bool m_Running = TRUE;
		ExtensionManager m_ExtensionManager;
	};

}