#include "CollisionManager.h"

#include <raylib.h>

#include "Player.h"
#include "Obstacle.h"

namespace ColisionManager
{
	static bool CollisionAABB(Rectangle rectA, Rectangle rectB);


	static bool CollisionAABB(Rectangle rectA, Rectangle rectB)
	{
		//Chequeo si el rectangulo A esta a la izquierda de B
		bool isAToTheLeftOfB = false;
		if (rectA.x + rectA.width < rectB.x)
		{
			isAToTheLeftOfB = true;
		}

		//Chequeo si el rectangulo A esta a la derecha de B
		bool isAToTheRightOfB = false;
		if (rectA.x > rectB.x + rectB.width)
		{
			isAToTheRightOfB = true;
		}

		//Chequeo si el rectangulo A esta encima de B
		bool AisAboveB = false;
		if (rectA.y + rectA.height < rectB.y)
		{
			AisAboveB = true;
		}

		//Chequeo si el rectangulo A esta por debajo de B
		bool AisBelowB = false;
		if (rectA.y > rectB.y + rectB.height)
		{
			AisBelowB = true;
		}

		//Si se cumplen todas -> Los rectangulos estan colisionando
		return !(isAToTheRightOfB || isAToTheLeftOfB || AisAboveB || AisBelowB);
	}

	void CheckColisions(Player::Player& player, Obtacle::Obstacle& obstacle, int screenHeight)
	{
		//Chequeo colision del player con la parte superior e inferior de la pantalla
		if (player.position.y <= 0)
		{
			player.position.y = 0;
		}
		else if (player.position.y + player.hitbox.height >= screenHeight)
		{
			player.position.y = static_cast<float>(screenHeight) - player.hitbox.height;
		}

		//Chequeo colsion de los obstaculos con el borde izquierdo de la pantalla
		if (obstacle.position.x + obstacle.rectangleUp.width <= 0)
		{
			obstacle.isOffScreen = true;
		}

		//Chequeo colision con los obstaculos
		if (CollisionAABB(player.hitbox, obstacle.rectangleDown) || CollisionAABB(player.hitbox, obstacle.rectangleUp))
		{
			player.isAlive = false;
		}
	}
}