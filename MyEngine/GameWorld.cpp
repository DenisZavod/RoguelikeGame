#include "pch.h"
#include "GameWorld.h"
#include "../RoguelikeGame/HealthBarComponent.h"
#include "StatsComponent.h"
#include "../RoguelikeGame/GameSettings.h"
#include "../RoguelikeGame/StaminaBarComponent.h"
namespace MyEngine
{
	GameWorld* GameWorld::Instance()
	{
		static GameWorld world;
		return &world;
	}

	void GameWorld::Update(float deltaTime)
	{
		for (int i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i]->Update(deltaTime);
		}


	}

	void GameWorld::FixedUpdate(float deltaTime)
	{
		fixedCounter += deltaTime;
		if (fixedCounter > PhysicsSystem::Instance()->GetFixedDeltaTime())
		{
			fixedCounter -= PhysicsSystem::Instance()->GetFixedDeltaTime();
			PhysicsSystem::Instance()->Update();
		}
	}

	void GameWorld::Render()
	{
		for (int i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i]->Render();
		}

		MyEngine::GameObject* playerObject = nullptr;
		for (MyEngine::GameObject* obj : gameObjects)
		{
			if (obj != nullptr && obj->GetName() == "Player")
			{
				playerObject = obj;
				break;
			}
		}

		if (playerObject != nullptr)
		{
			MyEngine::StatsComponent* stats = playerObject->GetComponent<MyEngine::StatsComponent>();
			if (stats != nullptr)
			{
				RoguelikeGame::HealthBarComponent healthBar(stats->GetMaxHealth());
				healthBar.SetHealth(stats->GetCurrentHealth());
				healthBar.Render();

				RoguelikeGame::StaminaBarComponent staminaBar(stats->GetMaxStamina());
				staminaBar.SetStamina(stats->GetCurrentStamina()); // <-- ÂÎÇÌÎÆÍÀß ÎØÈÁÊÀ
				staminaBar.Render();

				if (stats != nullptr)
				{
					float damageTaken = stats->GetMaxHealth() - stats->GetCurrentHealth();

					if (damageTaken > 0)
					{
						sf::Font font;
						if (font.loadFromFile(RoguelikeGame::SETTINGS.RESOURCES_PATH + "Fonts/Roboto-Regular.ttf"))
						{
							sf::Text damageText;
							damageText.setFont(font);
							damageText.setString("Damage: " + std::to_string((int)damageTaken));
							damageText.setCharacterSize(48);
							damageText.setFillColor(sf::Color::Red);
							damageText.setOutlineColor(sf::Color::Black);
							damageText.setOutlineThickness(3);

							sf::RenderWindow& window = MyEngine::RenderSystem::Instance()->GetMainWindow();
							sf::Vector2u windowSize = window.getSize();
							sf::FloatRect textBounds = damageText.getLocalBounds();

							damageText.setOrigin(textBounds.width / 2.0f, textBounds.height / 2.0f);
							damageText.setPosition(windowSize.x / 2.0f, windowSize.y / 2.0f - 90.0f);

							sf::View savedView = window.getView();

							window.setView(window.getDefaultView());
							MyEngine::RenderSystem::Instance()->Render(damageText);
							window.setView(savedView);
						}
					}
				}
			}
		}

	}

	void GameWorld::LateUpdate()
	{
		for (int i = markedToDestroyGameObjects.size() - 1; i >= 0; i--)
		{
			DestroyGameObjectImmediate(markedToDestroyGameObjects[i]);
		}

	}

	GameObject* GameWorld::CreateGameObject()
	{
		GameObject* newGameObject = new GameObject();
		gameObjects.push_back(newGameObject);
		return newGameObject;
	}

	GameObject* GameWorld::CreateGameObject(std::string name)
	{
		GameObject* newGameObject = new GameObject(name);
		gameObjects.push_back(newGameObject);
		return newGameObject;
	}

	void GameWorld::DestroyGameObject(GameObject* gameObject)
	{
		markedToDestroyGameObjects.push_back(gameObject);
	}

	void GameWorld::Clear()
	{
		for (int i = gameObjects.size() - 1; i >= 0; i--)
		{
			if (gameObjects[i] == nullptr)
			{
				continue;
			}

			if (gameObjects[i]->GetComponent<TransformComponent>()->GetParent() == nullptr)
			{
				DestroyGameObjectImmediate(gameObjects[i]);
			}
		}

		fixedCounter = 0.f;
	}

	void GameWorld::Print() const
	{
		for (auto& obj : gameObjects)
		{
			if (obj == nullptr)
			{
				continue;
			}
			if (obj->GetComponent<TransformComponent>()->GetParent() == nullptr)
			{
				obj->Print();
			}
		}
	}

	void GameWorld::DestroyGameObjectImmediate(GameObject* gameObject)
	{
		auto parent = gameObject->GetComponent<TransformComponent>()->GetParent();
		if (parent != nullptr)
		{
			parent->GetGameObject()->RemoveChild(gameObject);
		}

		for (auto transform : gameObject->GetComponentsInChildren<TransformComponent>())
		{
			GameObject* gameObjectToDelete = transform->GetGameObject();

			gameObjects.erase(std::remove_if(gameObjects.begin(), gameObjects.end(), [gameObjectToDelete](GameObject* obj) { return obj == gameObjectToDelete; }), gameObjects.end());
			markedToDestroyGameObjects.erase(std::remove_if(markedToDestroyGameObjects.begin(), markedToDestroyGameObjects.end(), [gameObjectToDelete](GameObject* obj) { return obj == gameObjectToDelete; }), markedToDestroyGameObjects.end());

			delete gameObjectToDelete;
		}
	}
}