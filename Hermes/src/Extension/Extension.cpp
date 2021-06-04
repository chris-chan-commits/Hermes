#include "Extension.h"

#include "Logger/Logger.h"

namespace Hermes {
	Extension::Extension(STRING name):
		m_Name(name)
	{
		HERMES_TRACE("Initializing extension: %s...", name);
	}
	Extension::~Extension()
	{
	}
}