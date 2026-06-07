#pragma once
#include <SFML/Graphics.hpp>
#include "RenderSystem.h"
#include <SFML/Graphics/Text.hpp>

namespace RoguelikeGame
{
    class StaminaBarComponent
    {
    public:
        // Конструктор принимает максимальное значение
        StaminaBarComponent(float maxStamina);

        // Метод для установки текущего значения
        void SetStamina(float stamina);

        // Метод для отрисовки
        void Render();

    private:
        float currentStamina;
        float maxStamina;

        // Графические элементы
        sf::RectangleShape backgroundBar;
        sf::RectangleShape staminaBarFill;

        // Надпись (по желанию)
        sf::Text staminaLabel;
        sf::Font font;
    };
}