#include "font.h"
#include "../../ThirdParty/SDL2_ttf-2.20.0/include/SDL_ttf.h"

neu::Font::Font(const std::string& filename, int fontSize)
{
	Load(filename, fontSize);
}

neu::Font::~Font()
{
	if (m_ttfFont) TTF_CloseFont(m_ttfFont);
}

void neu::Font::Load(const std::string& filename, int fontSize)
{
	m_ttfFont = TTF_OpenFont(filename.c_str(), fontSize);
}
