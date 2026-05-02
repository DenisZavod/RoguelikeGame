#include "Game.h"
#include <cassert>
#include <algorithm>
#include "GameStatePlaying.h"


namespace RoguelikeGame
{
	Game::Game()
	{
		// Generate fake records table
		recordsTable =
		{
			{"John", rand() % 1000},
			{"Jane", rand() % 1000 },
			{"Alice", rand() % 1000 },
			{"Bob", rand() % 1000 },
			{"Clementine", rand() % 1000 },
		};

		stateChangeType = GameStateChangeType::None;
		pendingStateType = GameStateType::None;
		pendingStateIsExclusivelyVisible = false;

		SwitchStateTo(GameStateType::MainMenu);
	}

	Game::~Game()
	{
		Shutdown();
	}

	void Game::UpdateGame(float deltaTime, sf::RenderWindow& window)
	{
		HandleWindowEvents(window);
		if (Update(deltaTime))
		{
			// Draw everything here
			// Clear the window first
			window.clear();

			Draw(window);

			// End the current frame, display window contents on screen
			window.display();
		}
		else
		{
			window.close();
		}
	}

	void Game::HandleWindowEvents(sf::RenderWindow& window)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window if close button or Escape key pressed
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (stateStack.size() > 0)
			{
				stateStack.back().HandleWindowEvent(event);
			}
		}
	}

	bool Game::Update(float deltaTime)
	{
		if (stateChangeType == GameStateChangeType::Switch)
		{
			// Shutdown all game states
			while (stateStack.size() > 0)
			{
				stateStack.pop_back();
			}
		}
		else if (stateChangeType == GameStateChangeType::Pop)
		{
			// Shutdown only current game state
			if (stateStack.size() > 0)
			{
				stateStack.pop_back();
			}
		}

		// Initialize new game state if needed
		if (pendingStateType != GameStateType::None)
		{
			stateStack.push_back(GameState(pendingStateType, pendingStateIsExclusivelyVisible));
		}

		stateChangeType = GameStateChangeType::None;
		pendingStateType = GameStateType::None;
		pendingStateIsExclusivelyVisible = false;

		if (stateStack.size() > 0)
		{
			stateStack.back().Update(deltaTime);
			return true;
		}

		return false;
	}

	void Game::Draw(sf::RenderWindow& window)
	{
		if (stateStack.size() > 0)
		{
			std::vector<GameState*> visibleGameStates;
			for (auto it = stateStack.rbegin(); it != stateStack.rend(); ++it)
			{
				visibleGameStates.push_back(&(*it));
				if (it->IsExclusivelyVisible())
				{
					break;
				}
			}

			for (auto it = visibleGameStates.rbegin(); it != visibleGameStates.rend(); ++it)
			{
				(*it)->Draw(window);
			}
		}
	}

	void Game::Shutdown()
	{
		// Shutdown all game states
		while (stateStack.size() > 0)
		{
			stateStack.pop_back();
		}

		stateChangeType = GameStateChangeType::None;
		pendingStateType = GameStateType::None;
		pendingStateIsExclusivelyVisible = false;
	}

	void Game::PushState(GameStateType stateType, bool isExclusivelyVisible)
	{
		pendingStateType = stateType;
		pendingStateIsExclusivelyVisible = isExclusivelyVisible;
		stateChangeType = GameStateChangeType::Push;
	}

	void Game::PopState()
	{
		pendingStateType = GameStateType::None;
		pendingStateIsExclusivelyVisible = false;
		stateChangeType = GameStateChangeType::Pop;
	}

	void Game::SwitchStateTo(GameStateType newState)
	{
		pendingStateType = newState;
		pendingStateIsExclusivelyVisible = false;
		stateChangeType = GameStateChangeType::Switch;
	}

	void Game::SetOption(GameOptions option, bool value)
	{
		if (value) 
		{
			options = (GameOptions)((std::uint8_t)options | (std::uint8_t)option);
		}
		else 
		{
			options = (GameOptions)((std::uint8_t)options & ~(std::uint8_t)option);
		}
	}

	void Game::SetDifficultyLevel(DifficultyLevel level)
	{
		difficulty = level;
	}

	bool Game::IsEnableOptions(GameOptions option)
	{
		const bool isEnable = ((std::uint8_t)options & (std::uint8_t)option) != (std::uint8_t)GameOptions::Empty;
		return isEnable;
	}

	bool Game::IsEnableDifficultyLevel(DifficultyLevel level)
	{
		const bool isEnable = difficulty == level;
		return isEnable;
	}

	int Game::GetRecordByPlayerId(const std::string& playerId) const
	{
		auto it = recordsTable.find(playerId);
		return it == recordsTable.end() ? 0 : it->second;
	}

	void Game::UpdateRecord(const std::string& playerId, int score)
	{
		recordsTable[playerId] = std::max(recordsTable[playerId], score);
	}

	void Game::ShowRecords()
	{
		PushState(GameStateType::Records, true);
	}

	void Game::QuitGame()
	{
		SwitchStateTo(GameStateType::None);
	}

	void Game::ExitGame()
	{
		SwitchStateTo(GameStateType::MainMenu);
	}

	void Game::StartGame()
	{
		SwitchStateTo(GameStateType::Playing);
	}

	void Game::PauseGame()
	{
		PushState(GameStateType::ExitDialog, false);
	}

	void Game::WinGame()
	{
		PushState(GameStateType::GameWin, false);
	}

	void Game::LooseGame()
	{
		PushState(GameStateType::GameOver, false);
	}

	void Game::LoadNextLevel()
	{
		assert(stateStack.back().GetType() == GameStateType::Playing);
		auto playingData = (stateStack.back().GetData<GameStatePlayingData>());
		playingData->LoadNextLevel();
	}
}