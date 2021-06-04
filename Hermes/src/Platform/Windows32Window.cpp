#include "Windows32Window.h"

#define INSTANCE GetModuleHandle(NULL)

static wchar_t className[256] = L"default class";

#define CURSOR IDC_HAND

LRESULT CALLBACK WindowProc(
	HWND hWnd,
	UINT Msg,
	WPARAM wParam,
	LPARAM lParam)
{
	switch (Msg)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		return 0;
	case WM_CHAR:
		static std::wstring title;
		if (wParam == VK_BACK)
		{
			if(title.size() > 0)
				title.pop_back();
		}
		else
			title += wParam;
		

		SetWindowText(hWnd, title.c_str());
		break;
	}

	return DefWindowProc(hWnd, Msg, wParam, lParam);
}

namespace Hermes {
	VOID Windows32Window::Initialize(INT width, INT height, STRING title)
	{
		/*- Trace -*/
		HERMES_TRACE("Initializing Win32Window!");

		/*- Initializing members -*/
		m_Width = width; m_Height = height;
		m_Title = title;
		/*- Class -*/
		WNDCLASSEX wc = {};
		wc.cbClsExtra = NULL;
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.cbWndExtra = NULL;
		wc.hbrBackground = CreateSolidBrush(RGB(1, 0, 0));
		wc.hCursor = LoadCursor(NULL, CURSOR);
		wc.hIcon = NULL;
		wc.hIconSm = NULL;
		wc.hInstance = INSTANCE;
		wc.lpfnWndProc = WindowProc;
		wc.lpszClassName = className;
		wc.lpszMenuName = nullptr;
		wc.style = NULL;

		RegisterClassEx(&wc);

		const WCHAR* wtitle;

		int nchars = MultiByteToWideChar(CP_ACP, 0, title, -1, NULL, 0);

		wtitle = new WCHAR[nchars];

		MultiByteToWideChar(CP_ACP, 0, title, -1, (LPWSTR)wtitle, nchars);


		/*- Window creation -*/
		m_Handle = CreateWindowEx(NULL, className, wtitle, WS_SYSMENU | WS_MINIMIZEBOX, 0, 0, width, height, NULL, NULL, INSTANCE, NULL);
		if (!m_Handle)
		{
			HERMES_FATAL("Failed to create window!");
		}
		ShowWindow(m_Handle, SW_SHOW);

		/*- Garbage collection -*/
		delete[] wtitle;
	}


	VOID Windows32Window::Update()
	{
		static MSG msg; // Static msg variable will stay on the memory

		if (GetMessage(&msg, NULL, NULL, NULL))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			m_Closing = true;
		}
	}

	B00L Windows32Window::ShouldClose()
	{
		return m_Closing;
	}
}