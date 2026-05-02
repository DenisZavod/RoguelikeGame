#pragma once

#include <SFML/Graphics.hpp>
#include "GameStateData.h"

namespace RoguelikeGame
{
	class GameStateExitDialogData : public GameStateData
	{
		public:

			void HandleWindowEvent(const sf::Event& event) override;
			void Init() override;
			void Update(float deltaTime) override;
			void Draw(sf::RenderWindow& window) override;

		private:

			sf::Font font;

			sf::RectangleShape background;
			sf::Text hintText;
	};
}