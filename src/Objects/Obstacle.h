#pragma once

#include <raylib.h>

namespace Obtacle
{
	

	struct Obstacle
	{
		Vector2 position;

		Vector2 direction;

		Vector2 speed;

		float offset;

		Rectangle rectangleUp;
		Rectangle rectangleDown;

		bool isOffScreen;
	};


	void Init(Obstacle& obstacle, int width, int height);

	void Update(Obstacle& obstacle, float deltaTime);

	void Draw(Obstacle& obstacle);
}