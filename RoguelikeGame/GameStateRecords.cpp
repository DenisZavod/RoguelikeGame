#include "GameStateRecords.h"
//#include "Application.h"
#include "GameSettings.h"
#include "Math.h"
#include <assert.h>
#include <sstream>

namespace RoguelikeGame
{
	void GameStateRecordsData::Init()
	{
		assert(font.loadFromFile(SETTINGS.FONTS_PATH + "Roboto-Regular.ttf"));

		titleText.setString(L"Рекорды");
		titleText.setFont(font);
		titleText.setFillColor(sf::Color::Red);
		titleText.setCharacterSize(30);

		tableTexts.reserve(SETTINGS.MAX_RECORDS_TABLE_SIZE);

		//const Game& game = Application::Instance().GetGame();
		/*std::map<int, std::string> sortedRecordsTable;
		for (const auto& item : game.GetRecordsTable())
		{
			sortedRecordsTable[item.second] = item.first;
		}*/

		//auto it = sortedRecordsTable.rbegin();
		//for (int i = 0; i < SETTINGS.MAX_RECORDS_TABLE_SIZE && it != sortedRecordsTable.rend(); ++i, ++it)
		//{
		//	tableTexts.emplace_back(); // Create text in place
		//	sf::Text& text = tableTexts.back();

		//	// We can use streams for writing into string and reading from it
		//	std::stringstream sstream;
		//	sstream << i + 1 << ". " << it->second << ": " << it->first;
		//	text.setString(sstream.str());
		//	text.setFont(font);
		//	text.setFillColor(sf::Color::White);
		//	text.setCharacterSize(24);
		//}
	}

	void GameStateRecordsData::HandleWindowEvent(const sf::Event& event)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				//Application::Instance().GetGame().PopState();
			}
		}
	}

	void GameStateRecordsData::Update(float deltaTime)
	{

	}

	void GameStateRecordsData::Draw(sf::RenderWindow& window)
	{
		sf::Vector2f viewSize = window.getView().getSize();

		titleText.setOrigin(GetTextOrigin(titleText, { 0.5f, 0.f }));
		titleText.setPosition(window.getSize().x / 2.f, 100.0f);
		window.draw(titleText);

		// We need to create new vector here as DrawItemsList needs vector of pointers
		std::vector<sf::Text*> textsList;
		textsList.reserve(tableTexts.size());

		for (auto& text : tableTexts)
		{
			textsList.push_back(&text);
		}

		for (int i = 0; i < SETTINGS.MAX_RECORDS_TABLE_SIZE; ++i)
		{
			tableTexts[i].setOrigin(GetTextOrigin(tableTexts[i], { 0.5f, 0.f }));
			tableTexts[i].setPosition(window.getSize().x / 2.f, 150 + i * 50.f);

			window.draw(tableTexts[i]);
		}
	}
}
