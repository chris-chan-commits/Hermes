#pragma once

#include "Core.h"
#include "types.h"

namespace Hermes {
	CLASS Extension
	{
	public:
		/*- Constructor -*/
		Extension(STRING name);

		/*- Destructor -*/
		~Extension();

		inline STRING GetName(){ return m_Name; }

		virtual void OnAttach() {}
		virtual void OnTick() {}
		virtual void OnDetach() {}

	private:
		STRING m_Name;
	};
}