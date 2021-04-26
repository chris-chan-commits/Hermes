# Disclaimer!
Using pre releases will not be optimized, may be unstable, and also may have less features! If you want more stability, features, and optimization, wait for the full releases.

# Bolt

![image](https://user-images.githubusercontent.com/48699812/115972373-c515f400-a502-11eb-9ff9-c00e24a01746.png)

What is bolt? Bolt is a Game Engine that is currently in development, and includes a completed 2D renderer and an audio system. The audio system is currently in development, however you can still use it, and it produces, mediocore sounds.

# Attribution
Visually state/show that any application/game was made by Bolt

# Documentation
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
Then, in the Start function, you use Entity::CreateEntity. This takes in multiple parameters. Firstly, it takes the name of the object. Second, you must give a camera. So, lets create a camera. First, you want to say Camera::InitializeCameraOrthographic, or Camera::InitializeCameraPerspective. Orthographic is generally for 2D graphics, and perspective, usually is for 3D graphics. For now, we are going to use 2D graphics, so we say Camera::InitializeCameraOrthographic. And it takes in multiple parameters. It takes in, left, right, bottom, top. These are just the settings for the camera, we are going to set this to -2.0f, 2.0f, -1.5f, 1.5f. If you don't know how I got these values, I recommend you learn about projection. So, in total it will look like this:
###
	m_Camera = Camera::InitializeCameraOrthographic(-2.0f, 2.0f, -1.5f, 1.5f);
Now, lets go back to that Entity::CreateEntity function. Now that we passed in a name, and the camera, now it either takes a mesh or some vertices. Lets pass in a default mesh. Pass in CreateQuad(), and that will give the mesh to the CreateEntity function. Now we give it the shader, so lets give it the default shader by typing in MAIN_SHADER. And finally a texture. To initialize a Texture, you call the constructor with a couple parameters. Firstly, specify if its a 2D texture or a 3D texture. Type true for this value, because 3D textures are not implemented yet. And then the second parameter is the filepath for the texture. Add scene->BindCamera(camera), and finally, do scene->AddEntity(entity), and new Script(), because we will not implement a script for this entity. Tada! There is now a quad!
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
### How do I change the entities texture later on?
Thats also really simple, in either your entity script or the derived application, do entity->ChangeTexture(TheTexture). The Texture can be initialized by the same way we did before.
###
	m_Entity->ChangeTexture(new Texture("yes.bmp"));
### How do I translate an entity?
All you need to do to translate entities, is entity->translate(glm::vec3(x,y,z));
###
	m_Entity->Translate(glm::vec3(0, 1 * elapsedTime, 0);
This can also be done in the script class
### How about animations in the 2DRenderer?
Well, that is simple! All you have to do, is either in your script class or your application class, create a new Animation2D instance, give it a list of textures, and in your update function, do animation->UpdateAnimation(). And whenever you want to play an animation, do animation->Play(startingDelay, endingDelay, isLooped, delay), and when you want to stop the animation, do animation->Stop(). If the animation is not looped, then you dont need to do animation->Stop(). And if you want there to be delay before the animation starts, put true into startingDelay, and if you want the animation to delay before played again, put true into endingDelay.
###
	class PlayerMovement : public Script
###

	virtual void Start() override
	{
		m_PlayerMovementAnimation = new Animation2D
		(
			m_Entity,
			{
				{new Texture(true, "crap.png")},
				{new Texture(true, "crap2.png")}
			}
		);
	}

	virtual void Update() override
	{
		m_PlayerMovementAnimation->UpdateAnimation();
		if (m_Application->GetKeyPressed('F'))
		{
			m_PlayerMovementAnimation->Play(false, 1.0f);
		}
	}
# Classes and Functions
### Window Properties
	struct BOLT_API WindowProperties
	{
		int width, height;
		const wchar_t* title;
		bool clearColor;
		float* color;
		bool vsync;
	};
width, and height is the size of the window.

title, is the title of the window

clearColor must be true, or false, true if you want to clear a color to the screen

color must be set if clearColor is set to true

vsync must be true if you want vsync, and false if you dont

### Application::Initialize(const WindowProperties& windowProperties);
windowProperties MUST be a valid structure.

This function initializes Application
### 

