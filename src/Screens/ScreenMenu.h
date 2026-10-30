#pragma once

#include <raylib.h>

namespace Menu
{

	void Init(Font font, int screenWidth, int screenHeight);

	void Update(bool& playButtonPressed, bool& creditsButtonPressed, bool& exitButtonPressed);

	void Draw();

}