#include "Player.h"

#include <raylib.h>

namespace Player
{
	static const float PLAYER_WIDTH = 60.0f;
	static const float PLAYER_HEIGHT = 60.0f;

	static const float INITIAL_SPEED = 200.f;

	static const float JUMP_FORCE = 300.0f;
	static const float MAX_VELOCITY = 500.0f;

	static Vector2 UP_DIR = { 0, -1 };
	static Vector2 DOWN_DIR = { 0, 1 };

	void Init(Player& player, int screenWidth, int screenHeight)
	{
		player.position.x = static_cast<float>(screenWidth / 4);
		player.position.y = static_cast<float>(screenHeight / 2);

		player.direction.x = 0;
		player.direction.y = 0;

		player.verticalVelocity = INITIAL_SPEED;
		player.maxVerticalVelocity = MAX_VELOCITY;

		player.hitbox.width = PLAYER_WIDTH;
		player.hitbox.height = PLAYER_HEIGHT;

		player.hitbox.x = player.position.x;
		player.hitbox.y = player.position.y;

		player.jumpForce = JUMP_FORCE;

		player.isAlive = true;

		player.score = 0;

		player.color = GREEN;
	}

	void Update(Player& player, float deltaTime, float gravity)
	{
		if (IsKeyPressed(KEY_SPACE) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			player.verticalVelocity = player.jumpForce * UP_DIR.y;
			player.direction = UP_DIR;
		}
		else
		{
			player.direction = DOWN_DIR;
		}

		/*if (player.direction.y == DOWN_DIR.y)
		{
			player.verticalVelocity = SPEED;
		}*/
		/*if (IsKeyDown(KEY_W))
		{
			player.direction = UP_DIR;

			player.position.y += player.direction.y * player.verticalVelocity * deltaTime;
		}
		else if (IsKeyDown(KEY_S))
		{
			player.direction = DOWN_DIR;

			player.position.y += player.direction.y * player.verticalVelocity * deltaTime;
		}*/

		//Aceleracion
		if (player.verticalVelocity >= player.maxVerticalVelocity)
		{
			player.verticalVelocity = player.maxVerticalVelocity;
		}
		else
		{
			player.verticalVelocity += gravity * deltaTime;
		}


		//Actualizo posicion
		player.position.y += player.direction.y * player.verticalVelocity * deltaTime;

		player.hitbox.x = player.position.x;
		player.hitbox.y = player.position.y;
	}

	void Draw(Player& player)
	{
		DrawRectangleRec(player.hitbox, player.color);
	}
}