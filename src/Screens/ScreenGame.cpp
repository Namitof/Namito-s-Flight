#include "ScreenGame.h"

#include "Objects/Player.h"
#include "Objects/Obstacle.h"
#include "Objects/CollisionManager.h"

namespace Game
{
	//Constantes
	const float INITIAL_GRAVITY = 800.0f;

	//Recursos
	static Player::Player player;
	static Obtacle::Obstacle obstacle;

	static float gravity;

	void Init(int screenWidth, int screenHeight)
	{
		Player::Init(player, screenWidth, screenHeight);
		Obtacle::Init(obstacle, screenWidth, screenHeight);

		gravity = INITIAL_GRAVITY;
	}

	void Update(float deltaTime, int screenHeight, bool& isGameOver)
	{
		Player::Update(player, deltaTime, gravity);
		Obtacle::Update(obstacle, deltaTime);

		ColisionManager::CheckColisions(player, obstacle, screenHeight);

		if (!player.isAlive)
		{
			isGameOver = true;
		}
		else
		{
			isGameOver = false;
		}
	}

	void Draw()
	{
		Player::Draw(player);
		Obtacle::Draw(obstacle);
	}
}