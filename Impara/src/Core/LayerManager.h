#pragma once

#include "DLL.h"
#include <vector>
#include "Layer.h"

namespace Impara
{
	class LayerManager
	{
	public:
		LayerManager();
		~LayerManager();

		void PushLayer(Layer* layer);
		void UpdateLayers();
		void PopLayer(Layer* layer);
	private:
		std::vector<Layer*> m_Layers;
	};
}