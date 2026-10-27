#include "ScreenManager.h"

#include <raylib.h>

#include "ScreenGame.h"

namespace ScreenManager
{
	//Recursos
	static const int SCREEN_WIDTH = 1080;
	static const int SCREEN_HEIGHT = 720;

	static void Init();

	static void Update(float deltaTime);

	static void Draw();


	static void Init()
	{
		InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Namito's Flight");

		Game::Init(SCREEN_WIDTH, SCREEN_HEIGHT);
	}

	static void Update(float deltaTime)
	{
		Game::Update(deltaTime, SCREEN_WIDTH, SCREEN_HEIGHT);
	}

	static void Draw()
	{
		BeginDrawing();
		ClearBackground(WHITE);

		Game::Draw();

		EndDrawing();
	}

	void Run()
	{
		// Inicialización
		Init();

		float deltaTime = 0.0f;

		// Loop
		while (!WindowShouldClose())
		{
			deltaTime = GetFrameTime();

			// Actualización
			Update(deltaTime);

			// Dibujado
			Draw();
		}

		// Cierre
		CloseWindow();
	}
}