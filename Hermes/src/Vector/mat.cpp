#include "mat.h"

namespace Hermes {
	mat4::mat4(float matrix[4][4])
	{
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				m[y][x] = matrix[y][x];
			}
		}
	}
	mat4::mat4()
	{
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				m[y][x] = 0.0f;
			}
		}
	}

	mat4::mat4(float diagonal)
	{
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				m[y][x] = 0.0f;
			}
		}

		m[0][0] = diagonal;
		m[1][1] = diagonal;
		m[2][2] = diagonal;
		m[3][3] = diagonal;
	}
	mat4& mat4::mul(mat4 left, const mat4& right)
	{
		mat4 result;
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				result.m[y][x] = 0;
				for (int z = 0; z < 4; z++)
				{
					result.m[y][x] += left.m[y][z] * right.m[z][x];
				}
			}
		}

		return result;
	}

	mat4& mat4::add(mat4 left, const mat4& right)
	{
		mat4 result;
		for(int y = 0; y < 4; y++)
		{
			for(int x = 0; x < 4; x++)
			{
				result.m[x][y] = left.m[x][y] + right.m[x][y];
			}
		}

		return result;
	}

	float* mat4::GetMatrix() const
	{
		float* b = new float[16];

		for (int q = 0; q < 4; q++)
		{
			for (int t = 0; t < 4; t++)
			{
				b[q * 4 + t] = m[q][t];
			}
		}

		return b;
	}

	mat4 mat4::Translate(const mat4& matrix, const vec3& translation)
	{
		mat4 result(matrix);
		result.m[3][0] += translation.x;
		result.m[3][1] += translation.y;
		result.m[3][2] += translation.z;

		return result;
	}

	mat4 mat4::Rotate(const mat4& matrix, const vec3& rotation)
	{
		mat4 result(matrix);

		mat4 xRot = mat4(
			new float[4][4]
			{
				{1, 0, 0, 0},
				{0, cos(rotation.x), -sin(rotation.x), 0},
				{0, sin(rotation.x), cos(rotation.x), 0},
				{0, 0, 0, 1}
			}
		);
		mat4 yRot = mat4(
			new float[4][4]
			{
				{cos(rotation.y), 0, sin(rotation.y), 0},
				{0, 1, 0, 0},
				{-sin(rotation.y), 0, cos(rotation.y), 0},
				{0, 0, 0, 1}
			}
		);
		mat4 zRot = mat4(
			new float[4][4]
			{
				{cos(rotation.z), -sin(rotation.z), 0, 0},
				{sin(rotation.z), cos(rotation.z), 0, 0},
				{0, 0, 1, 0},
				{0, 0, 0, 1}
			}
		);

		mat4 rot(1.0f);

		rot *= zRot;
		rot *= yRot;
		rot *= xRot;

		result *= rot;
		
		return result;
	}

	mat4 mat4::Orthographic(float left, float right, float bottom, float top, float near, float far)
	{
		float matrix[4][4] =
		{
			{
				2 / (right - left), 0, 0, -((right + left) / (right - left))
			},
			{
				0, 2 / (top - bottom), 0, -((top + bottom) / (top - bottom))
			},
			{
				0, 0, -2 / (far - near), -((far + near) / (far - near))
			},
			{
				0, 0, 0, 1
			}
		};

		mat4 mat(matrix);

		return mat;
	}

	HERMES_API mat4 operator*(mat4 left, const mat4& right)
	{
		mat4 result = left.mul(left, right);
		return result;
	}
	void operator*=(mat4& left, const mat4& right)
	{
		left = left.mul(left, right);
	}

	mat4 operator+(mat4 left, const mat4& right)
	{
		return left.add(left, right);
	}

	void operator+=(mat4& left, const mat4& right)
	{
		left = left.add(left, right);
	}
}
