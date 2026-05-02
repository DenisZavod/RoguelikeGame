#pragma once
#include "Component.h"
#include <SFML/Window.hpp> 

namespace MyEngine
{
	class InputComponent : public Component
	{
		public:

			InputComponent(GameObject* gameObject);

			void Update(float deltaTime) override;
			void Render() override;

			float GetHorizontalAxis() const;
			float GetVerticalAxis() const;

			bool IsAttack() const { return isAttack; }

		private:

			float horizontalAxis = 0.f;
			float verticalAxis = 0.f;

			bool isAttack = false;
	};
}

