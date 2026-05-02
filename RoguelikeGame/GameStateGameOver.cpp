#include "GameStateGameOver.h"
//#include "Application.h"
#include "Math.h"
#include <assert.h>
#include <sstream>

namespace RoguelikeGame
{
	const char* PLAYER_NAME = "Player";

	void GameStateGameOverData::Init()
	{
		//assert(font.loadFromFile(SETTINGS.FONTS_PATH + "Roboto-Regular.ttf"));

		timeSinceGameOver = 0.f;

		gameOverText.setFont(font);
		gameOverText.setCharacterSize(48);
		gameOverText.setStyle(sf::Text::Bold);
		gameOverText.setFillColor(sf::Color::Red);
		gameOverText.setString(L"Вы проиграли");
		gameOverText.setOrigin(GetTextOrigin(gameOverText, { 0.5f, 0.5f }));

		hintText.setFont(font);
		hintText.setCharacterSize(24);
		hintText.setFillColor(sf::Color::White);
		hintText.setString(L"Нажмите Space для перезапуска");
		hintText.setOrigin(GetTextOrigin(hintText, { 0.5f, 1.f }));

		//recordsTableTexts.reserve(SETTINGS.MAX_RECORDS_TABLE_SIZE);

		/*std::multimap<int, std::string> sortedRecordsTable;
		Game& game = Application::Instance().GetGame();
		for (const auto& item : game.GetRecordsTable())
		{
			sortedRecordsTable.insert(std::make_pair(item.second, item.first));
		}*/

		//bool isPlayerInTable = false;
		//auto it = sortedRecordsTable.rbegin();
		//for (int i = 0; i < SETTINGS.MAX_RECORDS_TABLE_SIZE && it != sortedRecordsTable.rend(); ++i, ++it) // Note, we can do several actions in for action block
		//{
		//	recordsTableTexts.emplace_back(); // Create text in place
		//	sf::Text& text = recordsTableTexts.back();

		//	// We can use streams for writing into string and reading from it
		//	std::stringstream sstream;
		//	sstream << i + 1 << ". " << it->second << ": " << it->first;
		//	text.setString(sstream.str());
		//	text.setFont(font);
		//	text.setCharacterSize(24);
		//	if (it->second == PLAYER_NAME)
		//	{
		//		text.setFillColor(sf::Color::Green);
		//		isPlayerInTable = true;
		//	}
		//	else
		//	{
		//		text.setFillColor(sf::Color::White);
		//	}
		//}

		// If snake is not in table, replace last element with him
		//if (!isPlayerInTable)
		//{
		//	/*sf::Text& text = recordsTableTexts.back();
		//	std::stringstream sstream;
		//	int playerScores = game.GetRecordByPlayerId(PLAYER_NAME);
		//	sstream << SETTINGS.MAX_RECORDS_TABLE_SIZE << ". " << PLAYER_NAME << ": " << playerScores;
		//	text.setString(sstream.str());
		//	text.setFillColor(sf::Color::Green);*/
		//}
	}

	void GameStateGameOverData::HandleWindowEvent(const sf::Event& event)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			/*if (event.key.code == sf::Keyboard::Space)
			{
				Application::Instance().GetGame().StartGame();
			}
			else if (event.key.code == sf::Keyboard::Escape)
			{
				Application::Instance().GetGame().ExitGame();
			}*/
		}
	}

	void GameStateGameOverData::Update(float deltaTime)
	{
		timeSinceGameOver += deltaTime;

		sf::Color gameOverTextColor = (int)timeSinceGameOver % 2 ? sf::Color::Red : sf::Color::Yellow;
		gameOverText.setFillColor(gameOverTextColor);
	}

	void GameStateGameOverData::Draw(sf::RenderWindow& window)
	{
		sf::Vector2f viewSize = window.getView().getSize();

		gameOverText.setPosition(viewSize.x / 2.f, viewSize.y / 2.f - 150.f);
		window.draw(gameOverText);

		// We need to create new vector here as DrawItemsList needs vector of pointers
		std::vector<sf::Text*> textsList;
		textsList.reserve(recordsTableTexts.size());
		for (auto& text : recordsTableTexts)
		{
			textsList.push_back(&text);
		}

		/*for (int i = 0; i < SETTINGS.MAX_RECORDS_TABLE_SIZE; ++i)
		{
			recordsTableTexts[i].setOrigin(GetTextOrigin(recordsTableTexts[i], { 0.5f, 0.f }));
			recordsTableTexts[i].setPosition(window.getSize().x / 2.f, 200 + i * 50.f);

			window.draw(recordsTableTexts[i]);
		}*/
		hintText.setPosition(viewSize.x / 2.f, viewSize.y - 10.f);
		window.draw(hintText);
	}
}
