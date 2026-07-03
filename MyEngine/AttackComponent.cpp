#include "pch.h"
#include "AttackComponent.h"
#include "InputComponent.h" 
#include "StatsComponent.h"

namespace MyEngine
{
	AttackComponent::AttackComponent(GameObject* gameObject, float attackPower, GameObject* target)
		: Component(gameObject), attackPower(attackPower), target(target)
	{
	}

	void AttackComponent::Update(float deltaTime)
	{
		if (!target) return; 

		auto myTransform = gameObject->GetComponent<TransformComponent>();
		auto targetTransform = target->GetComponent<TransformComponent>();
		if (!myTransform || !targetTransform) return;

		Vector2Df myPos = myTransform->GetWorldPosition();
		Vector2Df targetPos = targetTransform->GetWorldPosition();
		float distanceToTarget = (myPos - targetPos).GetLength();

		
		if (cooldownTimer > 0.0f)
		{
			cooldownTimer -= deltaTime;
		}

		
		auto myStats = gameObject->GetComponent<StatsComponent>();
		if (!myStats || myStats->GetCurrentStamina() <= 0.0f)
		{
			return; 
		}

		
		auto inputComponent = gameObject->GetComponent<InputComponent>();
		bool isPlayerWantsToAttack = false;

		if (inputComponent && inputComponent->IsAttack())
		{
			isPlayerWantsToAttack = true;
		}

		
		bool isEnemyAutoAttack = !inputComponent;

		
		if ((isPlayerWantsToAttack || isEnemyAutoAttack) &&
			distanceToTarget < attackRange &&
			cooldownTimer <= 0.0f)
		{
			Attack(myStats); 
			cooldownTimer = attackCooldown;
		}
	}

	void AttackComponent::Render() {}

	void AttackComponent::SetAttackPower(float newAttackPower) { attackPower = newAttackPower; }

	void AttackComponent::Attack(StatsComponent* myStats)
	{
		if (!target) return;

		
		auto targetStatsComponent = target->GetComponent<StatsComponent>();
		if (targetStatsComponent)
		{
			targetStatsComponent->TakeDamage(attackPower);
		}

		myStats->ConsumeStamina(10.0f);
	}
}