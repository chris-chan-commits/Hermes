#pragma once

#include "vec.h"
#include "Core.h"
#include "types.h"

namespace Hermes {
	struct HERMES_API mat4
	{
		float m[4][4]; // 4 x 4

		mat4(float matrix[4][4]);
		mat4();
		mat4(float diagonal);

		mat4& mul(mat4 left, const mat4& right);
		mat4& add(mat4 left, const mat4& right);

		friend HERMES_API mat4 operator*(mat4 left, const mat4& right);
		friend HERMES_API void operator*=(mat4& left, const mat4& right);

		friend HERMES_API mat4 operator+(mat4 left, const mat4& right);
		friend HERMES_API void operator+=(mat4& left, const mat4& right);

		float* GetMatrix() const;

		static mat4 Translate(mat4& matrix, vec3 translation);

		static mat4 ortho(float left, float right, float bottom, float top, float near, float far);
	};
}