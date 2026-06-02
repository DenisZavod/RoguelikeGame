#pragma once // <-- Это очень важная строка, она предотвращает ошибки

#include <SFML/Graphics.hpp>
#include "RenderSystem.h" 
#include <SFML/Graphics/Text.hpp>

// Убедись, что класс находится внутри пространства имен RoguelikeGame
namespace RoguelikeGame
{
    // Имя класса должно точно совпадать с именем файла
    class HealthBarComponent
    {
    public:
        // Конструктор принимает максимальное здоровье
        HealthBarComponent(float maxHealth);

        // Метод для изменения текущего здоровья
        void SetHealth(float health);

        // Метод для отрисовки полоски
        void Render();

        void UpdateHealthBar(float currentHealth, float maxHealth);

    private:
        float currentHealth;
        float maxHealth;

        // Графические элементы для отрисовки (из библиотеки SFML)
        sf::RectangleShape backgroundBar;
        sf::RectangleShape healthBarFill;

        sf::Text healthLabel; // Переменная для нашей надписи
        sf::Font font;         // Переменная для шрифта
    };
}