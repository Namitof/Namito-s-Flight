#include "Obstacle.h"

#include <raylib.h>

namespace Obtacle
{
	//Constantes
	static const float OFFSET_VALUE = 150.0f;

	static const float OFFSET_SCREEN_LIMITS = 50.0f;

	static const float OBSTACLE_WIDTH = 50.0f;

	static const float OBSTACLE_SPEED = 150.0f;

	static const float MIN_HEIGHT = 150.0f; 
	static const float MAX_HEIGHT = 570.0f; 

	static const Vector2 LEFT_DIR = { -1, 0 };
	static const Vector2 HORIZONTAL_SPEED = { OBSTACLE_SPEED, 0 };

	//Variables
	static int screenWidth;
	static int screenHeight;


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

		int minHeight = static_cast<int>(OFFSET_VALUE + OFFSET_SCREEN_LIMITS);
		int maxHeight = static_cast<int>(screenHeight - OFFSET_SCREEN_LIMITS);

		int randomNumber = GetRandomValue(static_cast<int>(minHeight * DIVISION), static_cast<int>(maxHeight * DIVISION));

		float randomHeigth = randomNumber / DIVISION;

		obstacle.rectangleDown.height = screenHeight - randomHeigth;
		obstacle.rectangleUp.height = randomHeigth - obstacle.offset;

		setPos(obstacle, obstacle.position.x, randomHeigth);
	}

	void Init(Obstacle& obstacle, int width, int height)
	{
		screenWidth = width;
		screenHeight = height;

		obstacle.position.x = static_cast<float>(screenWidth);
		obstacle.position.y = 0;

		obstacle.direction = LEFT_DIR;

		obstacle.speed = HORIZONTAL_SPEED;

		obstacle.offset = OFFSET_VALUE;

		obstacle.rectangleUp.x = 0;
		obstacle.rectangleUp.y = 0;

		obstacle.rectangleUp.width = OBSTACLE_WIDTH;
		obstacle.rectangleUp.height = 0;

		obstacle.rectangleDown.x = 0;
		obstacle.rectangleDown.y = 0;

		obstacle.rectangleDown.width = OBSTACLE_WIDTH;
		obstacle.rectangleDown.height = 0;

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
			setPos(obstacle, static_cast<float>(screenWidth), 0.0f);
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