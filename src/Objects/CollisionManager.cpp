#include "CollisionManager.h"

#include "Player.h"

namespace ColisionManager
{
	void CheckColisions(Player::Player& player, int screenWidth, int screenHeight)
	{
		if (player.position.y <= 0)
		{
			player.position.y = 0;
		}
		else if (player.position.y + player.hitbox.height >= screenHeight)
		{
			player.position.y = static_cast<float>(screenHeight) - player.hitbox.height;
		}

		screenWidth++;
	}
}