#include "LayerManager.h"

namespace beye
{
	LayerManager::~LayerManager()
	{
		for (Layer* layer : m_Layers)
		{
			layer->OnDetach();

			delete layer;
		}
	}
	void LayerManager::PushLayer(Layer* layer)
	{
		layer->OnAttach();
		m_Layers.push_back(layer);
	}
	void LayerManager::PopLayer(Layer* layer)
	{
		layer->OnDetach();

		m_Layers.erase
		(
				std::remove
				(
				m_Layers.begin(),
				m_Layers.end(),
				layer
				),
		m_Layers.end()
		);
	}
}