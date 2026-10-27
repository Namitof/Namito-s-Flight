#include "ScreenGame.h"

#include "Objects/Player.h"

namespace Game
{
	//Recursos
	static Player::Player player;


	void Init(int screenWidth, int screenHeight)
	{
		Player::Init(player, screenWidth, screenHeight);
	}

	void Update(float deltaTime)
	{
		Player::Update(player, deltaTime);
	}

	void Draw()
	{
		Player::Draw(player);
	}
}