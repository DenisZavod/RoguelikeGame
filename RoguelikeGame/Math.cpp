#include "Math.h"
#include <cstdlib>
#include <SFML/Graphics.hpp>

namespace RoguelikeGame
{
	Position2D GetRandomPositionInScreen(float screenWidth, float screenHeight)
	{
		Position2D result;
		result.X = rand() / (float)RAND_MAX * screenWidth;
		result.Y = rand() / (float)RAND_MAX * screenHeight;
		return result;
	}

	bool IsRectanglesCollide(Position2D rect1Position, Vector2D rect1Size,
		Position2D rect2Position, Vector2D rect2Size)
	{
		float dx = (float)fabs(rect1Position.X - rect2Position.X);
		float dy = (float)fabs(rect1Position.Y - rect2Position.Y);

		return (dx <= (rect1Size.X + rect2Size.X) / 2.0f &&
			dy <= (rect1Size.Y + rect2Size.Y) / 2.0f);
	}

	bool IsCirclesCollide(Position2D circle1Position, float circle1Radius,
		Position2D circle2Position, float circle2Radius)
	{
		float squareDistance = (circle1Position.X - circle2Position.X) * (circle1Position.X - circle2Position.X) +
			(circle1Position.Y - circle2Position.Y) * (circle1Position.Y - circle2Position.Y);
		float squareRadisuSum = (circle1Radius + circle2Radius) * (circle1Radius + circle2Radius) / 4;

		return squareDistance <= squareRadisuSum;
	}

	sf::Vector2f GetTextOrigin(const sf::Text& text, const sf::Vector2f& relativePosition)
	{
		sf::FloatRect textSize = text.getLocalBounds();
		return {
			(textSize.left + textSize.width) * relativePosition.x,
			(textSize.top + textSize.height) * relativePosition.y,
		};
	}

	void DrawItemsList(sf::RenderWindow& window, const std::vector<sf::Text*>& items, float spacing, Orientation orientation, Alignment alignment, const sf::Vector2f& position, const sf::Vector2f& origin)
	{
		sf::FloatRect totalRect;
		// Calculate total height/width of all texts
		for (auto it = items.begin(); it != items.end(); ++it)
		{
			sf::FloatRect itemRect = (*it)->getGlobalBounds();

			if (orientation == Orientation::Horizontal)
			{
				totalRect.width += itemRect.width + (it != items.end() - 1 ? spacing : 0.f);
				totalRect.height = std::max(totalRect.height, itemRect.height);
			}
			else
			{
				totalRect.width = std::max(totalRect.width, itemRect.width);
				totalRect.height += itemRect.height + (it != items.end() - 1 ? spacing : 0.f);
			}
		}

		totalRect.left = position.x - origin.x * totalRect.width;
		totalRect.top = position.y - origin.y * totalRect.height;
		sf::Vector2f currentPos = { totalRect.left, totalRect.top };

		for (auto it = items.begin(); it != items.end(); ++it)
		{
			sf::FloatRect itemRect = (*it)->getGlobalBounds();
			sf::Vector2f itemOrigin;

			if (orientation == Orientation::Horizontal)
			{
				itemOrigin.y = alignment == Alignment::Min ? 0.f : alignment == Alignment::Middle ? 0.5f : 1.f;
				itemOrigin.x = 0.f;
				currentPos.y = totalRect.top + itemOrigin.y * totalRect.height;
			}
			else
			{
				itemOrigin.y = 0.f;
				itemOrigin.x = alignment == Alignment::Min ? 0.f : alignment == Alignment::Middle ? 0.5f : 1.f;
				currentPos.x = totalRect.left + itemOrigin.x * totalRect.width;
			}

			(*it)->setOrigin(GetTextOrigin(**it, itemOrigin));
			(*it)->setPosition(currentPos);
			window.draw(**it);

			if (orientation == Orientation::Horizontal)
			{
				currentPos.x += itemRect.width + spacing;
			}
			else
			{
				currentPos.y += itemRect.height + spacing;
			}
		}
	}
}