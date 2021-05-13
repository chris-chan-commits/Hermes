#version 330 core
layout(location = 0) in vec3 aPos; // the position variable has attribute position 0
uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Proj;

void main()
{
    gl_Position = u_Proj * u_View * u_Model * vec4(aPos, 1.0); // see how we directly give a vec3 to vec4's constructor
}

.SplitShader
#version 330 core
out vec4 FragColor;
uniform vec3 u_Color;

void main()
{
	FragColor = vec4(u_Color, 1.0);
}
