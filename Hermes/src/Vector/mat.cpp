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
	HERMES_API mat4 operator*(mat4 left, const mat4& right)
	{
		mat4 result = left.mul(left, right);
		return result;
	}
	void operator*=(mat4& left, const mat4& right)
	{
		left = left.mul(left, right);
	}
}