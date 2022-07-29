//#pragma once

namespace math {

	const float pi = 3.14159265359f;
	const float Twopi = 6.28318530718f;
	const float Halfpi = 1.57079632679f;

	inline float DegToRad(float degrees)
	{
		return degrees * (pi / 180);
	}	
	inline float RadtoDeg(float radians)
	{
		return radians * (180 / pi);
	}

	int sqr(int v);
	inline int half(int v) { return v / 2; }
}


/*
#ifndef __MATH_UTILS_H__
#define __MATH_UTILS_H__
namespace Math {
	int sqr(int v);
}

#endif // __MATH_UTILS_H__
*/