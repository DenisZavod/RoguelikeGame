#pragma once
#include "SFML/Graphics.hpp"

namespace RoguelikeGame
{
	class GameStateData
	{
		public:

			virtual ~GameStateData() = default;

			virtual void HandleWindowEvent(const sf::Event& event) = 0;
			virtual void Init() = 0;
			virtual void Update(float deltaTime) = 0;
			virtual void Draw(sf::RenderWindow& window) = 0;
	};
}