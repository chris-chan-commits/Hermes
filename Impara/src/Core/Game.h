#pragma once

#include <iostream>
#include "DLL.h"
#include "ImparaAllocator.h"
#include "LayerManager.h"

namespace Impara
{
	class IMPARA_API Game
	{
	public:
		Game();
		~Game();

		void Run();

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);
	private:
		bool m_Running = true;

		ImparaAllocator* m_Alloc;
		LayerManager m_LayerManager;
	};
}