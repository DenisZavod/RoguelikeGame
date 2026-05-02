#include "GameStateMainMenu.h"
//#include "Application.h"
#include <assert.h>

namespace RoguelikeGame
{
	void GameStateMainMenuData::Init()
	{
		//assert(font.loadFromFile(SETTINGS.FONTS_PATH + "Roboto-Regular.ttf"));

		//assert(soundBtnHoverBuffer.loadFromFile(SETTINGS.SOUNDS_PATH + "\\menu-hover.wav"));

		soundBtnHover.setBuffer(soundBtnHoverBuffer);

		auto setTextParameters = [&](sf::Text& itemText, const std::wstring& title, int fontSize, sf::Color color = sf::Color::Transparent)
			{
				itemText.setString(title);
				itemText.setFont(font);
				itemText.setCharacterSize(fontSize);
				if (color != sf::Color::Transparent)
				{
					itemText.setFillColor(color);
				}
			};

		//Game& game = Application::Instance().GetGame();

		/*setTextParameters(startGame.text, L"Начать игру", 24);
		startGame.onPressCallback = [](MenuItem&)
			{
				Application::Instance().GetGame().StartGame();
			};
		
		const bool isEasy = game.IsEnableDifficultyLevel(DifficultyLevel::Easy);
		setTextParameters(difficultyEasy.text, L"Лёгкий: " + std::wstring(isEasy ? L"Вкл" : L"Выкл"), 24);
		difficultyEasy.onPressCallback = [this](MenuItem& item)
			{
				Game& game = Application::Instance().GetGame();
				bool newEasy = !game.IsEnableDifficultyLevel(DifficultyLevel::Easy);
				game.SetDifficultyLevel(DifficultyLevel::Easy);
				item.text.setString(L"Лёгкий: " + std::wstring(newEasy ? L"Вкл" : L"Выкл"));
				UpdateDifficultyMenuItems();
				
			};

		const bool isNormal = game.IsEnableDifficultyLevel(DifficultyLevel::Normal);
		setTextParameters(difficultyNormal.text, L"Нормальный: " + std::wstring(isNormal ? L"Вкл" : L"Выкл"), 24);
		difficultyNormal.onPressCallback = [this](MenuItem& item)
			{
				Game& game = Application::Instance().GetGame();
				bool newNormal = !game.IsEnableDifficultyLevel(DifficultyLevel::Normal);
				game.SetDifficultyLevel(DifficultyLevel::Normal);
				item.text.setString(L"Нормальный: " + std::wstring(newNormal ? L"Вкл" : L"Выкл"));
				UpdateDifficultyMenuItems();
			};

		const bool isHard = game.IsEnableDifficultyLevel(DifficultyLevel::Hard);
		setTextParameters(difficultyHard.text, L"Сложный: " + std::wstring(isHard ? L"Вкл" : L"Выкл"), 24);
		difficultyHard.onPressCallback = [this](MenuItem& item)
			{
				Game& game = Application::Instance().GetGame();
				bool newHard = !game.IsEnableDifficultyLevel(DifficultyLevel::Hard);
				game.SetDifficultyLevel(DifficultyLevel::Hard);
				item.text.setString(L"Сложный: " + std::wstring(newHard ? L"Вкл" : L"Выкл"));
				UpdateDifficultyMenuItems();
			};

		const bool isInsane = game.IsEnableDifficultyLevel(DifficultyLevel::Insane);
		setTextParameters(difficultyInsane.text, L"Безумный: " + std::wstring(isInsane ? L"Вкл" : L"Выкл"), 24);
		difficultyInsane.onPressCallback = [this](MenuItem& item)
			{
				Game& game = Application::Instance().GetGame();
				bool newInsane = !game.IsEnableDifficultyLevel(DifficultyLevel::Insane);
				game.SetDifficultyLevel(DifficultyLevel::Insane);
				item.text.setString(L"Безумный: " + std::wstring(newInsane ? L"Вкл" : L"Выкл"));
				UpdateDifficultyMenuItems();
			};

		const bool isImpossible = game.IsEnableDifficultyLevel(DifficultyLevel::Impossible);
		setTextParameters(difficultyImpossible.text, L"Невозможный: " + std::wstring(isImpossible ? L"Вкл" : L"Выкл"), 24);
		difficultyImpossible.onPressCallback = [this](MenuItem& item)
			{
				Game& game = Application::Instance().GetGame();
				bool newImpossible = !game.IsEnableDifficultyLevel(DifficultyLevel::Impossible);
				game.SetDifficultyLevel(DifficultyLevel::Impossible);
				item.text.setString(L"Невозможный: " + std::wstring(newImpossible ? L"Вкл" : L"Выкл"));
				UpdateDifficultyMenuItems();
			};*/

		setTextParameters(difficulty.text, L"Уровень сложности", 24);
		setTextParameters(difficulty.hintText, L"Выберите уровень сложности", 48, sf::Color::Red);
		difficulty.childrenOrientation = Orientation::Vertical;
		difficulty.childrenAlignment = Alignment::Middle;
		difficulty.childrenSpacing = 10.f;
		difficulty.children.push_back(&difficultyEasy);
		difficulty.children.push_back(&difficultyNormal);
		difficulty.children.push_back(&difficultyHard);
		difficulty.children.push_back(&difficultyInsane);
		difficulty.children.push_back(&difficultyImpossible);
		
		/*const bool isSound = game.IsEnableOptions(GameOptions::Sound);
		setTextParameters(optionsSound.text, L"Звук: " + std::wstring(isSound ? L"Вкл" : L"Выкл"), 24);
		optionsSound.onPressCallback = [](MenuItem& item)
			{
				Game& game = Application::Instance().GetGame();
				bool newSound = !game.IsEnableOptions(GameOptions::Sound);
				game.SetOption(GameOptions::Sound, newSound);
				item.text.setString(L"Звук: " + std::wstring(newSound ? L"Вкл" : L"Выкл"));
			};

		const bool isMusic = game.IsEnableOptions(GameOptions::Music);
		setTextParameters(optionsMusic.text, L"Музыка: " + std::wstring(isMusic ? L"Вкл" : L"Выкл"), 24);
		optionsMusic.onPressCallback = [](MenuItem& item)
			{
				Game& game = Application::Instance().GetGame();
				bool newMusic = !game.IsEnableOptions(GameOptions::Music);
				game.SetOption(GameOptions::Music, newMusic);
				item.text.setString(L"Музыка: " + std::wstring(newMusic ? L"Вкл" : L"Выкл"));
			};*/
		
		setTextParameters(options.text, L"Настройки", 24);
		setTextParameters(options.hintText, L"Настройки", 48, sf::Color::Red);
		options.childrenOrientation = Orientation::Vertical;
		options.childrenAlignment = Alignment::Middle;
		options.childrenSpacing = 10.f;

		options.children.push_back(&optionsSound);
		options.children.push_back(&optionsMusic);
		
		/*setTextParameters(records.text, L"Таблица рекордов", 24);
		records.onPressCallback = [](MenuItem&)
			{
				Application::Instance().GetGame().ShowRecords();
			};
		
		setTextParameters(yesItem.text, L"Да", 24);
		yesItem.onPressCallback = [](MenuItem&) 
			{
				Application::Instance().GetGame().QuitGame();
			};*/

		setTextParameters(noItem.text, L"Нет", 24);
		noItem.onPressCallback = [&](MenuItem&)
			{
				menu.GoBack();
			};

		setTextParameters(exitGame.text, L"Выйти из игры", 24);

		setTextParameters(exitGame.hintText, L"Вы уверены?", 48, sf::Color::Red);
		exitGame.childrenOrientation = Orientation::Horizontal;
		exitGame.childrenAlignment = Alignment::Middle;
		exitGame.childrenSpacing = 10.f;
		exitGame.children.push_back(&yesItem);
		exitGame.children.push_back(&noItem);

		setTextParameters(mainMenu.hintText, L"Arcanoid", 48, sf::Color::Red);
		mainMenu.childrenOrientation = Orientation::Vertical;
		mainMenu.childrenAlignment = Alignment::Middle;
		mainMenu.childrenSpacing = 10.f;
		mainMenu.children.push_back(&startGame);
		mainMenu.children.push_back(&difficulty);
		mainMenu.children.push_back(&options);
		mainMenu.children.push_back(&records);
		mainMenu.children.push_back(&exitGame);

		menu.Init(mainMenu);
	}

	void GameStateMainMenuData::HandleWindowEvent(const sf::Event& event)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			/*if (event.key.code == sf::Keyboard::Escape)
			{
				menu.GoBack();
			}
			else if (event.key.code == sf::Keyboard::Enter)
			{
				if (Application::Instance().GetGame().IsEnableOptions(GameOptions::Sound))
				{
					soundBtnHover.play();
				}
				menu.PressOnSelectedItem();
			}*/

			Orientation orientation = menu.GetCurrentContext().childrenOrientation;
			if (orientation == Orientation::Vertical && event.key.code == sf::Keyboard::Up ||
				orientation == Orientation::Horizontal && event.key.code == sf::Keyboard::Left)
			{
				menu.SwitchToPreviousMenuItem();
			}
			else if (orientation == Orientation::Vertical && event.key.code == sf::Keyboard::Down ||
				orientation == Orientation::Horizontal && event.key.code == sf::Keyboard::Right)
			{
				menu.SwitchToNextMenuItem();
			}
		}
	}

	void GameStateMainMenuData::Update(float deltaTime)
	{
		
	}

	void GameStateMainMenuData::UpdateDifficultyMenuItems()
	{
		/*Game& game = Application::Instance().GetGame();

		const bool isEasy = game.IsEnableDifficultyLevel(DifficultyLevel::Easy);
		difficultyEasy.text.setString(L"Лёгкий: " + std::wstring(isEasy ? L"Вкл" : L"Выкл"));

		const bool isNormal = game.IsEnableDifficultyLevel(DifficultyLevel::Normal);
		difficultyNormal.text.setString(L"Нормальный: " + std::wstring(isNormal ? L"Вкл" : L"Выкл"));

		const bool isHard = game.IsEnableDifficultyLevel(DifficultyLevel::Hard);
		difficultyHard.text.setString(L"Сложный: " + std::wstring(isHard ? L"Вкл" : L"Выкл"));

		const bool isInsane = game.IsEnableDifficultyLevel(DifficultyLevel::Insane);
		difficultyInsane.text.setString(L"Безумный: " + std::wstring(isInsane ? L"Вкл" : L"Выкл"));

		const bool isImpossible = game.IsEnableDifficultyLevel(DifficultyLevel::Impossible);
		difficultyImpossible.text.setString(L"Невозможный: " + std::wstring(isImpossible ? L"Вкл" : L"Выкл"));*/
		
	}

	void GameStateMainMenuData::Draw(sf::RenderWindow& window)
	{
		sf::Vector2f viewSize = (sf::Vector2f)window.getSize();

		sf::Text* hintText = &menu.GetCurrentContext().hintText;
		hintText->setOrigin(GetTextOrigin(*hintText, { 0.5f, 0.f }));
		hintText->setPosition(viewSize.x / 2.f, 150.f);
		window.draw(*hintText);

		menu.Draw(window, viewSize / 2.f, { 0.5f, 0.f });
	}
}