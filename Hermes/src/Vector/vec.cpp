#include "vec.h"

namespace Hermes {
	HERMES_API std::ostream& operator<<(std::ostream& os, const vec2& vector)
	{
		os << "(" << vector.x << ", " << vector.y << ")";
		return os;
	}
	HERMES_API std::ostream& operator<<(std::ostream& os, const vec3& vector)
	{
		os << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
		return os;
	}
	vec2& vec2::add(vec2 left, const vec2& right)
	{
		left.x += right.x;
		left.y += right.y;

		return left;
	}
	vec2& vec2::sub(vec2 left, const vec2& right)
	{
		left.x -= right.x;
		left.y -= right.y;

		return left;
	}
	vec2& vec2::mul(vec2 left, const vec2& right)
	{
		left.x *= right.x;
		left.y *= right.y;

		return left;
	}
	vec2& vec2::div(vec2 left, const vec2& right)
	{
		left.x /= right.x;
		left.y /= right.y;

		return left;
	}
	vec3& vec3::add(vec3 left, const vec3& right)
	{
		left.x += right.x;
		left.y += right.y;
		left.z += right.z;
		return left;
	}
	vec3& vec3::sub(vec3 left, const vec3& right)
	{
		left.x -= right.x;
		left.y -= right.y;
		left.z -= right.z;
		return left;
	}
	vec3& vec3::mul(vec3 left, const vec3& right)
	{
		left.x *= right.x;
		left.y *= right.y;
		left.z *= right.z;
		return left;
	}
	vec3& vec3::div(vec3 left, const vec3& right)
	{
		left.x /= right.x;
		left.y /= right.y;
		left.z /= right.z;
		return left;
	}
	vec4& vec4::add(vec4 left, const vec4& right)
	{
		left.x += right.x;
		left.y += right.y;
		left.z += right.z;
		left.w += right.w;

		return left;
	}
	vec4& vec4::sub(vec4 left, const vec4& right)
	{
		left.x -= right.x;
		left.y -= right.y;
		left.z -= right.z;
		left.w -= right.w;

		return left;
	}
	vec4& vec4::mul(vec4 left, const vec4& right)
	{
		left.x *= right.x;
		left.y *= right.y;
		left.z *= right.z;
		left.w *= right.w;

		return left;
	}
	vec4& vec4::div(vec4 left, const vec4& right)
	{
		left.x /= right.x;
		left.y /= right.y;
		left.z /= right.z;
		left.w /= right.w;

		return left;
	}
}