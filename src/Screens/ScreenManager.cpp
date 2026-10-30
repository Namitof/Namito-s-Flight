#include "ScreenManager.h"

#include <ctime>

#include <raylib.h>

#include "ScreenGame.h"
#include "ScreenMenu.h"
#include "ScreenCredits.h"
#include "Utils/Text.h"

namespace ScreenManager
{
	//Constantes
	static const int SCREEN_WIDTH = 1280;
	static const int SCREEN_HEIGHT = 720;

	static const int MAX_FONT_SIZE = 100;


	//Recursos
	static Font font;

	static Text::Text version;

	static Screens currentScreen;

	static bool isRunning;


	static void TextInit();

	static void Init();

	static void Update(float deltaTime);

	static void Draw();

	static void Delete();


	static void TextInit()
	{
		const float fontSize = 50.0f;

		const Vector2 position = { 10, 0 };

		Text::Init(version, font, fontSize, "v 0.2", position, 0, BLACK);
	}

	static void Init()
	{
		InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Namito's Flight");

		SetRandomSeed(static_cast<unsigned int>(time(NULL)));

		currentScreen = Screens::Menu;

		isRunning = true;

		//Carga centralizada de recursos
		font = LoadFontEx("res/font/accid___.ttf", MAX_FONT_SIZE, NULL, 0);

		TextInit();

		Game::Init(SCREEN_WIDTH, SCREEN_HEIGHT);

		Menu::Init(font, SCREEN_WIDTH, SCREEN_HEIGHT);

		Credits::Init(font, SCREEN_WIDTH, SCREEN_HEIGHT);
	}

	static void Update(float deltaTime)
	{
		bool isGameOver;
		bool playButtonPressed;
		bool creditsButtonPressed;
		bool exitButtonPressed;
		bool backButtonPressed;

		switch (currentScreen)
		{
		case Screens::Menu:
			Menu::Update(playButtonPressed, creditsButtonPressed, exitButtonPressed);
			if (playButtonPressed)
			{
				currentScreen = Screens::Play;
			}
			else if (creditsButtonPressed)
			{
				currentScreen = Screens::Credits;
			}
			else if (exitButtonPressed)
			{
				currentScreen = Screens::Exit;
			}
			break;
		case Screens::Play:
			Game::Update(deltaTime, SCREEN_HEIGHT, isGameOver);
			if (isGameOver)
			{
				currentScreen = Screens::Menu;
				Game::Init(SCREEN_WIDTH, SCREEN_HEIGHT);
			}
			break;
		case Screens::Credits:
			Credits::Update(backButtonPressed);
			if (backButtonPressed)
			{
				currentScreen = Screens::Menu;
			}
			break;
		case Screens::Exit:
			isRunning = false;
			break;
		default:
			break;
		}
	}

	static void Draw()
	{
		BeginDrawing();
		ClearBackground(WHITE);

		switch (currentScreen)
		{
		case Screens::Menu:
			Menu::Draw();
			Text::Draw(version);
			break;
		case Screens::Play:
			Game::Draw();
			break;
		case Screens::Credits:
			Credits::Draw();
			break;
		case Screens::Exit:

			break;
		default:
			break;
		}

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
		while (!WindowShouldClose() && isRunning)
		{
			deltaTime = GetFrameTime();

			// Actualización
			Update(deltaTime);

			// Dibujado
			Draw();
		}

		// Borrar y liberar recursos
		Delete();

		// Cierre
		CloseWindow();
	}
}