#pragma once

#include <iostream>

#include "Core.h"
#include "ExtensionManager/ExtensionManager.h"
#include "types.h"
#include "Window/IWindow.h"

namespace Hermes {
	CLASS Application
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
		VOID InitializeWindow();
	private:
		IWindow* m_Window;
		bool m_Running = TRUE;
		ExtensionManager m_ExtensionManager;
	};

}