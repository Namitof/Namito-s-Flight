#pragma once

#include <raylib.h>

namespace Player
{
	const float PLAYER_WIDTH = 100.0f;
	const float PLAYER_HEIGHT = 100.0f;

	const float SPEED = 200.f;

	struct Player
	{
		Vector2 position;

		Vector2 direction;

		Vector2 speed;

		Rectangle hitbox;

		bool isAlive;

		int score;

		Color color;
	};

	void Init(Player& player, int screenWidth, int screenHeight);

	void Update(Player& player, float deltaTime);

	void Draw(Player& player);
}