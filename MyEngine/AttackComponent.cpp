#include "pch.h"
#include "AttackComponent.h"
#include "InputComponent.h" 
#include "StatsComponent.h"
#include "TransformComponent.h"

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
		if (!myStats) return;

		
		const float PASSIVE_DAMAGE_PER_SECOND = 0.2f; // Сколько ХП теряем в секунду
		if (distanceToTarget < attackRange)
		{
			myStats->TakeDamage(PASSIVE_DAMAGE_PER_SECOND * deltaTime);
		}

		if (myStats->GetCurrentStamina() <= 0.0f)
		{
			return; // Если стамина кончилась, выходим (активная атака невозможна)
		}

		bool isPlayerWantsToAttack = false;
		auto inputComponent = gameObject->GetComponent<InputComponent>();
		if (inputComponent && inputComponent->IsAttack())
		{
			isPlayerWantsToAttack = true;
		}

		bool isEnemyAutoAttack = !inputComponent;

		// Проверка условий для удара
		if ((isPlayerWantsToAttack || isEnemyAutoAttack) &&
			distanceToTarget < attackRange &&
			cooldownTimer <= 0.0f)
		{
			// Защита от самобоя (Self-harm prevention)
			if (target->GetName() == "player")
			{
				LOG_INFO("Self-attack blocked.");
				return;
			}

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

		// Трата стамины 
		myStats->ConsumeStamina(5.0f);
	}
}