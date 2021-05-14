#pragma once

#include "Core\Core.h"

#include "Script.h"
#include <vector>

namespace beye
{
	class BLIND_EYE_API ScriptSystem
	{
	private:
		ScriptSystem() {}
		~ScriptSystem();
	public:
		ScriptSystem(const ScriptSystem&) = delete;

		static ScriptSystem& Get()
		{
			static ScriptSystem instance;
			return instance;
		}

		void PushScript(Script* script);
		void PopScript(Script* script);

		std::vector<Script*> GetScripts() { return m_Scripts; }
	private:
		std::vector<Script*> m_Scripts;
	};
}