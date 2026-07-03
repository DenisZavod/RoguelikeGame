#pragma once
#include "Component.h"
#include "GameObject.h"
#include "StatsComponent.h"

namespace MyEngine
{
	struct AttackInfo
	{
		int damage;
		float range;
		float cooldown;
	};

	class AttackComponent : public Component
	{
	public:

		AttackComponent(GameObject* gameObject, float attackPower, GameObject* target);

		void Update(float deltaTime) override;
		void Render() override;

		float GetAttackPower() const { return attackPower; }

		float GetDamage() const { return attackPower; }

		void SetAttackPower(float newAttackPower);

		void Attack(StatsComponent* myStats);


		//void Attack();

		GameObject* target;

	private:

		float attackPower;
		float attackCooldown = 5.0f; // Время перезарядки в секундах
		float cooldownTimer = 5.0f; // Таймер

		float attackRange = 10.0f; // Дистанция атаки (в пикселях)
	};
}