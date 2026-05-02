#include "GameStateExitDialog.h"
//#include "Application.h"
#include "Math.h"
#include <assert.h>

namespace RoguelikeGame
{
	void GameStateExitDialogData::Init()
	{
		//assert(font.loadFromFile(SETTINGS.FONTS_PATH + "Roboto-Regular.ttf"));

		hintText.setString(L"Вы уверены что хотите завершить эту игру? Enter - Да, Esc - Нет");
		hintText.setFont(font);
		hintText.setCharacterSize(24);
		hintText.setFillColor(sf::Color::White);
		hintText.setOrigin(GetTextOrigin(hintText, { 0.5f, 0.5f }));

		background.setFillColor(sf::Color(0, 0, 0, 128)); // Semi-transparent black
	}

	void GameStateExitDialogData::HandleWindowEvent(const sf::Event& event)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				//Application::Instance().GetGame().PopState();
			}
			else if (event.key.code == sf::Keyboard::Enter)
			{
				//Application::Instance().GetGame().ExitGame();
			}
		}
	}

	void GameStateExitDialogData::Update(float deltaTime)
	{

	}

	void GameStateExitDialogData::Draw(sf::RenderWindow& window)
	{
		sf::Vector2f windowSize = (sf::Vector2f)window.getSize();

		background.setSize(windowSize);
		window.draw(background);

		hintText.setPosition(windowSize / 2.f);
		window.draw(hintText);
	}
}