#pragma once
#include "Framework/Actor.h"
namespace neu
{
	class Bullet : public neu::Actor
	{
	public:
		Bullet() = default;
		Bullet(const neu::Model model, const neu::Transform transform, float damage = 1) :
			Actor{ model, transform },
			m_damage{ damage }{}



		void Update() override;

		void OnCollision(Actor* other) override;

		float GetDamage() { return m_damage; }

	private:
		float m_damage = 1;
		float m_speed = 200;
	};
}