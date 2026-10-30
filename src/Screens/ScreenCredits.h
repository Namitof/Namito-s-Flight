#pragma once

#include <raylib.h>

namespace Credits
{

	void Init(Font font, int screenWidth, int screenHeight);

	void Update(bool& backButtonPressed);

	void Draw();

}