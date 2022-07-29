#pragma once
#include "Framework/Actor.h"
namespace neu {
	class Player : public neu::Actor
	{
	public:
		Player() = default;
		Player(const neu::Model model, const neu::Transform transform) :
			Actor{ model, transform } {}

		void Update() override;

		void OnCollision(Actor* other) override;

	private:
		float m_weaponType = 1;
		float m_healthRegen = 5;
		float m_health = 100;
		float m_speed = 100;
		float m_maxSpeed = 5;
	};
}