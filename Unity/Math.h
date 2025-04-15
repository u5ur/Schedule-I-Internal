#pragma once
#include <math.h>
#include <cmath>

struct Vector2
{
	float x, y;

	inline Vector2 operator*(float scalar) const { return { x * scalar, y * scalar }; }
	inline Vector2 operator+(const Vector2& other) const { return { x + other.x, y + other.y }; }
	inline Vector2 operator-(const Vector2& other) const { return { x - other.x, y - other.y }; }
	inline Vector2 operator*(const Vector2& other) const { return { x * other.x, y * other.y }; }
	inline Vector2 operator/(const Vector2& other) const { return { x / other.x, y / other.y }; }
	inline Vector2 operator-() const { return { -x, -y }; }

	inline Vector2 normalized() const
	{
		float len = sqrtf(x * x + y * y);
		return { x / len, y / len };
	}

	inline float Length() {
		return std::sqrt(x * x + y * y);
	}

	inline Vector2 Normalize() {
		return Vector2(this->x / Length(), this->y / Length());
	}

	inline bool Empty() {
		return x == 0 && y == 0;
	}

	inline bool Zero() const {
		return (x > -0.1f && x < 0.1f && y > -0.1f && y < 0.1f);
	}
};

struct Vector3
{
	float x, y, z;

	inline Vector3 operator*(float scalar) const { return { x * scalar, y * scalar, z * scalar }; }
	inline Vector3 operator+(const Vector3& other) const { return { x + other.x, y + other.y, z + other.z }; }
	inline Vector3 operator-(const Vector3& other) const { return { x - other.x, y - other.y, z - other.z }; }
	inline Vector3 operator*(const Vector3& other) const { return { x * other.x, y * other.y, z * other.z }; }
	inline Vector3 operator/(const Vector3& other) const { return { x / other.x, y / other.y, z / other.z }; }
	inline Vector3 operator-() const { return { -x, -y, -z }; }

	inline Vector3 normalized() const
	{
		float len = sqrtf(x * x + y * y + z * z);
		return { x / len, y / len, z / len };
	}

	inline float Magnitude()
	{
		return std::sqrt((x * x) + (y * y) + (z * z));
	}

	inline Vector3 Normalize()
	{
		Vector3 out = *this;
		auto l = Magnitude();
		if (l == 0)
			return *this;
		;
		out.x /= l;
		out.y /= l;
		out.z /= l;
		return out;
	}

	inline float Dot(const Vector3& Vec2) 
	{
		return this->x * Vec2.x + this->y * Vec2.y + this->z * Vec2.z;
	}

	static inline Vector3 Zero() 
	{
		return Vector3(0.0f, 0.0f, 0.0f);
	}

	inline bool Empty() 
	{ 
		return x == 0 && y == 0 && z == 0; 
	}

	inline float Distance(const Vector3& vector)
	{
		return std::sqrt(
			(x - vector.x) * (x - vector.x) +
			(y - vector.y) * (y - vector.y) +
			(z - vector.z) * (z - vector.z));
	}
};

struct Vector4
{
	float x, y, z, w;

	inline Vector4 operator*(float scalar) const { return { x * scalar, y * scalar, z * scalar, w * scalar }; }
	inline Vector4 operator+(const Vector4& other) const { return { x + other.x, y + other.y, z + other.z, w + other.w }; }
	inline Vector4 operator-(const Vector4& other) const { return { x - other.x, y - other.y, z - other.z, w - other.w }; }
	inline Vector4 operator/(const Vector4& other) const { return { x / other.x, y / other.y, z / other.z, w / other.w }; }
	inline Vector4 operator-() const { return { -x, -y, -z, -w }; }

	inline Vector4 operator*(const Vector4& other) const
	{
		return {
			w * other.x + x * other.w + y * other.z - z * other.y,
			w * other.y + y * other.w + z * other.x - x * other.z,
			w * other.z + z * other.w + x * other.y - y * other.x,
			w * other.w - x * other.x - y * other.y - z * other.z
		};
	}

	inline Vector3 operator*(const Vector3& vec) const
	{
		float _x = x * 2.0f;
		float _y = y * 2.0f;
		float _z = z * 2.0f;
		float xx = x * _x;
		float yy = y * _y;
		float zz = z * _z;
		float xy = x * _y;
		float xz = x * _z;
		float yz = y * _z;
		float wx = w * _x;
		float wy = w * _y;
		float wz = w * _z;

		Vector3 result;
		result.x = (1.0f - (yy + zz)) * vec.x + (xy - wz) * vec.y + (xz + wy) * vec.z;
		result.y = (xy + wz) * vec.x + (1.0f - (xx + zz)) * vec.y + (yz - wx) * vec.z;
		result.z = (xz - wy) * vec.x + (yz + wx) * vec.y + (1.0f - (xx + yy)) * vec.z;

		return result;
	}

	inline Vector4 conjugate() const { return { -x, -y, -z, w }; }
};

struct Matrix4x4
{
	float _11, _12, _13, _14;
	float _21, _22, _23, _24;
	float _31, _32, _33, _34;
	float _41, _42, _43, _44;
};
