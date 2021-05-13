#include "Mesh.h"

#include "OpenGL\OpenGLVertexArray.h"
#include "OpenGL\OpenGLVertexBuffer.h"
#include <istream>
#include <sstream>
#include <fstream>

namespace beye
{
	static int mesh_id = 0;

	static char* removeWhiteSpaces(char* str)
	{
		int i = 0, j = 0;
		while (str[i])
		{
			if (str[i] != ' ')
				str[j++] = str[i];
			i++;
		}
		str[j] = '\0';
		return str;
	}

	static void strReplace(char* target, const char* needle, const char* replacement)
	{
		char buffer[1024] = { 0 };
		char* insert_point = &buffer[0];
		const char* tmp = target;
		size_t needle_len = strlen(needle);
		size_t repl_len = strlen(replacement);

		while (1) {
			const char* p = strstr(tmp, needle);

			// walked past last occurrence of needle; copy remaining part
			if (p == NULL) {
				strcpy(insert_point, tmp);
				break;
			}

			// copy part before needle
			memcpy(insert_point, tmp, p - tmp);
			insert_point += p - tmp;

			// copy replacement string
			memcpy(insert_point, replacement, repl_len);
			insert_point += repl_len;

			// adjust pointers, move on
			tmp = p + needle_len;
		}

		// write altered string back to target
		strcpy(target, buffer);
	}

	static void readObj(const std::string& filename, std::vector<float>& vertices, std::vector<float>&texCoords, std::vector<float>& normals, std::vector<uint32_t>& indices)
	{
		std::ifstream file(filename, std::ios::in);
		if (!file)
		{
			BE_CORE_ERROR("Cannot open obj file! Reason: File does not exist!");
			BE_CORE_PAUSE();
			std::exit(-1);
		}

		std::vector<float> tempTexCoords;
		std::vector<float> tempNormals;

		std::string line;
		while (std::getline(file, line))
		{
			if (line.substr(0, 2) == "v ")
			{
				std::istringstream s(line.substr(2));
				glm::vec3 v;
				s >> v.x;
				s >> v.y;
				s >> v.z;
				vertices.push_back(v.x);
				vertices.push_back(v.y);
				vertices.push_back(v.z);
			}
			else if (line.substr(0, 3) == "vt ")
			{
				std::istringstream s(line.substr(3));
				glm::vec3 vt;
				s >> vt.x;
				s >> vt.y;
				//s >> vt.z;
				tempTexCoords.push_back(vt.x);
				tempTexCoords.push_back(vt.y);
				//tempTexCoords.push_back(vt.z);
			}
			else if (line.substr(0, 3) == "vn ")
			{
				std::istringstream s(line.substr(3));
				glm::vec3 vn;
				s >> vn.x;
				s >> vn.y;
				s >> vn.z;

				tempNormals.push_back(vn.x);
				tempNormals.push_back(vn.y);
				tempNormals.push_back(vn.z);
			}
			else if (line.substr(0, 2) == "f ")
			{
				uint32_t a, b, c, d, e, f, g, h, i;
				char* stuff = (char*)line.c_str();
				strReplace(stuff, "/", " ");
				strReplace(stuff, "f ", "");

				std::string crap = stuff;

				std::istringstream s(crap);

				s >> a;
				s >> b;
				s >> c;
				s >> d;
				s >> e;
				s >> f;
				s >> g;
				s >> h;
				s >> i;

				a--;
				b--;
				c--;
				
				d--;
				e--;
				f--;
				
				g--;
				h--;
				i--;

				texCoords.push_back(tempTexCoords[b]);
				texCoords.push_back(tempTexCoords[e]);
				//texCoords.push_back(tempTexCoords[h]);

				normals.push_back(tempNormals[c]);
				normals.push_back(tempNormals[f]);
				normals.push_back(tempNormals[i]);

				indices.push_back(a);
				indices.push_back(d);
				indices.push_back(g);
			}
		}
	}

	Ref<Mesh> Mesh::Create2DMesh(const SPRITE& sprite, const Mat2D& mat)
	{
		mesh_id++;
		Ref<Mesh> mesh = CreateRef<Mesh>();
		float vertices[4 * 3] =
		{
	 0.5f,  0.5f, 0.0f,  // top right
	 0.5f, -0.5f, 0.0f,  // bottom right
	-0.5f, -0.5f, 0.0f,  // bottom left
	-0.5f,  0.5f, 0.0f   // top left
		};

		uint32_t indices[6] =
		{
	0, 1, 3,   // first triangle
	1, 2, 3    // second triangle
		};

		float textureCoordinates[4 * 2] =
		{
			-1.f, -1.f,
			-1.f, 1.f,
			1.f, 1.f,
			1.f, -1.f,
		};

		Ref<VertexArray> vao = VertexArray::CreateVertexArray();
		Ref<VertexBuffer> vbo = VertexBuffer::CreateVertexBuffer(vertices, 12 * sizeof(size_t));
		Ref<IndexBuffer> ibo = IndexBuffer::CreateIndexBuffer(indices, 6 * sizeof(size_t));

		BufferLayout layout = {};
		layout.index = 0;
		layout.size = 3;
		vbo->SetLayout(layout);

		vao->AddVertexBuffer(vbo);
		vao->BindIndexBuffer(ibo);

		

		if (!mat.textureAlbedo) 
		{
			mesh->shader = Shader::CreateShader("main_shader_2d.shader");
			mesh->shader->SetFloat3(mat.albedoColor.name, mat.albedoColor.value);
			mesh->usesTextures = false;
		}
		else
		{
			mesh->shader = Shader::CreateShader("main_shader_2d_textured.shader");
			Ref<VertexBuffer> uvBuffer = VertexBuffer::CreateVertexBuffer(textureCoordinates, (sizeof(textureCoordinates) / sizeof(&textureCoordinates[0])) * sizeof(size_t));
			layout = {};
			layout.index = 1;
			layout.size = 2;
			uvBuffer->SetLayout(layout);
			vao->AddVertexBuffer(uvBuffer);
			
			mesh->texture = mat.textureAlbedo;
			mesh->usesTextures = true;
		}
		
		mesh->vao = vao;
		mesh->transformation = glm::mat4(1.0f);
		mesh->meshID = mesh_id;

		return mesh;
	}

	Ref<Mesh> Mesh::Create3DMesh()
	{
		mesh_id++;

		return nullptr;
	}

	void Mesh::BindMaterial(const Mat2D& mat)
	{
		shader->SetFloat3(mat.albedoColor.name, mat.albedoColor.value);
	}

	/*MESH*/
	void Mesh::Render()
	{
		glm::mat4 proj = Camera::GetActive()->projection;
		glm::mat4 view = Camera::GetActive()->view;

		shader->SetMat4("u_Proj", Camera::GetActive()->projection);
		shader->SetMat4("u_View", Camera::GetActive()->view);
		shader->SetMat4("u_Model", transformation);

		if (usesTextures)
		{
			texture->Bind();
		}
		shader->Bind();
		Renderer::BeginRender();
		Renderer::Render(vao);
		if (usesTextures)
		{
			texture->Unbind();
		}
		shader->Unbind();
	}
}