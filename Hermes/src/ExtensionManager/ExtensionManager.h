#pragma once

#include "Core.h"
#include "Extension/Extension.h"
#include <vector>
#include "types.h"

namespace Hermes {
	class HERMES_API ExtensionManager 
	{
	public:
		ExtensionManager() = default;
		~ExtensionManager();

		void PushExtension(Extension* ext);
		void PopExtension(Extension* ext);

		inline std::vector<Extension*> GetExtensions() { return m_Extensions; }
	private:
		std::vector<Extension*> m_Extensions;
	};
}