#version 330 core

location(layout = 0) in vec3 aPos;

void main()
{
	gl_Position = vec4(aPos, 1.0);
}

#Shader_SPLIT
#version 330 core

out vec4 FragColor;

void main()
{
	FragColor = vec4(1, 0, 1, 0);
}