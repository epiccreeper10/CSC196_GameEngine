#pragma once
#include "Renderer.h"
#include <iostream>
#include <vector>

namespace neu
{

	class Model
	{
	public:
		Model() = default;
		Model(const std::vector<neu::Vector2>& points, const neu::Color& color) :
			m_points{ points }, m_color{ color }
		{
		}

		Model(const std::string filename);

		void Draw(Renderer& renderer, const Vector2& position, float angle, float scale = 1);

		void Load(const std::string& filename);

		float GetRadius() { return m_radius; }
		float CalculateRadius();
	private:
		neu::Color m_color;
		std::vector<neu::Vector2> m_points;

		float m_radius = 0;
	};
}