#pragma once

#include "Player.h"
#include "Obstacle.h"

namespace ColisionManager
{
	void CheckColisions(Player::Player& player, Obtacle::Obstacle& obstacle, int screenHeight);
}
