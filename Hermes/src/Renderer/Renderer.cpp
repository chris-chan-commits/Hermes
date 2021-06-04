#include "Renderer.h"

namespace Hermes {
	RendererApi Renderer::s_Api;

	VOID Renderer::Initialize(const RendererApi& api)
	{
		s_Api = api;
		// Do other initializing bullcrap
		switch (s_Api)
		{
		case RendererApi::OpenGL:
			{

			}break;
		}
	}
}