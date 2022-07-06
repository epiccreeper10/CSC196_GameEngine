#pragma once

namespace neu
{
	struct Vector2
	{
		float x, y;

		Vector2() : x{ 0 }, y{ 0 } {};
		Vector2(float x, float y) : x{ x }, y{ y } {};
		Vector2(float v) : x{ v }, y{ v } {};

		void set(float x, float y) {}

		Vector2 operator + (const Vector2& v) { return Vector2{ this->x + v.x, this->y + v.y }; }
		Vector2 operator - (const Vector2& v) { return Vector2{ this->x - v.x, this->y - v.y }; }
		Vector2 operator * (const Vector2& v) { return Vector2{ this->x * v.x, this->y * v.y }; }
		Vector2 operator / (const Vector2& v) { return Vector2{ this->x / v.x, this->y / v.y }; }

		Vector2 operator += (const Vector2& v) { return Vector2{ this->x += v.x, this->y += v.y }; return *this; }
		Vector2 operator -= (const Vector2& v) { return Vector2{ this->x -= v.x, this->y -= v.y }; return *this; }
		Vector2 operator *= (const Vector2& v) { return Vector2{ this->x *= v.x, this->y *= v.y }; return *this; }
		Vector2 operator /= (const Vector2& v) { return Vector2{ this->x /= v.x, this->y /= v.y }; return *this; }

		Vector2 operator + (float s) { return Vector2{ this->x + s, this->y + s }; }
		Vector2 operator - (float s) { return Vector2{ this->x - s, this->y - s }; }
		Vector2 operator * (float s) { return Vector2{ this->x * s, this->y * s }; }
		Vector2 operator / (float s) { return Vector2{ this->x / s, this->y / s }; }

		Vector2 operator += (float s) { return Vector2{ this->x += s, this->y += s }; return *this; }
	};
}