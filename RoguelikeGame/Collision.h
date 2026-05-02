#pragma once
#include "SFML/Graphics.hpp"
#include <memory>

namespace RoguelikeGame
{
	class Collision
	{
		public:

			virtual bool CheckCollision(std::shared_ptr<Collision> collision) 
			{
				if (GetCollision(collision)) 
				{
					OnHit();
					collision->OnHit();
					return true;
				}
				return false;
			}

			virtual bool GetCollision(std::shared_ptr<Collision> collision) const = 0;

		protected:

			virtual void OnHit() = 0;
	};
}