#include "SpaceShooter.h"
#include "Engine.h"
#include "Player.h"
#include "Enemy.h"

void SpaceShooter::Initialize()
{
	

	m_scene = std::make_unique<neu::Scene>(this);

	neu::Text title(neu::Font);

	m_font = std::make_unique<neu::Font>("Fonts/HumanWorld.ttf", 24);
	m_titleText = std::make_unique<neu::Text>(m_font.get());
	m_titleText->Create(neu::g_renderer, "Star Trek", { 0, 255, 255, 255 });
	m_scoreText = std::make_unique<neu::Text>(m_font.get());
	m_scoreText->Create(neu::g_renderer, "000000", { 255, 255, 255, 255 });

	neu::g_audio.PlayAudio("Star_Trek", true);


	neu::Transform transform;
	transform.position = neu::Vector2{ 400, 300 };
	transform.rotation = 0;
	transform.scale = 5;
	
	neu::SeedRandom(23443);
	
	//Transform
	neu::Vector2 move{ 3,0 };
	float angle = 0;
	std::unique_ptr<neu::Player> player = std::make_unique<neu::Player>(neu::Model("Player.txt"), transform);
	m_scene->Add(std::move(player));


	std::unique_ptr<neu::Enemy> enemy = std::make_unique<neu::Enemy>(neu::Model("Enemy.txt"), transform, 20.0f);
	m_scene->Add(std::move(enemy));
}

void SpaceShooter::Shutdown()
{
}

void SpaceShooter::Update()
{
	
	m_spawntimer -= neu::g_time.deltaTime;
	if (m_spawntimer <= 0)
	{
		
		neu::Transform transform;
		transform.position.x = neu::randomf(800);
		transform.position.y = neu::randomf(600);
		transform.rotation = neu::randomf(math::Twopi);
		transform.scale = 5;  // 0 - 412857931
		
			m_spawntimer = 2;
		
		std::unique_ptr<neu::Enemy> enemy = std::make_unique<neu::Enemy>(neu::Model("Enemy.txt"), transform);
		m_scene->Add(std::move(enemy));
		if (m_score > 100) {
			transform.position.x = neu::randomf(800);
			transform.position.y = neu::randomf(600);
			transform.rotation = neu::randomf(math::Twopi);
			transform.scale = 5;  // 0 - 412857931
			std::unique_ptr<neu::Enemy> enemy = std::make_unique<neu::Enemy>(neu::Model("Enemy.txt"), transform);
			m_scene->Add(std::move(enemy));
			if (m_score > 200) {
				transform.position.x = neu::randomf(800);
				transform.position.y = neu::randomf(600);
				transform.rotation = neu::randomf(math::Twopi);
				transform.scale = 5;  // 0 - 412857931
				std::unique_ptr<neu::Enemy> enemy = std::make_unique<neu::Enemy>(neu::Model("Enemy.txt"), transform);
				m_scene->Add(std::move(enemy));
				if (m_score > 300) {
					m_spawntimer = 1;
				}
			}
		}

		m_scoreText->Create(neu::g_renderer, std::to_string(m_score), { 255, 255, 255, 255 });
	}
	m_pointTimer -= neu::g_time.deltaTime;
	if (m_pointTimer <= 0)
	{
		m_score += 10;
		m_pointTimer = 3;
	}

	m_scene->Update();

	m_scoreText->Create(neu::g_renderer, std::to_string(m_score), { 255, 255, 255, 255 });
}

void SpaceShooter::Draw(neu::Renderer& renderer)
{
	m_scene->Draw(renderer);

	m_titleText->Draw(renderer, { 400, 300 });
	m_scoreText->Draw(renderer, { 40, 30 });
}
