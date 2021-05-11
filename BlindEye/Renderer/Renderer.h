#pragma once

#include "Core/Core.h"
#include "Mesh.h"
#include "Camera.h"

namespace beye
{
	enum class API
	{
		OPENGL
	};

	struct Mesh;

	class BLIND_EYE_API Renderer
	{
	public:
		static void Initialize(const API& api);
		static void BeginRender(Ref<Camera> camera);
		static void Render(const Ref<Mesh>& mesh);
		static void Resize(int width, int height);
		static void CullFace();
		static void NotCullFace();

		static API GetAPI() { return s_API; }
	private:
		static Ref<Camera> s_Camera;
		static API s_API;
	};
}