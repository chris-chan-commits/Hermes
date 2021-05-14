#pragma once

#include "Core/Core.h"

#include "Entity.h"

namespace beye
{
	class BLIND_EYE_API Script
	{
	public:
		Script(Ref<Entity> entity):
			p_Entity(entity){}
		virtual ~Script() = default;

		virtual void OnAttach() = 0;
		virtual void OnDetach() = 0;
		virtual void OnUpdate() = 0;
	protected:
		Ref<Entity> p_Entity;
	};
}