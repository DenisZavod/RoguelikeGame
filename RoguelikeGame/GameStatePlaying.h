#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
//#include "Ball.h"
//#include "Platform.h"
#include "GameBonus.h"
#include "GameStateData.h"
//#include "BlockFactory.h"
#include "LevelLoader.h"
#include "IObserver.h"

#include <unordered_map>

namespace RoguelikeGame
{
	class Game;
	//class Block;
	//class BlockFactory;

	class GameStatePlayingData : public GameStateData, public IObserver, public std::enable_shared_from_this<GameStatePlayingData>
	{
		public:

			void HandleWindowEvent(const sf::Event& event) override;
			void Init() override;
			void Update(float deltaTime) override;
			void Draw(sf::RenderWindow& window) override;

			void Notify(std::shared_ptr<IObservable> observable) override;
			void LoadNextLevel();

			void DifficultyLevelState();

		private:

			void createBlocks();
			void GetBallInverse(const sf::Vector2f& ballPos, const sf::FloatRect& blockRect, bool& needInverseDirX,
				bool& needInverseDirY);

			//Resources
			sf::Texture platformTexture;
			sf::Texture ballTexture;

			sf::SoundBuffer soundAppleEatBuffer;
			sf::SoundBuffer soundDeathBuffer;
			sf::SoundBuffer soundBackgroundBuffer;

			//Game data
			//std::vector<std::shared_ptr<GameObject>> gameObjects;
			//std::vector<std::shared_ptr<Block>> blocks;
			std::vector<std::shared_ptr<GameBonus>> bonuses;
			std::vector<std::shared_ptr<GameBonus>> activeBonuses;

			int score = 0;
			int lives = 1;

			// UI data
			sf::Font font;
			sf::Text scoreText;
			sf::Text inputHintText;
			sf::RectangleShape background;
			sf::Text livesText;

			//Sound
			sf::Sound soundAppleEat;
			sf::Sound soundDeath;
			sf::Sound soundBackground;

			//Blocks creator
			//std::unordered_map<BlockType, std::unique_ptr<BlockFactory>> factories;
			int breackableBlocksCount = 0;

			//Levels
			LevelLoader levelLoader;
			int currentLevel = 0;
	};
}

