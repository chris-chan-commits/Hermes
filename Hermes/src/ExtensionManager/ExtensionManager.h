#pragma once

#include "Core.h"
#include "Extension/Extension.h"
#include <vector>
#include "types.h"

namespace Hermes {
	CLASS ExtensionManager 
	{
	public:
		void PushExtension(Extension* ext);
		void PopExtension(Extension* ext);

		inline std::vector<Extension*> GetExtensions() { return m_Extensions; }
	private:
		std::vector<Extension*> m_Extensions;
	};
}