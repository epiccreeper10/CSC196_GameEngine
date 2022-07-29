#include "text.h"
#include "font.h"
#include "Renderer.h"
#include <SDL.h>
#include "../../ThirdParty/SDL2_ttf-2.20.0/include/SDL_ttf.h"

namespace neu
{
	neu::Text::~Text()
	{
		if (m_texture) SDL_DestroyTexture(m_texture);
	}

	void neu::Text::Create(Renderer& renderer, const std::string& text, const Color& color)
	{
		SDL_Color c{ color.r, color.g, color.b, color.a };
		SDL_Surface* surface = TTF_RenderText_Solid(m_font->m_ttfFont, text.c_str(), c);

		m_texture = SDL_CreateTextureFromSurface(renderer.m_renderer, surface);
		SDL_FreeSurface(surface);
	}

	void neu::Text::Draw(Renderer& renderer, const Vector2& position)
	{
		int width, height;
		SDL_QueryTexture(m_texture, nullptr, nullptr, &width, &height);

		SDL_Rect rect{ (int)position.x, (int)position.y, width, height };

		SDL_RenderCopy(renderer.m_renderer, m_texture, NULL, &rect);
	}
}
