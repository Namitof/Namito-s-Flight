#include "ScreenMenu.h"

#include <raylib.h>

#include "Utils/Text.h"
#include "Objects/Button.h"

namespace Menu
{
	//Constantes
	const float FONT_SIZE_TITLE = 40.0f;
	const float TITLE_FONT_SPACING = 10.0f;

	const float FONT_SIZE_BUTTON = 40.0f;
	const float BUTTON_FONT_SPACING = 10.0f;

	const float PLAY_TEXT_OFFSET_X = 20.0f;
	const float CREDITS_TEXT_OFFSET_X = 20.0f;
	const float EXIT_TEXT_OFFSET_X = 20.0f;
	const float BUTTONS_TEXT_OFFSET_Y = 5.0f;

	//Recursos
	static Text::Text title;

	static Button::Button play;
	static Button::Button credits;
	static Button::Button exit;

	static Font menuFont;


	static void ButtonsInit(int screenWidth, int screenHeight);

	static void TextInit();


	static void ButtonsInit(int screenWidth, int screenHeight)
	{
		//Init a cada boton
		Vector2 buttonPos;
		buttonPos.x = static_cast<float>((screenWidth / 2) - (Button::BUTTON_WIDTH / 2));
		buttonPos.y = static_cast<float>((screenHeight / 12) * 6);

		Vector2 textPos;

		Color currentColor = RED;
		Color defaultColor = RED;
		Color selectColor = MAROON;

		Text::Text text;

		Rectangle hitbox;
		hitbox.x = buttonPos.x;
		hitbox.y = buttonPos.y;
		hitbox.width = Button::BUTTON_WIDTH;
		hitbox.height = Button::BUTTON_HEIGHT;

		//Text backButton
		textPos.x = hitbox.x + PLAY_TEXT_OFFSET_X;
		textPos.y = hitbox.y + BUTTONS_TEXT_OFFSET_Y;

		Text::Init(text, menuFont, FONT_SIZE_BUTTON, "Play", textPos, BUTTON_FONT_SPACING, WHITE);

		Button::Init(play, defaultColor, selectColor, hitbox, text);

		//CREDITS
		buttonPos.x = static_cast<float>((screenWidth / 2) - (Button::BUTTON_WIDTH / 2));
		buttonPos.y = static_cast<float>((screenHeight / 12) * 8);

		hitbox.x = buttonPos.x;
		hitbox.y = buttonPos.y;
		hitbox.width = Button::BUTTON_WIDTH;
		hitbox.height = Button::BUTTON_HEIGHT;

		textPos.x = hitbox.x + CREDITS_TEXT_OFFSET_X;
		textPos.y = hitbox.y + BUTTONS_TEXT_OFFSET_Y;

		Text::Init(text, menuFont, FONT_SIZE_BUTTON, "Credits", textPos, BUTTON_FONT_SPACING, WHITE);

		Button::Init(credits, defaultColor, selectColor, hitbox, text);

		//EXIT
		buttonPos.x = static_cast<float>((screenWidth / 2) - (Button::BUTTON_WIDTH / 2));
		buttonPos.y = static_cast<float>((screenHeight / 12) * 10);

		hitbox.x = buttonPos.x;
		hitbox.y = buttonPos.y;
		hitbox.width = Button::BUTTON_WIDTH;
		hitbox.height = Button::BUTTON_HEIGHT;

		textPos.x = hitbox.x + EXIT_TEXT_OFFSET_X;
		textPos.y = hitbox.y + BUTTONS_TEXT_OFFSET_Y;

		Text::Init(text, menuFont, FONT_SIZE_BUTTON, "Exit", textPos, BUTTON_FONT_SPACING, WHITE);

		Button::Init(exit, defaultColor, selectColor, hitbox, text);
	}

	static void TextInit()
	{
		Vector2 pos;
		pos.x = 100;
		pos.y = 100;
		Text::Init(title, menuFont, FONT_SIZE_TITLE, "Namito's Flight", pos, TITLE_FONT_SPACING, BLACK);
	}

	void Init(Font font, int screenWidth, int screenHeight)
	{
		menuFont = font;
		TextInit();
		ButtonsInit(screenWidth, screenHeight);
	}

	void Update(bool& playButtonPressed, bool& creditsButtonPressed, bool& exitButtonPressed)
	{
		//Actualizar estado de botones
		Vector2 mousePos = GetMousePosition();

		//Play
		Button::Update(play, mousePos);
		if (!play.isPressed && play.wasPressed)
		{
			play.isPressed = false;
			play.wasPressed = false;
			playButtonPressed = true;
		}
		else
		{
			playButtonPressed = false;
		}

		//Credits
		Button::Update(credits, mousePos);
		if (!credits.isPressed && credits.wasPressed)
		{
			credits.isPressed = false;
			credits.wasPressed = false;
			creditsButtonPressed = true;
		}
		else
		{
			creditsButtonPressed = false;
		}

		//Exit
		Button::Update(exit, mousePos);
		if (!exit.isPressed && exit.wasPressed)
		{
			exit.isPressed = false;
			exit.wasPressed = false;
			exitButtonPressed = true;
		}
		else
		{
			exitButtonPressed = false;
		}
	}

	void Draw()
	{
		Text::Draw(title);
		Button::Draw(play);
		Button::Draw(credits);
		Button::Draw(exit);
	}

}