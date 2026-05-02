#include "AI.h"
#include "ResourceSystem.h"
#include "SpriteColliderComponent.h"
//#include "MovementComponent.h"
#include <AttackComponent.h>

#include <FollowComponent.h>


namespace RoguelikeGame
{
	AI::AI(const Vector2Df& position, GameObject* player)
		: gameObject(gameObject), player(player)
	{
		gameObject = MyEngine::GameWorld::Instance()->CreateGameObject("AI");
		auto transform = gameObject->GetComponent<MyEngine::TransformComponent>();
		transform->SetWorldPosition(position);

		auto renderer = gameObject->AddComponent<MyEngine::SpriteRendererComponent>();
		renderer->SetTexture(*MyEngine::ResourceSystem::Instance()->GetTextureMapElementShared("AI", 0));
		renderer->SetPixelSize(100, 100);

		auto follower = gameObject->AddComponent<MyEngine::FollowComponent>();
		follower->SetTarget(player);
		follower->SetSpeed(100.0f);

		auto rigidbody = gameObject->AddComponent<MyEngine::RigidbodyComponent>();
		rigidbody->SetKinematic(false);

		auto collideer = gameObject->AddComponent<MyEngine::SpriteColliderComponent>();

		//Attack Component
		auto attackComponent = gameObject->AddComponent<MyEngine::AttackComponent>(10.0f, player);

		
	}

	//void AI::Update(float deltaTime)
	//{
	//	// Получаем компоненты
	//	auto attackComponent = gameObject->GetComponent<MyEngine::AttackComponent>();
	//	auto transform = gameObject->GetComponent<MyEngine::TransformComponent>();

	//	// Получаем позицию AI и игрока
	//	auto playerTransform = player ? player->GetComponent<MyEngine::TransformComponent>() : nullptr;
	//	if (!playerTransform) return;

	//	auto aiPos = transform->GetWorldPosition();
	//	auto playerPos = playerTransform->GetWorldPosition();;

	//	// Проверяем дистанцию
	//	float distance = (aiPos - playerPos).GetLength();
	//	if (distance < 500.0f) // например, 100 — радиус атаки
	//	{
	//		// Атакуем игрока
	//		//attackComponent->Attack(player); // реализуйте метод Attack, если его нет
	//	}


	//}

	MyEngine::GameObject* AI::GetGameObject()
	{
		return gameObject;
	}
}