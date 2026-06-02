#include "HealthBarComponent.h"
#include "RenderSystem.h" 
#include <assert.h>
#include "GameSettings.h"

namespace RoguelikeGame
{
    HealthBarComponent::HealthBarComponent(float maxHealth)
        : currentHealth(maxHealth), maxHealth(maxHealth)
    {

        assert(font.loadFromFile(SETTINGS.RESOURCES_PATH + "Fonts/Roboto-Regular.ttf"));

        float barWidth = 200.0f;
        float barHeight = 30.0f;

        backgroundBar.setSize(sf::Vector2f(barWidth, barHeight));
        backgroundBar.setFillColor(sf::Color(150, 0, 0, 255));

        healthBarFill.setSize(sf::Vector2f(barWidth, barHeight));
        healthBarFill.setFillColor(sf::Color(0, 200, 0, 255));

        

        healthLabel.setFont(font);
        healthLabel.setString("PLAYER_HEALTH");
        healthLabel.setCharacterSize(16);
        healthLabel.setFillColor(sf::Color::White);
        healthLabel.setPosition(10.0f, 40.0f);
    }

    void HealthBarComponent::SetHealth(float health)
    {
        currentHealth = std::clamp(health, 0.0f, maxHealth);

        float ratio = currentHealth / maxHealth;
        float newWidth = 200.0f * ratio;
        float height = healthBarFill.getSize().y;

        healthBarFill.setSize(sf::Vector2f(newWidth, height));
    }

    void HealthBarComponent::UpdateHealthBar(float currentHealth, float maxHealth)
    {
        if (maxHealth <= 0) return;

        float ratio = currentHealth / maxHealth;
        float newWidth = 200.0f * ratio;
        float height = healthBarFill.getSize().y;

        healthBarFill.setSize(sf::Vector2f(newWidth, height));
    }

    void HealthBarComponent::Render()
    {
        sf::RenderWindow& window = MyEngine::RenderSystem::Instance()->GetMainWindow();
        sf::View savedView = window.getView();

        window.setView(window.getDefaultView());

        backgroundBar.setPosition(10.0f, 10.0f);
        healthBarFill.setPosition(10.0f, 10.0f);

        MyEngine::RenderSystem::Instance()->Render(backgroundBar);
        MyEngine::RenderSystem::Instance()->Render(healthBarFill);
        MyEngine::RenderSystem::Instance()->Render(healthLabel);

        window.setView(savedView);
    }
}