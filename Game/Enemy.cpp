#include "Enemy.h"
#include "Bullet.h"
#include "Player.h"
#include "Engine.h"
namespace neu {
	void Enemy::Update()
	{
		m_fireTimer -= neu::g_time.deltaTime;

		if (m_fireTimer <= 0)
		{
			std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>(neu::Model("BulletE.txt"), m_transform);
			bullet->GetTag() = "Enemy";
			scene->Add(std::move(bullet));
			m_fireTimer = neu::randomf(3, 5);
		}

		// set rotation twards player
		Player* player = scene->GetActor<Player>();
		if (player)
		{
			neu::Vector2 direction = player->m_transform.position - m_transform.rotation;
			m_transform.rotation = direction.GetAngle();
		}

		neu::Vector2 direction = { 1, 0 };
		direction = neu::Vector2::Rotate(direction, m_transform.rotation);
		neu::Vector2 velocity = (direction * m_speed * neu::g_time.deltaTime);
		m_transform.position += velocity;

		if (m_transform.position.x > neu::g_renderer.getWidth()) m_transform.position.x = 0;
		if (m_transform.position.x < 0) m_transform.position.x = (float)neu::g_renderer.getWidth();
		if (m_transform.position.y > neu::g_renderer.getWidth()) m_transform.position.y = 0;
		if (m_transform.position.y < 0) m_transform.position.y = (float)neu::g_renderer.getHeight();

	}

	void Enemy::Initialize()
	{
		m_fireTimer = neu::randomf(3, 5);
		m_speed = neu::randomf(20, 150);
	}
	void Enemy::OnCollision(Actor* other)
	{
		if (dynamic_cast<Bullet*>(other) && other->GetTag() == "Player")
		{
			m_health -= m_health -= dynamic_cast<Bullet*>(other)->GetDamage();
			if (m_health <= 0) {
				m_destory = true;
			}
		}
	}
}
