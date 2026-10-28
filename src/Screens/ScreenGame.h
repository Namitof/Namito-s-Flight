#pragma once

namespace Game
{

	void Init(int screenWidth, int screenHeight);

	void Update(float deltaTime, int screenHeight, bool& isGameOver);

	void Draw();

}