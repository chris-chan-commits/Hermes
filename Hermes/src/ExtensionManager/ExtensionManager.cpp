#include "ExtensionManager.h"

namespace Hermes {
	void ExtensionManager::PushExtension(Extension* ext)
	{
		ext->OnAttach();
		m_Extensions.push_back(ext);
	}

	void ExtensionManager::PopExtension(Extension* ext)
	{
		ext->OnDetach();
		m_Extensions.erase(
			std::remove(
				m_Extensions.begin(), 
				m_Extensions.end(), 
				ext), 
		m_Extensions.end());
	}
}