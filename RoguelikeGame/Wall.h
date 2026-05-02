#pragma once
#include <GameWorld.h>
#include <ResourceSystem.h>
#include "GameObject.h"

namespace RoguelikeGame
{
	class Wall
	{
		public:

			Wall(const MyEngine::Vector2Df position, int textureMapIndex);

		private:

			MyEngine::GameObject* gameObject;
	};
}