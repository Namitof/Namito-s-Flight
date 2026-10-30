#pragma once

namespace ScreenManager
{
	enum class Screens
	{
		None = 0,
		Menu,
		Play,
		Credits,
		Exit
	};

	void Run();
}