#include "ScreenGame.h"

#include "Objects/Player.h"
#include "Objects/CollisionManager.h"

namespace Game
{
	//Recursos
	static Player::Player player;


	void Init(int screenWidth, int screenHeight)
	{
		Player::Init(player, screenWidth, screenHeight);
	}

	void Update(float deltaTime, int screenWidth, int screenHeight)
	{
		Player::Update(player, deltaTime);

		ColisionManager::CheckColisions(player, screenWidth, screenHeight);
	}

	void Draw()
	{
		Player::Draw(player);
	}
}