#pragma once
#include <Framework/game.h>

namespace neu
{
	class Font;
	class Text;
}

class SpaceShooter : public neu::Game
{
	
public:
	SpaceShooter() = default;
	~SpaceShooter() = default;

	virtual void Initialize() override;

	virtual void Shutdown() override;


	virtual void Update() override;


	virtual void Draw(neu::Renderer& renderer) override;
	std::unique_ptr<neu::Text> m_scoreText;

private:
	float m_spawntimer = 2;
	std::unique_ptr<neu::Font> m_font;
	std::unique_ptr<neu::Text> m_titleText;
	float m_pointTimer = 5;
};