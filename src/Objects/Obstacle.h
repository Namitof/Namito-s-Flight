#pragma once

#include <raylib.h>

namespace Obtacle
{
	const float PATH_SIZE = 150.0f;

	const float OBSTACLE_WIDTH = 150.0f;
	const float OBSTACLE_HEIGHT = 720.0f;

	const float OBSTACLE_SPEED = 150.0f;

	const Vector2 SPAWN = { 1280, 0 };

	const float MIN_HEIGHT = 150.0f; //200.0f;
	const float MAX_HEIGHT = 570.0f; //1080.0f;

	struct Obstacle
	{
		Vector2 position;

		Vector2 direction;
		Vector2 speed;

		float path;

		Rectangle rectangleUp;
		Rectangle rectangleDown;

		bool isOffScreen;
	};


	void Init(Obstacle& obstacle);

	void Update(Obstacle& obstacle, float deltaTime);

	void Draw(Obstacle& obstacle);
}