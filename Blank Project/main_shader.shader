#version 330 core

layout(location = 0) in vec3 aPos; // the position variable has attribute position 0
uniform mat4 u_Projection;
uniform mat4 u_View;
uniform mat4 u_Model;

void main()
{
    gl_Position = u_Projection * u_View * u_Model * vec4(aPos, 1.0); // see how we directly give a vec3 to vec4's constructor
}

#Shader_SPLIT

#version 330 core

out vec4 FragColor;

void main()
{
    FragColor = vec4(0, 1, 0, 0);
}