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

		VOID Run();

		VOID PushExtension(Extension* extension);
		VOID PopExtension(Extension* extension);
	private:
		VOID _InitializeWindow();
	private:
		IWindow* m_Window;
		bool m_Running = TRUE;
		ExtensionManager m_ExtensionManager;
	};

}