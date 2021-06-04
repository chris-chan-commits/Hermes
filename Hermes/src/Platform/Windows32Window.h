#pragma once

#include "Logger/Logger.h"
#include "Core.h"
#ifdef HERMES_PLATFORM_WINDOWS
#include "Window/IWindow.h"

#include <Windows.h>

namespace Hermes {
	CLASS Windows32Window : public IWindow
	{
	public:
		virtual VOID Initialize(INT width, INT height, STRING title) override;
		virtual VOID Update() override;

		virtual B00L ShouldClose() override;
	private:
		B00L m_Closing = FALSE;
		INT m_Width, m_Height;
		STRING m_Title;
		HWND m_Handle;
	};
}
#else
#error Trying to include Windows32Window.h, however, not on windows!
#endif