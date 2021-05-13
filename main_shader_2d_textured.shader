#version 330 core
layout(location = 0) in vec3 aPos; // the position variable has attribute position 0
layout(location = 1) in vec2 aTexCoord;
uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Proj;

out vec2 texCoord;
out vec3 fragPos;

void main()
{
    gl_Position = u_Proj * u_View * u_Model * vec4(aPos, 1.0); // see how we directly give a vec3 to vec4's constructor
	texCoord = aTexCoord;
}

.SplitShader
#version 330 core
out vec4 FragColor;
in vec2 texCoord;
uniform sampler2D tex;

void main()
{
    FragColor = texture(tex, texCoord);
}