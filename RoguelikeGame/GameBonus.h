#pragma once
#include <SFML/Graphics.hpp>
//#include "GameObject.h"
#include "IObserver.h"

namespace RoguelikeGame
{
	//class Ball;
	//class Platform;

	enum class BonusType
	{
		ExpandPlatform,
		SlowBall,
		ExtraLife,
		Count
	};

	class IBonusEffect
	{
		public:

			virtual ~IBonusEffect() = default;
			//virtual void Apply(Platform& platform, Ball& ball) = 0;
			//virtual void Revert(Platform& platform, Ball& ball) = 0;
	};

	class GameBonus : /*public GameObject,*/ public IObservable
	{
		public:

			GameBonus(const sf::Vector2f& position, BonusType type);
			~GameBonus() = default;

			//void Update(float deltaTime) override;

			bool IsActive() const { return active; }
			BonusType GetType() const { return type; }
			//void OnCollect(Platform& platform, Ball& ball);
			//void OnEffectEnd(Platform& platform, Ball& ball);

		private:
			BonusType type;
			std::unique_ptr<IBonusEffect> effect;
			bool active = true;
			bool effectApplied = false;
			float timer = 0.f;
			float duration = 0.f;
	};
}


