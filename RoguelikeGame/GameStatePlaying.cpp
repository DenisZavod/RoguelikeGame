#include "GameStatePlaying.h"
//#include "Application.h"
//#include "Block.h"
#include "Game.h"
#include "Math.h"

#include "assert.h"
#include <sstream>

namespace RoguelikeGame
{
	void GameStatePlayingData::Init()
	{
		// Init game resources (terminate if error)
		assert(font.loadFromFile(SETTINGS.FONTS_PATH + "Roboto-Regular.ttf"));

		assert(soundAppleEatBuffer.loadFromFile(SETTINGS.SOUNDS_PATH + "\\AppleEat.wav"));
		assert(soundDeathBuffer.loadFromFile(SETTINGS.SOUNDS_PATH + "\\GameOver.wav"));
		assert(soundBackgroundBuffer.loadFromFile(SETTINGS.SOUNDS_PATH + "\\Background.wav"));

		//factoriesInit
		//factories.emplace(BlockType::Simple, std::make_unique<SimpleBlockFactory>());
		//factories.emplace(BlockType::ThreeHit, std::make_unique<ThreeHitBlockFactory>());
		//factories.emplace(BlockType::Unbreackable, std::make_unique<UnbreackableBlockFactory>());

		// Init background
		background.setSize(sf::Vector2f(static_cast<float>(SETTINGS.SCREEN_WIDTH), static_cast<float>(SETTINGS.SCREEN_HEIGHT)));
		background.setPosition(0.f, 0.f);
		background.setFillColor(sf::Color(0, 0, 0));

		scoreText.setFont(font);
		scoreText.setCharacterSize(24);
		scoreText.setFillColor(sf::Color::White);

		inputHintText.setFont(font);
		inputHintText.setCharacterSize(16);
		inputHintText.setFillColor(sf::Color::White);
		inputHintText.setString(L"Используйте клавишы A D для перемещения, ESC для выхода");
		inputHintText.setOrigin(GetTextOrigin(inputHintText, { 1.f, 0.f }));

		//auto platform = std::make_shared<Platform>(sf::Vector2f({ SETTINGS.SCREEN_WIDTH / 2.f, SETTINGS.SCREEN_HEIGHT - SETTINGS.PLATFORM_HEIGHT / 2.f }));
		//gameObjects.emplace_back(platform);
		//auto ball = std::make_shared<Ball>(sf::Vector2f({ SETTINGS.SCREEN_WIDTH / 2.f, SETTINGS.SCREEN_HEIGHT - SETTINGS.PLATFORM_HEIGHT - SETTINGS.BALL_SIZE / 2.f }));
		//ball->AddObserver(weak_from_this());
		//gameObjects.emplace_back(ball);

		DifficultyLevelState();
		createBlocks();

		soundBackground.setBuffer(soundBackgroundBuffer);
		/*if (Application::Instance().GetGame().IsEnableOptions(GameOptions::Music))
		{
			soundBackground.setLoop(true);
			soundBackground.play();
		}*/
		soundAppleEat.setBuffer(soundAppleEatBuffer);
		soundDeath.setBuffer(soundDeathBuffer);
	}

	void GameStatePlayingData::DifficultyLevelState()
	{/*
		Game& game = Application::Instance().GetGame();
		auto platform = std::dynamic_pointer_cast<Platform>(gameObjects[0]);
		auto ball = std::dynamic_pointer_cast<Ball>(gameObjects[1]);*/

		/*if (game.IsEnableDifficultyLevel(DifficultyLevel::Easy))
		{
			platform->SetWidth(1.5f);
			ball->SetMultiplySpeed(0.8f);
		}
		else if (game.IsEnableDifficultyLevel(DifficultyLevel::Normal))
		{
			platform->SetWidth(1.f);
			ball->SetMultiplySpeed(1.f);
		}
		else if (game.IsEnableDifficultyLevel(DifficultyLevel::Hard))
		{
			platform->SetWidth(0.8f);
			ball->SetMultiplySpeed(1.2f);
		}
		else if (game.IsEnableDifficultyLevel(DifficultyLevel::Insane))
		{
			platform->SetWidth(0.6f);
			ball->SetMultiplySpeed(1.4f);
		}
		else if (game.IsEnableDifficultyLevel(DifficultyLevel::Impossible))
		{
			platform->SetWidth(0.4f);
			ball->SetMultiplySpeed(1.6f);
		}*/
	}

	void GameStatePlayingData::HandleWindowEvent(const sf::Event& event)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				//Application::Instance().GetGame().PauseGame();
			}
		}
	}

	void GameStatePlayingData::Update(float deltaTime)
	{
		static auto updateFunctor = [deltaTime](auto obj) { obj->Update(deltaTime); };

		/*std::for_each(gameObjects.begin(), gameObjects.end(), updateFunctor);
		std::for_each(blocks.begin(), blocks.end(), updateFunctor);
		std::for_each(bonuses.begin(), bonuses.end(), updateFunctor);

		std::shared_ptr <Platform> platform = std::dynamic_pointer_cast<Platform>(gameObjects[0]);
		std::shared_ptr<Ball> ball = std::dynamic_pointer_cast<Ball>(gameObjects[1]);

		const bool isCollision = platform->CheckCollision(ball);*/

		bool needInverseDirX = false;
		bool needInverseDirY = false;
		bool hasBrokeOneBlock = false;

		//remove-erase idiom
		/*blocks.erase(
			std::remove_if(blocks.begin(), blocks.end(),
				[ball, &hasBrokeOneBlock, &needInverseDirX, &needInverseDirY, this](auto block) 
				{
					if ((!hasBrokeOneBlock) && block->CheckCollision(ball)) 
					{
						hasBrokeOneBlock = true;
						const auto ballPos = ball->GetPosition();
						const auto blockRect = block->GetRect();

						GetBallInverse(ballPos, blockRect, needInverseDirX, needInverseDirY);

						soundAppleEat.play();

						if (block->isHit == true)
						{
							score += block->ScoreValue;

							if ((rand() % 100) < 10)
							{
								BonusType type = static_cast<BonusType>(rand() % static_cast<int>(BonusType::Count));
								auto bonus = std::make_shared<GameBonus>(ballPos, type);
								bonus->AddObserver(weak_from_this());
								bonuses.emplace_back(bonus);
							}
						}
					}
					return block->IsBroken();
				}),
			blocks.end()
		);*/

		scoreText.setString(L"Счёт: " + std::to_wstring(score));
		
		/*if (needInverseDirX) 
		{
			ball->InvertDirectionX();
		}
		if (needInverseDirY) 
		{
			ball->InvertDirectionY();
		}*/

		//for (auto it = bonuses.begin(); it != bonuses.end(); )
		//{
		//	auto& bonus = *it;
		//	bonus->Update(deltaTime);

		//	// Проверка столкновения с платформой
		//	if (bonus->GetRect().intersects(platform->GetRect()))
		//	{
		//		if(BonusType::ExtraLife == bonus->GetType())
		//		{
		//			lives++;
		//		}

		//		bonus->OnCollect(*platform, *ball);
		//		activeBonuses.emplace_back(bonus);
		//		it = bonuses.erase(it); // удаляем бонус
		//		 
		//	}
		//	// Проверка выхода за пределы экрана
		//	else if (bonus->GetPosition().y > SETTINGS.SCREEN_HEIGHT) 
		//	{
		//		it = bonuses.erase(it);
		//	}
		//	else
		//	{
		//		++it;
		//	}
		//}

		// Деактивация бонусов по таймеру:
		/*for (auto it = activeBonuses.begin(); it != activeBonuses.end(); )
		{
			auto& bonus = *it;
			bonus->Update(deltaTime);

			if (!bonus->IsActive()) 
			{
				bonus->OnEffectEnd(*platform, *ball);
				it = activeBonuses.erase(it);
			}
			else 
			{
				++it;
			}
		}*/
	}

	void GameStatePlayingData::LoadNextLevel()
	{
		/*if (currentLevel > levelLoader.GetLevelCount() - 1)
		{
			Game& game = Application::Instance().GetGame();
			game.WinGame();
		}
		else
		{
			std::shared_ptr <Platform> platform = std::dynamic_pointer_cast<Platform>(gameObjects[0]);
			std::shared_ptr<Ball> ball = std::dynamic_pointer_cast<Ball>(gameObjects[1]);
			platform->restart();
			ball->restart();

			blocks.clear();
			++currentLevel;
			createBlocks();
		}*/
	}

	void GameStatePlayingData::Draw(sf::RenderWindow& window)
	{
		// Draw background
		window.draw(background);

		static auto drawFunc = [&window](auto block) { block->Draw(window); };

		// Draw game objects
		/*std::for_each(gameObjects.begin(), gameObjects.end(), drawFunc);
		std::for_each(blocks.begin(), blocks.end(), drawFunc);
		std::for_each(bonuses.begin(), bonuses.end(), drawFunc);*/

		scoreText.setOrigin(GetTextOrigin(scoreText, { 0.f, 0.f }));
		scoreText.setPosition(10.f, 10.f);
		window.draw(scoreText);

		sf::Vector2f viewSize = window.getView().getSize();
		inputHintText.setPosition(viewSize.x - 10.f, 10.f);
		window.draw(inputHintText);

		livesText.setFont(font);
		livesText.setCharacterSize(24);
		livesText.setFillColor(sf::Color::White);
		livesText.setString(L"Жизни: " + std::to_wstring(lives));
		livesText.setPosition(10.f, 40.f);
		window.draw(livesText);
	}

	void GameStatePlayingData::createBlocks()
	{
		/*for (const auto& pair : factories)
		{
			pair.second->ClearCounter();
		}
		auto self = weak_from_this();

		auto level = levelLoader.GetLevel(currentLevel);

		for (auto pairPosBlockTYpe : level.m_blocks)
		{
			auto blockType = pairPosBlockTYpe.second;
			sf::Vector2i pos = pairPosBlockTYpe.first;

			sf::Vector2f position{
				(float)(SETTINGS.BLOCK_SHIFT + SETTINGS.BLOCK_WIDTH / 2.f + pos.x * (SETTINGS.BLOCK_WIDTH + SETTINGS.BLOCK_SHIFT))
				, (float)pos.y * SETTINGS.BLOCK_HEIGHT
			};


			blocks.emplace_back(factories.at(blockType)->CreateBlock(position));
			blocks.back()->AddObserver(self);
		}

		for (const auto& pair : factories)
		{
			breackableBlocksCount += pair.second->GetCreatedBreackableBlocksCount();
		}*/
	}

	void GameStatePlayingData::GetBallInverse(const sf::Vector2f& ballPos, const sf::FloatRect& blockRect, bool& needInverseDirX, bool& needInverseDirY) 
	{

		if (ballPos.y > blockRect.top + blockRect.height)
		{
			needInverseDirY = true;
		}
		if (ballPos.x < blockRect.left)
		{
			needInverseDirX = true;
		}
		if (ballPos.x > blockRect.left + blockRect.width)
		{
			needInverseDirX = true;
		}
	}

	void GameStatePlayingData::Notify(std::shared_ptr<IObservable> observable)
	{
		//if (auto block = std::dynamic_pointer_cast<Block>(observable); block) 
		//{
		//	--breackableBlocksCount;
		//	Game& game = Application::Instance().GetGame();
		//	if (breackableBlocksCount == 0) 
		//	{
		//		game.LoadNextLevel();
		//	}
		//}
		//else if (auto ball = std::dynamic_pointer_cast<Ball>(observable); ball)
		//{
		//	if (ball->GetPosition().y > gameObjects.front()->GetRect().top) 
		//	{
		//		lives--;

		//		if(lives < 0)
		//		{
		//			lives = 0;
		//			Game& game = Application::Instance().GetGame();
		//			soundDeath.play();
		//			game.UpdateRecord(SETTINGS.PLAYER_NAME, score);
		//			game.LooseGame();
		//		}
		//		else
		//		{
		//			// Рестарт платформы и шарика
		//			auto platform = std::dynamic_pointer_cast<Platform>(gameObjects[0]);
		//			auto ball = std::dynamic_pointer_cast<Ball>(gameObjects[1]);
		//			if (platform) platform->restart();
		//			if (ball) ball->restart();
		//		}
		//	}
		//}
	}
}