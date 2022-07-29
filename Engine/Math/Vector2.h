#pragma once
#include <cmath>
#include <iostream>
#include <string>

namespace neu
{
	struct Vector2
	{
		float x, y;

		Vector2() : x{ 0 }, y{ 0 } {};
		Vector2(float x, float y) : x{ x }, y{ y } {};
		Vector2(float v) : x{ v }, y{ v } {};
		Vector2(int x, int y) : x{ (float)x }, y{ (float)y } {}

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
		Vector2 operator -= (float s) { return Vector2{ this->x -= s, this->y -= s }; return *this; }
		Vector2 operator *= (float s) { return Vector2{ this->x *= s, this->y *= s }; return *this; }
		Vector2 operator /= (float s) { return Vector2{ this->x /= s, this->y /= s }; return *this; }

		Vector2 operator - () const { return Vector2{ -x, -y }; }
		
		bool operator == (const Vector2& v) const { return (this->x == v.x && this->y == v.y); }
		bool operator != (const Vector2& v) const { return (this->x != v.x || this->y != v.y); }

		//Functions
		float Lengthsqr();
		float Length();

		float DistanceSqr(const Vector2& v);
		float Distance(const Vector2& v);
		
		Vector2 Normalized();
		void Normalize();

		static Vector2 Rotate(const Vector2& v, float angle);
		float GetAngle();
	};

	inline std::istream& operator >> (std::istream& stream, Vector2& v)
	{
		std::string line;
		std::getline(stream, line);

		// { ##, ## }
		size_t start = line.find("{") + 1;
		size_t middle = line.find(",");
		size_t end = line.find("}");

		std::string xs = line.substr(start, middle - start - 1);
		v.x = std::stof(xs);

		std::string ys = line.substr(middle + 1, end - middle - 2);
		v.y = std::stof(ys);

		return stream;
	}


	inline float Vector2::Lengthsqr() { return x * x + y * y; }

	inline float Vector2::Length() { return std::sqrt(x * x + y * y); }

	inline float Vector2::DistanceSqr(const Vector2& v)
	{
		return ((*this-v).Lengthsqr());
	}

	inline float Vector2::Distance(const Vector2& v)
	{
		return ((*this - v).Length());
	}
	inline Vector2 Vector2::Normalized()
	{
		float length = Length();
		return Vector2{ x / length, y / length};
	}
	inline void Vector2::Normalize()
	{
		(*this) /= Length();
	}
	inline Vector2 Vector2::Rotate(const Vector2& v, float angle)
	{
		float x = v.x * std::cos(angle) - v.y * std::sin(angle);
		float y = v.x * std::sin(angle) + v.y * std::cos(angle);

		return Vector2{ x, y };

		
	}
	inline float Vector2::GetAngle()
	{
		return std::atan2(y, x);
	}
}