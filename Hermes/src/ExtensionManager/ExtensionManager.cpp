#include "ExtensionManager.h"

namespace Hermes {
	ExtensionManager::~ExtensionManager()
	{
		for (Extension* extension : m_Extensions)
		{
			extension->OnDetach();

			delete extension;
		}
	}

	void ExtensionManager::PushExtension(Extension* ext)
	{
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