#include "../Hermes/src/Hermes.h"
#include "../Hermes/src/EntryPoint.h"
#include "../Hermes/src/Renderer/Renderer.h"
#include "../Hermes/src/Platform/RenderPlatform/OpenGL/OGLVertexArray.h"
#include "../Hermes/src/Platform/RenderPlatform/OpenGL/OGLShader.h"

#include <Windows.h>

using namespace Hermes;

class MainExtension : public Extension
{
private:
	Ref<VertexArray> array;
	Ref<VertexBuffer> buffer;
	Ref<IndexBuffer> ibo;
	Ref<Shader> shader;
	mat4 proj;
	mat4 view;
	mat4 model;
public:
	MainExtension():
		Extension("Main Extension")
	{
	}

	virtual void OnAttach() override
	{
		std::vector<float> vertices ={
	 0.5f,  0.5f, 0.0f,  // top right
	 0.5f, -0.5f, 0.0f,  // bottom right
	-0.5f, -0.5f, 0.0f,  // bottom left
	-0.5f,  0.5f, 0.0f   // top left 
		};

		std::vector<uint32_t> indices = {
			0, 1, 3,
			1, 2, 3
		};

		array = VertexArray::CreateVertexArray();
		array->Initialize();
		
		buffer = VertexBuffer::CreateVertexBuffer();
		buffer->Initialize({ 0, 3 }, vertices.data(), sizeof(float) * 12*3*3);

		ibo = IndexBuffer::CreateIndexBuffer();
		ibo->Initialize(indices.data(), sizeof(uint32_t) * 6);
		
		array->AddVertexBuffer(buffer);
		array->BindIndexBuffer(ibo);

		shader = Shader::CreateShader();
		shader->Initialize("main_shader.shader");
		proj = mat4::Orthographic(-1.0f, 1.0f, -1.0f, 1.0f, 0.01f, 1000.0f);
		model = mat4(1.0f);
		view = mat4(1.0f);
	}

	virtual void OnTick() override
	{
		shader->Bind();
		shader->SetMat4("u_Projection", proj);
		shader->SetMat4("u_View", view);
		shader->SetMat4("u_Model", model);

		view = mat4::Rotate(view, vec3(0, 0, 0.01f));
		
		LowLevelRenderer::Get().RenderVertexArray(array);
		shader->Unbind();
	}

	virtual void OnDetach() override
	{
	}
};

class MyGame : public Application
{
public:
	MyGame()
	{
		PushExtension(new MainExtension());
	}

	~MyGame()
	{
	}
};

Application* CreateApplication()
{
	return new MyGame();
}