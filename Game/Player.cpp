#include "Player.h"
#include "Engine.h"
#include "Math/Transform.h"
#include "Bullet.h"
#include <memory>

#include <iostream>

void neu::Player::Update()
{
	bool cheat = 0;
	float thrust = 0;

	if (neu::g_input.GetKeyDown(neu::key_left)) {
		GetTransform().rotation -= math::pi * neu::g_time.deltaTime;
	
	}

	if (neu::g_input.GetKeyDown(neu::key_right)) {
		GetTransform().rotation += math::pi * neu::g_time.deltaTime;
		
	}

	if (neu::g_input.GetKeyState(neu::key_up) == neu::InputSystem::KeyState::Held) {
		m_speed *= 1.1;
		if (m_speed > 3000) {
			m_speed = 3000;
		}
	}

	if (neu::g_input.GetKeyState(neu::key_down) == neu::InputSystem::KeyState::Held)
	{
		m_speed -= m_speed;
		if (m_speed <= 0) {
			m_speed = 1;
		}
	}
	if (neu::g_input.GetKeyState(neu::key_j) == neu::InputSystem::KeyState::Held)
	{
		m_health = 999999;
		cheat = 1;
		std::cout << "what you have done can never be taken back" << std::endl;
	}
	if (neu::g_input.GetKeyState(neu::key_tab) == neu::InputSystem::KeyState::Pressed)
	{
		m_weaponType += 1;
		if (m_weaponType >= 3) {
			m_weaponType = 1;
		}
	}
	neu::Vector2 direction = { 1, 0 };
	direction = neu::Vector2::Rotate(direction, m_transform.rotation);
	neu::Vector2 force = direction * m_speed * neu::g_time.deltaTime;
	m_velocity += force;

	m_transform.position += m_velocity * neu::g_time.deltaTime;

	m_velocity *= 1.0f / (1.0f + m_damping * neu::g_time.deltaTime);
	if (m_weaponType == 1) {
		if (neu::g_input.GetKeyState(neu::key_space) == neu::InputSystem::KeyState::Pressed) {

			std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>(neu::Model("Bullet.txt"), m_transform);
			bullet->GetTag() = "Player";
			scene->Add(std::move(bullet));

			g_audio.PlayAudio("laser");

		}
	}
	else if (m_weaponType == 2) {
		if (neu::g_input.GetKeyState(neu::key_space) == neu::InputSystem::KeyState::Held) {

			std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>(neu::Model("Laser.txt"), m_transform);
			bullet->GetTag() = "Player";
			scene->Add(std::move(bullet));

			g_audio.PlayAudio("laser");

		}
	}
	if (m_transform.position.x > neu::g_renderer.getWidth()) m_transform.position.x = 0;
	if (m_transform.position.x < 0) m_transform.position.x = (float)neu::g_renderer.getWidth();
	if (m_transform.position.y > neu::g_renderer.getWidth()) m_transform.position.y = 0;
	if (m_transform.position.y < 0) m_transform.position.y = (float)neu::g_renderer.getHeight();
	m_healthRegen -= neu::g_time.deltaTime;
	while (m_health <= 100 && m_healthRegen <= 0) {
		m_healthRegen = 1;
		m_health += 1;
	}
}

void neu::Player::OnCollision(Actor* other)
{
	if (dynamic_cast<Bullet*>(other) && other->GetTag() == "Enemy") {


		m_health -= dynamic_cast<Bullet*>(other)->GetDamage();
		std::cout << m_health << std::endl;
		if (m_health <= 0) {
			m_destory = true;
		}
	}
}


