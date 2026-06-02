#include "pch.h"
#include "AttackComponent.h"


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

		if (distanceToTarget < attackRange && cooldownTimer <= 0.0f)
		{
			Attack(); // Наносим урон

			// Сбрасываем таймер на полную длительность кулдауна
			cooldownTimer = attackCooldown;
		}
	}

	void AttackComponent::Render()
	{
	}

	void AttackComponent::SetAttackPower(float newAttackPower)
	{
		attackPower = newAttackPower;
	}

	void AttackComponent::Attack()
	{
		if (!target)
		{
			return;
		}

		auto targetStatsComponent = target->GetComponent<StatsComponent>();
		if (targetStatsComponent)
		{
			float damage = attackPower;
			targetStatsComponent->TakeDamage(damage);
		}
	}
}