#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include "Engine.h"
namespace neu
{
	void neu::Bullet::Update()
	{
		neu::Vector2 direction = { 1, 0 };
		direction = neu::Vector2::Rotate(direction, m_transform.rotation);
		neu::Vector2 velocity = direction * m_speed * neu::g_time.deltaTime;
		m_transform.position += velocity;

		if (m_transform.position.x > neu::g_renderer.getWidth()) m_transform.position.x = 0;
		if (m_transform.position.x < 0) m_transform.position.x = (float)neu::g_renderer.getWidth();
		if (m_transform.position.y > neu::g_renderer.getWidth()) m_transform.position.y = 0;
		if (m_transform.position.y < 0) m_transform.position.y = (float)neu::g_renderer.getHeight();
	}
	void Bullet::OnCollision(Actor* other)
	{
		if (dynamic_cast<Player*>(other) && m_tag != "Player") {
			m_destory = true;
		}
		if (dynamic_cast<Enemy*>(other) && m_tag != "Enemy") {
			m_destory = true;
		}

	}
}
