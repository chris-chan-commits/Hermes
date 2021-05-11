#pragma once

#include <string>
#include "Core.h"

namespace beye
{
	class BLIND_EYE_API Layer
	{
	public:
		Layer(const std::string& layerName);
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
	private:
		std::string m_LayerName;
	};
}