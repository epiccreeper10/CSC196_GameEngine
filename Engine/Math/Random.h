#pragma once
#include <random>
namespace neu
{
	inline void SeedRandom(int seed) { srand(seed); }

	inline int random() { return rand(); }
	inline int random(int max) { return random() % max; } // Exclusive
	inline int random(int min, int max) { return min + random() % ((max - min) + 1);} // Inclusive
	
	inline float randomf() { return rand() / (float)RAND_MAX; } // 0.0 - 1.0
	inline float randomf(float max) { return randomf() * max; }
	inline float randomf(float min, float max) { return min + randomf(max - min); }
}