#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Menu.h"
#include "GameStateData.h"

namespace RoguelikeGame
{
	class Game;

	class GameStateMainMenuData : public GameStateData
	{
		public:

			void HandleWindowEvent(const sf::Event& event) override;
			void Init() override;
			void Update(float deltaTime) override;
			void Draw(sf::RenderWindow& window) override;

			

		private:

			void UpdateDifficultyMenuItems();

			MenuItem startGame;
			MenuItem difficulty;
			MenuItem options;
			MenuItem records;
			MenuItem exitGame;


			MenuItem difficultyEasy;
			MenuItem difficultyNormal;
			MenuItem difficultyHard;
			MenuItem difficultyInsane;
			MenuItem difficultyImpossible;

			MenuItem optionsSound;
			MenuItem optionsMusic;

			MenuItem mainMenu;
			MenuItem yesItem;
			MenuItem noItem;

			sf::Font font;
			Menu menu;

			sf::SoundBuffer soundBtnHoverBuffer;
			sf::Sound soundBtnHover;
	};
}

