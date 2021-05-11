#pragma once

#include <vector>
#include "Layer.h"

namespace beye
{
	class BLIND_EYE_API LayerManager
	{
	public:
		LayerManager()=default;
		~LayerManager();

		// Add a layer to the top of the list of layers
		void PushLayer(Layer* layer);

		// Remove a layer from the list of layers
		void PopLayer(Layer* layer);

		inline std::vector<Layer*> GetLayers()
		{
			return m_Layers;
		}
	private:
		std::vector<Layer*> m_Layers;
	};
}