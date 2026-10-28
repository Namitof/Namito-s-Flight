#include "Player.h"

#include <raylib.h>

namespace Player
{
	void Init(Player& player, int screenWidth, int screenHeight)
	{
		player.position.x = static_cast<float>(screenWidth / 4);
		player.position.y = static_cast<float>(screenHeight / 2);

		player.direction.x = 0;
		player.direction.y = 0;

		player.speed.x = SPEED;
		player.speed.y = SPEED;

		player.hitbox.width = PLAYER_WIDTH;
		player.hitbox.height = PLAYER_HEIGHT;

		player.hitbox.x = player.position.x;
		player.hitbox.y = player.position.y;

		player.isAlive = true;

		player.score = 0;

		player.color = GREEN;
	}

	void Update(Player& player, float deltaTime)
	{
		if (IsKeyDown(KEY_W))
		{
			player.direction.x = 0;
			player.direction.y = -1;

			player.position.x += player.direction.x * player.speed.x * deltaTime;
			player.position.y += player.direction.y * player.speed.y * deltaTime;
		}
		else if (IsKeyDown(KEY_S))
		{
			player.direction.x = 0;
			player.direction.y = 1;

			player.position.x += player.direction.x * player.speed.x * deltaTime;
			player.position.y += player.direction.y * player.speed.y * deltaTime;
		}

		player.hitbox.x = player.position.x;
		player.hitbox.y = player.position.y;
	}

	void Draw(Player& player)
	{
		DrawRectangleRec(player.hitbox, player.color);
	}
}