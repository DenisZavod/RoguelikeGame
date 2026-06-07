#include "StaminaBarComponent.h"
#include "RenderSystem.h"
#include "GameSettings.h"
#include <assert.h>

namespace RoguelikeGame
{
    // Конструктор: задаём размеры и цвета
    StaminaBarComponent::StaminaBarComponent(float maxStamina)
        : currentStamina(maxStamina), maxStamina(maxStamina)
    {
        assert(font.loadFromFile(SETTINGS.RESOURCES_PATH + "Fonts/Roboto-Regular.ttf"));

        // Ширина и высота индикатора
        float barWidth = 200.0f;
        float barHeight = 30.0f; // Сделаем тоньше, чем полоска здоровья

        // Фон (серый)
        backgroundBar.setSize(sf::Vector2f(barWidth, barHeight));
        backgroundBar.setFillColor(sf::Color(150, 150, 150, 255));

        // Заливка (ярко-голубой)
        staminaBarFill.setSize(sf::Vector2f(barWidth, barHeight));
        staminaBarFill.setFillColor(sf::Color(0, 128, 255, 255));

        // Надпись (по желанию)
        staminaLabel.setFont(font);
        staminaLabel.setString("STAMINA");
        staminaLabel.setCharacterSize(16);
        staminaLabel.setFillColor(sf::Color::White);
        staminaLabel.setPosition(240.0f, 40.0f);
    }

    // Метод для установки текущего значения
    void StaminaBarComponent::SetStamina(float stamina)
    {
        currentStamina = std::clamp(stamina, 0.0f, maxStamina);

        // Рассчитываем пропорцию заполнения
        float ratio = currentStamina / maxStamina;
        float newWidth = 200.0f * ratio;
        float height = staminaBarFill.getSize().y;

        staminaBarFill.setSize(sf::Vector2f(newWidth, height));
    }

    // Метод для отрисовки
    void StaminaBarComponent::Render()
    {
        sf::RenderWindow& window = MyEngine::RenderSystem::Instance()->GetMainWindow();
        sf::View savedView = window.getView();

        // Переключаемся на вид по умолчанию (координаты окна)
        window.setView(window.getDefaultView());

        // Расположение под полосой здоровья
        backgroundBar.setPosition(240.0f, 10.0f);
        staminaBarFill.setPosition(240.0f, 10.0f);

        MyEngine::RenderSystem::Instance()->Render(backgroundBar);
        MyEngine::RenderSystem::Instance()->Render(staminaBarFill);
        MyEngine::RenderSystem::Instance()->Render(staminaLabel);

        window.setView(savedView);
    }
}