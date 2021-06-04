#pragma once

#include "Logger/Logger.h"
#include "Core.h"
#ifdef HERMES_PLATFORM_WINDOWS
#include "Window/IWindow.h"

struct GLFWwindow;

namespace Hermes {
	class HERMES_API Windows32Window : public IWindow
	{
	public:
		virtual void Initialize(INT width, INT height, STRING title, const RendererApi& api) override;
		virtual void Update() override;

		virtual bool ShouldClose() override;
	private:
		bool m_Closing = FALSE;
		INT m_Width, m_Height;
		STRING m_Title;
		GLFWwindow* m_Handle;
	private:
		void _InitForOpenGL();
	};
}
#else
#error Trying to include Windows32Window.h, however, not on windows!
#endif