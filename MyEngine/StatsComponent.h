#pragma once
#include "Component.h"
#include "Logger.h"

namespace MyEngine
{
	class StatsComponent : public Component
	{
		public:

			StatsComponent(GameObject* gameObject, float health, float armor);

			void Update(float deltaTime) override;
			void Render() override;

			float GetCurrentHealth() const { return currentHealth; }
			float GetMaxHealth() const { return maxHealth; }
			float GetArmor() const { return armor; }


			void TakeDamage(float damage);

			void Heal(float amount);

			bool IsDead() const { return currentHealth <= 0.0f; }

			float GetMaxStamina() const { return maxStamina; }
			float GetCurrentStamina() const { return currentStamina; }

	
			void ConsumeStamina(float amount);

			


		private:

			float maxHealth;
			float currentHealth;
			float armor;
			float hurtTimer = 0.f; // Добавьте эту строку
			float maxStamina = 100.0f; // Начальное значение
			float currentStamina = maxStamina;
			
	};
}


