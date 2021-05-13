#pragma once

#include "Core/Core.h"
#include "Mesh.h"
#include "Camera.h"
#include "Light.h"

namespace beye
{
	enum class API
	{
		OPENGL
	};

	struct Mesh;
	struct Light;

	class BLIND_EYE_API Renderer
	{
	public:
		static void Initialize(const API& api);
		static void BeginRender();
		static void Render(const Ref<VertexArray>& array);
		static void Resize(int width, int height);
		static void CullFace();
		static void NotCullFace();
		static void EnableWireframe();
		static void DisableWireframe();

		static API GetAPI() { return s_API; }
	private:
		static Ref<Camera> s_Camera;
		static API s_API;
	};
}