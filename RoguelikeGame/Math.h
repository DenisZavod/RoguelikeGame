#pragma once

#include <SFML/Graphics.hpp>

namespace RoguelikeGame
{
	struct Vector2D
	{
		float X = 0.0f;
		float Y = 0.0f;
	};

	typedef Vector2D Position2D;

	Position2D GetRandomPositionInScreen(float screenWidth, float screenHeight);

	bool IsRectanglesCollide(Position2D rect1Position, Vector2D rect1Size,
		Position2D rect2Position, Vector2D rect2Size);

	bool IsCirclesCollide(Position2D circle1Position, float circle1Radius,
		Position2D circle2Position, float circle2Radius);

	sf::Vector2f GetTextOrigin(const sf::Text& text, const sf::Vector2f& relativePosition);

	// Helper method for organizing text items
	enum class Orientation
	{
		Horizontal,
		Vertical
	};

	enum class Alignment
	{
		Min, // Left or Top
		Middle,
		Max // Right or Bottom
	};

	void DrawItemsList(sf::RenderWindow& window, const std::vector<sf::Text*>& items, float spacing, Orientation orientation, Alignment alignment, const sf::Vector2f& position, const sf::Vector2f& origin);

}