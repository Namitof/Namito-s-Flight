#pragma once

#include <raylib.h>

namespace Player
{
	struct Player
	{
		Vector2 position;

		Vector2 direction;

		float verticalVelocity;

		float maxVerticalVelocity;

		Rectangle hitbox;

		float jumpForce;

		bool isAlive;

		int score;

		Color color;
	};

	void Init(Player& player, int screenWidth, int screenHeight);

	void Update(Player& player, float deltaTime, float gravity);

	void Draw(Player& player);
}