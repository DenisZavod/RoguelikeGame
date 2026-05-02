#include "Player.h"
#include <ResourceSystem.h>
#include <SpriteColliderComponent.h>
#include <SpriteDirectionComponent.h>
#include <SpriteMovementAnimationComponent.h>
#include <AudioComponent.h>
#include <MovementComponent.h>
#include <StatsComponent.h>
#include <AttackComponent.h>
#include <Logger.h>

namespace RoguelikeGame
{
	Player::Player(const MyEngine::Vector2Df& position)
		: gameObject(GetGameObject())
	{
		gameObject = MyEngine::GameWorld::Instance()->CreateGameObject("Player");
		auto transform = gameObject->GetComponent<MyEngine::TransformComponent>();
		transform->SetWorldPosition(position);

		auto renderer = gameObject->AddComponent<MyEngine::SpriteRendererComponent>();
		renderer->SetTexture(*MyEngine::ResourceSystem::Instance()->GetTextureMapElementShared("player", 0));
		renderer->SetPixelSize(100, 100);

		auto playerCamera = gameObject->AddComponent<MyEngine::CameraComponent>();
		playerCamera->SetWindow(&MyEngine::RenderSystem::Instance()->GetMainWindow());
		playerCamera->SetBaseResolution(1280, 720);

		auto playerInput = gameObject->AddComponent<MyEngine::InputComponent>();

		auto movement = gameObject->AddComponent<MyEngine::MovementComponent>();
		movement->SetSpeed(400.f);

		auto spriteDirection = gameObject->AddComponent<MyEngine::SpriteDirectionComponent>();

		auto rigidbody = gameObject->AddComponent<MyEngine::RigidbodyComponent>();
		rigidbody->SetKinematic(false);

		auto collider = gameObject->AddComponent<MyEngine::SpriteColliderComponent>();

		auto animator = gameObject->AddComponent<MyEngine::SpriteMovementAnimationComponent>();
		animator->Initialize("player", 6.f);

		//Health Component
		auto statsComponent = gameObject->AddComponent<MyEngine::StatsComponent>(100.f, 0.f);
		LOG_INFO("Player Health: " + std::to_string(statsComponent->GetCurrentHealth()) + "/" + std::to_string(statsComponent->GetMaxHealth()));
		
		//Attack Component
		auto attackComponent = gameObject->AddComponent<MyEngine::AttackComponent>(10.0f, gameObject);

	}

	MyEngine::GameObject* Player::GetGameObject()
	{
		return gameObject;
	}
}