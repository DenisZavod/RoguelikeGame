#pragma once
#include "CameraComponent.h"
#include "GameWorld.h"
#include "SpriteRendererComponent.h"
#include "RenderSystem.h"
#include "InputComponent.h"
#include "GameObject.h"
#include <Pawn.h>

namespace RoguelikeGame
{
	class Player
	{
		public:

			Player(const MyEngine::Vector2Df& position);
			MyEngine::GameObject* GetGameObject();

		private:

			MyEngine::GameObject* gameObject;
	};
}

