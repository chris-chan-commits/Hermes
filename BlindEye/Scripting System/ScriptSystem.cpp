#include "ScriptSystem.h"

namespace beye 
{
	ScriptSystem::~ScriptSystem()
	{
		for (Script* script : m_Scripts)
		{
			script->OnDetach();

			delete script;
		}
	}
	void ScriptSystem::PushScript(Script* script)
	{
		script->OnAttach();

		m_Scripts.push_back(script);
	}
	void ScriptSystem::PopScript(Script* script)
	{
		script->OnDetach();

		m_Scripts.erase
		(
			std::remove
			(
				m_Scripts.begin(),
				m_Scripts.end(),
				script
			),
			m_Scripts.end()
		);
	}
}