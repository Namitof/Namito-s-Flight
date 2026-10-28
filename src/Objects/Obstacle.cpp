#include "Obstacle.h"

#include <raylib.h>

namespace Obtacle
{
	//Constantes
	static const float OFFSET_VALUE = 150.0f;

	static const float OBSTACLE_WIDTH = 50.0f;
	static const float OBSTACLE_HEIGHT = 720.0f;
	
	static const float OBSTACLE_SPEED = 150.0f;
	
	static const Vector2 SPAWN = { 1280, 0 };
	
	static const float MIN_HEIGHT = 150.0f; //200.0f;
	static const float MAX_HEIGHT = 570.0f; //1080.0f;


	static void setPos(Obstacle& obstacle, float x, float y);

	static void SetRandomHeight(Obstacle& obstacle);


	static void setPos(Obstacle& obstacle, float x, float y)
	{
		obstacle.position.x = x;

		obstacle.position.y = y;

		obstacle.rectangleDown.x = x;
		obstacle.rectangleDown.y = y;

		obstacle.rectangleUp.x = x;
		obstacle.rectangleUp.y = y - obstacle.offset - obstacle.rectangleUp.height;
	}

	static void SetRandomHeight(Obstacle& obstacle)
	{
		const float DIVISION = 100.0f;

		int randomNumber = GetRandomValue(static_cast<int>(MIN_HEIGHT * DIVISION), static_cast<int>(MAX_HEIGHT * DIVISION));

		float randomHeigth = randomNumber / DIVISION;

		setPos(obstacle, obstacle.position.x, randomHeigth);

		/*obstacle.position.y = randomHeigth;

		obstacle.rectangleDown.y = randomHeigth;

		obstacle.rectangleUp.y = randomHeigth - obstacle.path - obstacle.rectangleUp.height;*/
	}

	void Init(Obstacle& obstacle)
	{
		obstacle.position.x = SPAWN.x;
		obstacle.position.y = 0;

		obstacle.direction.x = -1;
		obstacle.direction.y = 0;

		obstacle.speed.x = OBSTACLE_SPEED;
		obstacle.speed.y = OBSTACLE_SPEED;

		obstacle.offset = OFFSET_VALUE;

		obstacle.rectangleUp.x = 0;
		obstacle.rectangleUp.y = 0;

		obstacle.rectangleUp.width = OBSTACLE_WIDTH;
		obstacle.rectangleUp.height = OBSTACLE_HEIGHT;

		obstacle.rectangleDown.x = 0;
		obstacle.rectangleDown.y = 0;

		obstacle.rectangleDown.width = OBSTACLE_WIDTH;
		obstacle.rectangleDown.height = OBSTACLE_HEIGHT;

		obstacle.isOffScreen = false;

		SetRandomHeight(obstacle);
	}

	void Update(Obstacle& obstacle, float deltaTime)
	{
		obstacle.position.x += obstacle.direction.x * obstacle.speed.x * deltaTime;
		obstacle.position.y += obstacle.direction.y * obstacle.speed.y * deltaTime;
		
		setPos(obstacle, obstacle.position.x, obstacle.position.y);

		if (obstacle.isOffScreen)
		{
			setPos(obstacle, SPAWN.x, SPAWN.y);
			SetRandomHeight(obstacle);
			obstacle.isOffScreen = false;
		}
	}

	void Draw(Obstacle& obstacle)
	{
		DrawRectangleRec(obstacle.rectangleUp, RED);
		DrawRectangleRec(obstacle.rectangleDown, RED);
	}
}