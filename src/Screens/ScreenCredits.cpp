#include "ScreenCredits.h"

#include <raylib.h>

#include "Utils/Text.h"
#include "Objects/Button.h"

namespace Credits
{
	//Constantes
	const float FONT_SIZE_TITLE = 40.0f;
	const float TITLE_FONT_SPACING = 10.0f;

	const float FONT_SIZE_BUTTON = 40.0f;
	const float BUTTON_FONT_SPACING = 10.0f;

	const float BACK_TEXT_OFFSET_X = 20.0f;
	const float BUTTONS_TEXT_OFFSET_Y = 5.0f;

	//Recursos
	static Text::Text credits;

	static Button::Button back;

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
		textPos.x = hitbox.x + BACK_TEXT_OFFSET_X;
		textPos.y = hitbox.y + BUTTONS_TEXT_OFFSET_Y;

		Text::Init(text, menuFont, FONT_SIZE_BUTTON, "Back", textPos, BUTTON_FONT_SPACING, WHITE);

		Button::Init(back, defaultColor, selectColor, hitbox, text);
	}

	static void TextInit()
	{
		Vector2 pos;
		pos.x = 100;
		pos.y = 100;
		Text::Init(credits, menuFont, FONT_SIZE_TITLE, "Game Development by: Suarez Nahuel", pos, TITLE_FONT_SPACING, BLACK);
	}

	void Init(Font font, int screenWidth, int screenHeight)
	{
		menuFont = font;
		TextInit();
		ButtonsInit(screenWidth, screenHeight);
	}

	void Update(bool& backButtonPressed)
	{
		//Actualizar estado de botones
		Vector2 mousePos = GetMousePosition();

		//Back
		Button::Update(back, mousePos);
		if (!back.isPressed && back.wasPressed)
		{
			back.isPressed = false;
			back.wasPressed = false;
			backButtonPressed = true;
		}
		else
		{
			backButtonPressed = false;
		}
	}

	void Draw()
	{
		Text::Draw(credits);
		Button::Draw(back);
	}

}