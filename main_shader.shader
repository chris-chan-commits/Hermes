#version 330 core
layout(location = 0) in vec3 a_Pos;
layout(location = 1) in vec2 a_TexCoord;

uniform mat4 a_Proj;
uniform mat4 a_Model;
uniform mat4 a_View;
out vec2 TexCoord;

void main()
{
	gl_Position = a_Proj * a_View * a_Model * vec4(a_Pos.x, a_Pos.y, a_Pos.z, 1.0f);
	TexCoord = a_TexCoord;
}

..SHADER

#version 330 core
out vec4 a_FragColor;
in vec2 TexCoord;

uniform sampler2D tex;

void main()
{
	a_FragColor = texture(tex, TexCoord);
}