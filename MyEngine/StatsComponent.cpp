#include "pch.h"
#include "StatsComponent.h"
#include "GameObject.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include "RenderSystem.h"
#include <assert.h>
#include "../RoguelikeGame/GameSettings.h"



namespace MyEngine
{
    StatsComponent::StatsComponent(GameObject* gameObject, float health, float armor)
        : Component(gameObject), maxHealth(health), currentHealth(health), armor(armor), hurtTimer(0.0f)
    {
        // Таймер обнуляется при создании объекта
    }

    

    void StatsComponent::Update(float deltaTime)
    {
        // Логика таймера мигания
        // Если таймер запущен (больше нуля), уменьшаем его каждый кадр
        if (hurtTimer > 0.0f)
        {
            hurtTimer -= deltaTime;
            // Защита от отрицательных значений
            if (hurtTimer < 0.0f)
                hurtTimer = 0.0f;
        }


        

     
        
    }

    void StatsComponent::Render()
    {
        // Компонент не рисует себя сам, только предоставляет данные
    }



    void StatsComponent::TakeDamage(float damage)
    {
        damage -= armor;
        if (damage < 0)
        {
            damage = 0;
        }

        armor -= 1;
        if (armor < 0)
        {
            armor = 0;
            LOG_INFO("the armor was broken");
        }

        currentHealth -= damage;
        if (currentHealth < 0)
        {
            currentHealth = 0;
        }

        hurtTimer = 0.4f;

        ConsumeStamina(1.0f); // lополнительно тратим 5 единиц стамины

        LOG_INFO("Took " + std::to_string(damage) + " damage, current health: " + std::to_string(currentHealth));

        LOG_INFO("Игрок получил " + std::to_string(damage) + " урона.");
        LOG_INFO("Текущее здоровье: " + std::to_string(currentHealth));
    }

    void StatsComponent::Heal(float amount)
    {
        currentHealth += amount;

        if (currentHealth > maxHealth)
        {
            currentHealth = maxHealth;
        }

        LOG_INFO("Healed " + std::to_string(amount) + " health, current health: " + std::to_string(currentHealth));

    }

    void StatsComponent::ConsumeStamina(float amount)
    {
        currentStamina -= amount;
        if (currentStamina < 0)
            currentStamina = 0;
    }


}