#include "Mesh.h"

#include "OpenGL\OpenGLVertexArray.h"
#include "OpenGL\OpenGLVertexBuffer.h"
#include <istream>
#include <sstream>
#include <fstream>

namespace beye
{
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

	static void readObj(const std::string& filename, std::vector<float>& vertices, std::vector<float>& texCoords, std::vector<float>& normals, std::vector<uint32_t>& indices)
	{
		std::ifstream file(filename, std::ios::in);
		if (!file)
		{
			BE_CORE_ERROR("Cannot open obj file! Reason: File does not exist!");
			BE_CORE_PAUSE();
			std::exit(-1);
		}

		std::vector<float> tempTexCoords;

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
				s >> vt.z;
				tempTexCoords.push_back(vt.x);
				tempTexCoords.push_back(vt.y);
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
				texCoords.push_back(tempTexCoords[h]);

				indices.push_back(a);
				indices.push_back(d);
				indices.push_back(g);
			}
		}
	}

	Ref<Mesh> Mesh::CreateMesh(const std::string& objFilename, Ref<Shader> shader, std::vector<float>& texCoords)
	{
		std::vector<float> vertices;
		std::vector<float> normals;
		std::vector<uint32_t> indices;
		readObj(objFilename, vertices, texCoords, normals, indices);


		Ref<Mesh> mesh = CreateRef<Mesh>();
		mesh->shader = shader;
		mesh->model = glm::mat4(1.0f);
		float* data = (float*)vertices.data();
		size_t size = vertices.size() * sizeof(size_t);

		uint32_t* ind = (uint32_t*)indices.data();
		size_t indsiz = indices.size() * sizeof(size_t);

		Ref<VertexArray> vArray = VertexArray::CreateVertexArray();
		Ref<VertexBuffer> vBuf = VertexBuffer::CreateVertexBuffer(data, size);
		Ref<IndexBuffer> iBuf = IndexBuffer::CreateIndexBuffer(ind, indsiz);

		// Initialize Layout
		BufferLayout layout = {};
		layout.index = 0;
		layout.size = 3;
		vBuf->SetLayout(layout);


		vArray->AddVertexBuffer(vBuf);

		vArray->BindIndexBuffer(iBuf);

		mesh->vao = vArray;
		mesh->points = vertices.size() / 3;

		return mesh;
	}
	Ref<Mesh> Mesh::CreateMesh(const std::vector<float> vertices, Ref<Shader> shader)
	{
		Ref<Mesh> mesh = CreateRef<Mesh>();
		mesh->shader = shader;
		mesh->model = glm::mat4(1.0f);
		float* data = (float*)vertices.data();
		size_t size = vertices.size() * sizeof(size_t);

		Ref<VertexArray> vArray = VertexArray::CreateVertexArray();
		Ref<VertexBuffer> vBuf = VertexBuffer::CreateVertexBuffer(data, size);

		// Initialize Layout
		BufferLayout layout = {};
		layout.index = 0;
		layout.size = 3;
		vBuf->SetLayout(layout);


		vArray->AddVertexBuffer(vBuf);

		mesh->vao = vArray;
		mesh->points = vertices.size() / 3;

		return mesh;

	}
	Ref<Mesh> Mesh::CreateMesh(const std::vector<float> vertices, const std::vector<uint32_t> indices, Ref<Shader> shader)
	{
		Ref<Mesh> mesh = CreateRef<Mesh>();
		mesh->shader = shader;
		mesh->model = glm::mat4(1.0f);
		float* data = (float*)vertices.data();
		size_t size = vertices.size() * sizeof(size_t);

		uint32_t* ind = (uint32_t*)indices.data();
		size_t indsiz = indices.size() * sizeof(size_t);

		Ref<VertexArray> vArray = VertexArray::CreateVertexArray();
		Ref<VertexBuffer> vBuf = VertexBuffer::CreateVertexBuffer(data, size);
		Ref<IndexBuffer> iBuf = IndexBuffer::CreateIndexBuffer(ind, indsiz);

		// Initialize Layout
		BufferLayout layout = {};
		layout.index = 0;
		layout.size = 3;
		vBuf->SetLayout(layout);


		vArray->AddVertexBuffer(vBuf);

		vArray->BindIndexBuffer(iBuf);

		mesh->vao = vArray;
		mesh->points = vertices.size() / 3;

		return mesh;
	}
	void Mesh::BindTextureCoordinates(const std::vector<float> texCoords)
	{
		switch (Renderer::GetAPI())
		{
		case API::OPENGL:
			{
				float* data = (float*)texCoords.data();
				size_t size = texCoords.size() * sizeof(size_t);
				Ref<VertexBuffer> tBuf = VertexBuffer::CreateVertexBuffer(data, size);

				BufferLayout layout = {};
				layout.index = 1;
				layout.size = 2;
				tBuf->SetLayout(layout);

				vao->AddVertexBuffer(tBuf);
			}break;
		default:
			{
				BE_CORE_ERROR("Failed to bind texture coordinates! Reason: Only OpenGL is supported!");
				BE_CORE_PAUSE();
				std::exit(-1);
				return;
			}break;
		}
	}
	void Mesh::BindTexture(Ref<Texture> texture, const std::vector<float> texCoords)
	{
		this->texture = texture;
		usesTexture = true;

		switch (Renderer::GetAPI())
		{
		case API::OPENGL:
			{
				float* data = (float*)texCoords.data();
				size_t size = texCoords.size() * sizeof(size_t);
				Ref<VertexBuffer> tBuf = VertexBuffer::CreateVertexBuffer(data, size);

				BufferLayout layout = {};
				layout.index = 1;
				layout.size = 2;
				tBuf->SetLayout(layout);

				vao->AddVertexBuffer(tBuf);
			}break;
		default:
			{
				BE_CORE_ERROR("Failed to bind texture! Reason: Only OpenGL is supported!");
				BE_CORE_PAUSE();
				std::exit(-1);
				return;
			}break;
		}
	}
	void Mesh::BindTexture(Ref<Texture> texture)
	{
		this->usesTexture = true;
		this->texture = texture;
	}
}