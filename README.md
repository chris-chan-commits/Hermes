# Bolt
Bolt Engine


My engine is too big to commit source code...


# Documentation
What is bolt? Bolt is a Game Engine that is currently in development, and includes a 2D renderer and an audio system. The audio system is currently in development, however you can still use it, and it produces, mediocore sounds.
### Usage
In order to correctly use Bolt, you must have 2 things. Firstly, you must have a class in a .cpp file, that derives from bolt::Application. Also, in the class, you must have a public virtual bolt::WindowProperties GetWindowProperties() that returns a list of window properties that you wish to be applied to the window of your game. Secondly, you must create a protected virtual void Start() and a protected virtual void Update(). And lastly, you must have a function outside of the class that returns bolt::Application*, and it must be called CreateApplication(). In this function just return a new instance of your derived class. And also be sure to define which platform you are using at the very top, (before you include Bolt.h). Platforms include, and ARE limited to, WIN32, (and nothing else because I have not finished the game engine yet).
### Example
#define WIN32
#include "../Bolt/src/Bolt.h"

using namespace bolt;

class Game : public Application
{
private:
	Scene* m_Scene;
public:
	virtual WindowProperties GetWindowProperties() override
	{
		WindowProperties props = {  };
		props.width = 1280;
		props.height = 720;
		props.title = L"Demo";
		props.clearColor = false;

		return props;
	}

protected:
	virtual void Start() override
	{
		m_Scene = new Scene(this);
		LoadScene(m_Scene);
	}

	virtual void Update() override
	{

	}
};

Application* CreateApplication()
{
	return new Game();
}
