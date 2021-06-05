#include "../Hermes/src/Hermes.h"
#include "../Hermes/src/EntryPoint.h"
#include "../Hermes/src/Renderer/Renderer.h"
#include "../Hermes/src/Platform/RenderPlatform/OpenGL/OGLVertexArray.h"
#include "../Hermes/src/Platform/RenderPlatform/OpenGL/OGLShader.h"

using namespace Hermes;

class MainExtension : public Extension
{
private:
	Ref<VertexArray> array;
	Ref<VertexBuffer> buffer;
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
		float* vertices = new float[3 * 3]{
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
		};

		array = VertexArray::CreateVertexArray();
		array->Initialize();
		
		buffer = VertexBuffer::CreateVertexBuffer();
		buffer->Initialize({ 0, 3 }, vertices, sizeof(float) * 9);

		
		array->AddVertexBuffer(buffer);

		shader = Shader::CreateShader();
		shader->Initialize("main_shader.shader");
		proj = mat4::ortho(-1, 1, -1, 1, 0.001, 1000);
		model = mat4(1.0f);
		view = mat4(1.0f);
	}

	virtual void OnTick() override
	{
		shader->Bind();
		shader->SetMat4("u_Projection", proj);
		shader->SetMat4("u_Model", model);
		shader->SetMat4("u_View", view);
		model = mat4::Rotate(model, vec3(0, 0, 0.01f));
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