#include "LayerManager.h"

namespace Impara
{
	LayerManager::LayerManager()
	{
	}
	LayerManager::~LayerManager()
	{
		for (auto layer : m_Layers)
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
	void LayerManager::UpdateLayers()
	{
		for (auto layer : m_Layers)
		{
			layer->OnTick();
		}
	}
	void LayerManager::PopLayer(Layer* layer)
	{
		layer->OnDetach();

		m_Layers.erase(
			std::remove(
				m_Layers.begin(),
				m_Layers.end(),
				layer
			),
			m_Layers.end()
		);
	}
}