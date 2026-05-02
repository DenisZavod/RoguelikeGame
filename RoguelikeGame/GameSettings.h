#pragma once

#include <string>

namespace RoguelikeGame
{
	class GameWorld
	{
		private:

			GameWorld() = default;

		public:

			static GameWorld& Instance()
			{
				static GameWorld gameWorld;
				return gameWorld;
			}

			const std::string RESOURCES_PATH = "Resources/";
			const std::string TEXTURES_PATH = RESOURCES_PATH + "Textures/";
			const std::string FONTS_PATH = RESOURCES_PATH + "Fonts/";
			const std::string SOUNDS_PATH = RESOURCES_PATH + "Sounds/";
			const std::string LEVELS_CONFIG_PATH = RESOURCES_PATH + "levels.config";

			const unsigned int SCREEN_WIDTH = 800;
			const unsigned int SCREEN_HEIGHT = 600;
			const float TIME_PER_FRAME = 1.f / 60.f; // 60 fps

			const unsigned int PLATFORM_WIDTH = 50;
			const unsigned int PLATFORM_HEIGHT = 20;
			const unsigned int PLATFORM_PLAYER_WIDTH = 100;
			const float PLATFORM_SPEED = 300.f;

			const unsigned int BALL_SIZE = 20;
			const unsigned int BALL_SPEED = 400;
			const float BALL_ACCELERATION = 10.0f;

			const unsigned int BLOCKS_COUNT_ROWS = 5;
			const unsigned int BLOCKS_COUNT_IN_ROW = 15;
			const unsigned int BLOCK_SHIFT = 6;
			const unsigned int BLOCK_WIDTH = (SCREEN_WIDTH - (BLOCKS_COUNT_IN_ROW + 1) * BLOCK_SHIFT) / BLOCKS_COUNT_IN_ROW;
			const unsigned int BLOCK_HEIGHT = 20;

			const int MAX_RECORDS_TABLE_SIZE = 5;
			const char* PLAYER_NAME = "Player"; // We need to define this constant in some SPP

			const std::string GAME_NAME = "RoguelikeGame";

			const float BREAK_DELAY = 0.2f;

			const unsigned int BONUS_SIZE = 30;
	};
}

#define SETTINGS GameWorld::Instance()