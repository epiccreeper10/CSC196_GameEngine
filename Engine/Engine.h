#pragma once
#include "Input/InputSystem.h"
#include "Core/File.h"
#include "Math/Random.h"
#include "Math/MathUtils.h"
#include "Core/Time.h"
#include "Framework/Scene.h"
#include "Renderer/Model.h"
#include "Framework/Actor.h"
#include "Core/Memory.h"
#include "Renderer/Renderer.h"
#include "Audio/AudioSystem.h"
#include "Renderer/text.h"
#include "Renderer/font.h"

#include <memory>

namespace neu
{
	extern Renderer g_renderer;
	extern InputSystem g_input;
	extern Time g_time;
	extern AudioSystem g_audio;
}