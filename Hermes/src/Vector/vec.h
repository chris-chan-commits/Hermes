#pragma once
#include <ostream>


#include "Core.h"
namespace Hermes {
	struct HERMES_API vec2
	{
		vec2(float x, float y) :
			x(x), y(y)
		{

		}

		vec2()
		{
			x = y = 0;
		}

		float x, y;

		vec2& add(vec2 left, const vec2& right);
		vec2& sub(vec2 left, const vec2& right);
		vec2& mul(vec2 left, const vec2& right);
		vec2& div(vec2 left, const vec2& right);

		friend HERMES_API std::ostream& operator<<(std::ostream& os, const vec2& vector);

		friend HERMES_API vec2& operator+(vec2 left, const vec2& right) { return left.add(left, right); }
		friend HERMES_API void operator+=(vec2& left, const vec2& right) { left = left.add(left, right); }

		friend HERMES_API vec2& operator-(vec2 left, const vec2& right) { return left.sub(left, right); }
		friend HERMES_API void operator-=(vec2& left, const vec2& right) { left = left.sub(left, right); }

		friend HERMES_API vec2& operator*(vec2 left, const vec2& right) { return left.mul(left, right); }
		friend HERMES_API void operator*=(vec2& left, const vec2& right) { left = left.mul(left, right); }

		friend HERMES_API vec2& operator/(vec2 left, const vec2& right) { return left.div(left, right); }
		friend HERMES_API void operator/=(vec2& left, const vec2& right) { left = left.div(left, right); }
	};

	struct HERMES_API vec3
	{
		vec3(float x, float y, float z) :
			x(x), y(y), z(z)
		{

		}

		vec3()
		{
			x = y = z = 0;
		}



		float x, y, z;

		vec3& add(vec3 left, const vec3& right);
		vec3& sub(vec3 left, const vec3& right);
		vec3& mul(vec3 left, const vec3& right);
		vec3& div(vec3 left, const vec3& right);

		friend HERMES_API std::ostream& operator<<(std::ostream& os, const vec3& vector);


		friend HERMES_API vec3& operator+(vec3 left, const vec3& right) { return left.add(left, right); }
		friend HERMES_API void operator+=(vec3& left, const vec3& right) { left = left.add(left, right); }

		friend HERMES_API vec3& operator-(vec3 left, const vec3& right) { return left.sub(left, right); }
		friend HERMES_API void operator-=(vec3& left, const vec3& right) { left = left.sub(left, right); }

		friend HERMES_API vec3& operator*(vec3 left, const vec3& right) { return left.mul(left, right); }
		friend HERMES_API void operator*=(vec3& left, const vec3& right) { left = left.mul(left, right); }

		friend HERMES_API vec3& operator/(vec3 left, const vec3& right) { return left.div(left, right); }
		friend HERMES_API void operator/=(vec3& left, const vec3& right) { left = left.div(left, right); }
	};

	struct vec4
	{
		vec4(float x, float y, float z, float w):
			x(x), y(y), z(z), w(w)
		{

		}
		
		vec4()
		{
			x = y = z = w = 0;
		}

		float x, y, z, w;
	
		vec4& add(vec4 left, const vec4& right);
		vec4& sub(vec4 left, const vec4& right);
		vec4& mul(vec4 left, const vec4& right);
		vec4& div(vec4 left, const vec4& right);

		friend HERMES_API vec4& operator+(vec4 left, const vec4& right) { return left.add(left, right); }
		friend HERMES_API void operator+=(vec4& left, const vec4& right) { left = left.add(left, right); }
											 
		friend HERMES_API vec4& operator-(vec4 left, const vec4& right) { return left.sub(left, right); }
		friend HERMES_API void operator-=(vec4& left, const vec4& right) { left = left.sub(left, right); }
											 
		friend HERMES_API vec4& operator*(vec4 left, const vec4& right) { return left.mul(left, right); }
		friend HERMES_API void operator*=(vec4& left, const vec4& right) { left = left.mul(left, right); }
											 
		friend HERMES_API vec4& operator/(vec4 left, const vec4& right) { return left.div(left, right); }
		friend HERMES_API void operator/=(vec4& left, const vec4& right) { left = left.div(left, right); }
	};
}