#include "Engine.h"
#include "Player.h"
#include "Enemy.h"
#include "SpaceShooter.h"

#include <iostream>
#include <vector>
#include <cinttypes>
#include <time.h>
#include <algorithm>


using namespace std;
	
	int main()
	{
		neu::InitializeMemory();
		
		// Initialize Engine
		neu::g_renderer.Initialize();

		neu::g_renderer.Initialize();

		neu::g_audio.Initialize();

		neu::g_input.Initialize();

		// Create Window
		neu::g_renderer.CreateWindow("Neumont", 800, 600);
		neu::g_renderer.setClearColor(neu::Color{ 51, 51, 51, 255 });
		cout << neu::GetFilePath() << endl;
		neu::SetFilePath("../Assets");

		//Create Game
		SpaceShooter game;
		neu::g_audio.AddAudio("laser", "Bullet.wav");
		neu::g_audio.AddAudio("explosion", "Explosion.wav");
		neu::g_audio.AddAudio("Star_Trek", "BattleMusic.mp3");
		game.Initialize();




		
		//Update Loop
		bool quit = false;
		while (!quit) 
		{
			neu::g_time.Tick();
			neu::g_input.Update();
			
			if (neu::g_input.GetKeyDown(neu::key_escape)) {
				quit = true;
			}
			game.Update();
			
			neu::g_renderer.BeginFrame();
			// draw
			game.Draw(neu::g_renderer);
			neu::g_audio.Update();


			neu::g_renderer.EndFrame();


		}
		neu::g_audio.Shutdown();
		neu::g_renderer.Shutdown();

	}
	/*
		neu::Vector2 target = IS.getMousePosition();
		angle = target.GetAngle();
		neu::Vector2 direction{ 1, 0 };
		direction = neu::Vector2::Rotate(direction, angle - math::Halfpi);
		*/