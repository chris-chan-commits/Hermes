# Disclaimer!
Using pre releases will not be optimized, may be unstable, and also may have less features! If you want more stability, features, and optimization, wait for the full releases.
Also, documentation may not be up to date with the pre-releases! If you have any questions, email chrischancommits@gmail.com.

# Blind Eye(a.k.a Bolt)

![image](https://user-images.githubusercontent.com/48699812/115972373-c515f400-a502-11eb-9ff9-c00e24a01746.png)

What is Blind Eye? Blind Eye is an open source Game Engine that is currently in development, and includes a completed 2D renderer and an audio system. The audio system is currently in development, however you can still use it, and it produces, mediocore sounds.

# Attribution
Visually state/show that any application/game was made by Blind Eye

# Documentation
### Usage
First, you must create a "CreateApplication" function that returns your application, and then you must create a derived Application, and then a layer, to then push into the application. For example:
#
        class Test : public Application
        {
        public:
	        Test()
	        {
		        AttachLayer(new ApplicationLayer());
	        }
        };

    Application* CreateApplication()
    {
	    return new Test();
    }
And the layer will look like this:
#
    class ApplicationLayer : public Layer
    {
    ApplicationLayer():
		    Layer("Application Layer")
	    {
	    }
      virtual void OnAttach() override
	    {
      }
     virtual void OnDetach() override
	    {
	    }
      virtual void OnUpdate() override
	    {
      }
    } 
### How do I initialize the renderer?
    Renderer::Initialize(API);
The api can be only OpenGL because I have not made any other renderers.
This is recommended to be called in OnAttach()
### How do I create a mesh?
You need to create a camera, and then initialize the mesh and then if you want, bind a texture
#
    m_Camera = Camera::CreateOrthographicCamera(-1, 1, -1, 1);

		m_Mesh = DefaultQuad();
		m_Mesh->BindTexture(Texture::CreateTexture("brik.png"));
And to render it, call Renderer::BeginRender(camera); and then Renderer::Render(mesh);
### How do I customize the width, height, and title?
Create an engine.ini file, that contains the width, height, and title in this format...
#
	WIDTH:1280
	HEIGHT:720
	TITLE:MY TEST



# Credits
GLFW, GLEW, GLM
