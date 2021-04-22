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
### How do I create a mesh?
Well, its pretty simple actually. First, you declare a new entity.
###
	class Game : public Application
	{
	private:
		Scene* m_Scene;
		Entity* m_Entity;
Then, in the Start function, you use Entity::CreateEntity. This takes in multiple parameters. Firstly, it takes the name of the object. Second, you must give a camera. So, lets create a camera. First, you want to say Camera::InitializeCameraOrthographic, or Camera::InitializeCameraPerspective. Orthographic is generally for 2D graphics, and perspective, usually is for 3D graphics. For now, we are going to use 2D graphics, so we say Camera::InitializeCameraOrthographic. And it takes in multiple parameters. It takes in, left, right, bottom, top. These are just the settings for the camera, we are going to set this to -1.5f, 1.5f, -2.0f, 2.0f. If you don't know how I got these values, I recommend you learn about projection. So, in total it will look like this:
###
	m_Camera = Camera::InitializeCameraOrthographic(-1.5f, 1.5f, -2.0f, 2.0f);
Now, lets go back to that Entity::CreateEntity function. Now that we passed in a name, and the camera, now it either takes a mesh or some vertices. Lets pass in a default mesh. Pass in CreateQuad(), and that will give the mesh to the CreateEntity function. Now we give it the shader, so lets give it the default shader by typing in MAIN_SHADER. And finally a texture. To initialize a Texture, you call the constructor with a couple parameters. Firstly, specify if its a 2D texture or a 3D texture. Type true for this value, because 3D textures are not implemented yet. And then the second parameter is the filepath for the texture. And finally, do scene->AddEntity(entity), and new Script(), because we will not implement a script for this entity. Tada! There is now a quad!
### How do I add a script to an entity?
Pretty simple, actually. Firstly, you will want to create a class that inherits from Script. Then you want to override virtual functions, Start and Update. And then, in the place where you did scene->AddEntity, you actually want to pass a new instance of your script. and there you go, you have a scripted entity.
### The class
	class Mover : public Script
	{
	public:
		virtual void Start() override
		{
	
		}

		virtual void Update() override
		{
			m_Entity->Translate(glm::vec3(1, 0, 0) * elapsedTime);
		}
	};
### Adding the script
	m_Scene->AddEntity(Entity::CreateEntity("entity", m_Camera, CreateQuad(), MAIN_SHADER, new Texture(true, "dvdlogo.png")), new Mover());
