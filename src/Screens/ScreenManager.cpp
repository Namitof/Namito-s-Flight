#include "ScreenManager.h"

#include <ctime>

#include <raylib.h>

#include "ScreenGame.h"
#include "Utils/Text.h"

namespace ScreenManager
{
	//Constantes
	static const int SCREEN_WIDTH = 1080;
	static const int SCREEN_HEIGHT = 720;

	static const int MAX_FONT_SIZE = 100;

	
	//Recursos
	static Font font;

	static Text::Text version;

	
	static void TextInit();

	static void Init();

	static void Update(float deltaTime);

	static void Draw();

	static void Delete();


	static void TextInit()
	{
		const float fontSize = 50.0f;

		const Vector2 position = { 10, 0 };

		Text::Init(version, font, fontSize, "v 0.1", position, 0, BLACK);
	}

	static void Init()
	{
		InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Namito's Flight");

		SetRandomSeed(static_cast<unsigned int>(time(NULL)));

		//Carga centralizada de recursos
		font = LoadFontEx("res/font/accid___.ttf", MAX_FONT_SIZE, NULL, 0);

		TextInit();

		Game::Init(SCREEN_WIDTH, SCREEN_HEIGHT);
	}

	static void Update(float deltaTime)
	{
		bool isGameOver;

		Game::Update(deltaTime, SCREEN_HEIGHT, isGameOver);

		if (isGameOver)
		{
			Game::Init(SCREEN_WIDTH, SCREEN_HEIGHT);
		}
	}

	static void Draw()
	{
		BeginDrawing();
		ClearBackground(WHITE);

		Game::Draw();

		Text::Draw(version);

		EndDrawing();
	}

	static void Delete()
	{
		UnloadFont(font);
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

		//Borrar y liberar recursos
		Delete();

		// Cierre
		CloseWindow();
	}
}