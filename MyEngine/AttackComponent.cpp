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
		//Attack();
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