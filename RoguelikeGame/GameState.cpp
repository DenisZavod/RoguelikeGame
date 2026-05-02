#include "GameState.h"
#include "GameStateMainMenu.h"
#include "GameStatePlaying.h"
#include "GameStateGameOver.h"
#include "GameStateExitDialog.h"
#include "GameStateRecords.h"
#include "GameStateGameWin.h"

#include <assert.h>

namespace RoguelikeGame
{
	GameState::GameState(GameStateType type, bool isExclusivelyVisible)
		: type(type)
		, isExclusivelyVisible(isExclusivelyVisible)
	{
		switch (type)
		{
		case GameStateType::MainMenu:
		{
			data = std::make_shared<GameStateMainMenuData>();
			break;
		}
		case GameStateType::Playing:
		{
			data = std::make_shared<GameStatePlayingData>();
			break;
		}
		case GameStateType::GameOver:
		{
			data = std::make_shared<GameStateGameOverData>();
			break;
		}
		case GameStateType::ExitDialog:
		{
			data = std::make_shared<GameStateExitDialogData>();
			break;
		}
		case GameStateType::Records:
		{
			data = std::make_shared<GameStateRecordsData>();
			break;
		}
		case GameStateType::GameWin:
		{
			data = std::make_shared<GameStateGameWinData>();
			break;
		}
		default:
			assert(false); // We want to know if we forgot to implement new game state
			break;
		}
		if(data)
		{
			data->Init();
		}
	}

	GameState::~GameState()
	{
		if (data) 
		{
			data = nullptr;
		}
	}

	void GameState::Update(float deltaTime)
	{
		data->Update(deltaTime);
	}

	void GameState::Draw(sf::RenderWindow& window)
	{
		data->Draw(window);
	}

	void GameState::HandleWindowEvent(sf::Event& event)
	{
		data->HandleWindowEvent(event);
	}
}