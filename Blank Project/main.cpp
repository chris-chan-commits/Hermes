#include "../Hermes/src/Hermes.h"
#include "../Hermes/src/EntryPoint.h"
#include "../Hermes/src/Renderer/Renderer.h"

using namespace Hermes;

class MainExtension : public Extension
{
public:
	MainExtension():
		Extension("Main Extension")
	{
	}

	virtual void OnAttach() override
	{
		Renderer.Initialize(RendererApi::OpenGL);
	}

	virtual void OnTick() override
	{
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