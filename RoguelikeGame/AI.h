#pragma once
#include "CameraComponent.h"
#include "GameWorld.h"
#include "SpriteRendererComponent.h"
#include "RenderSystem.h"
#include "InputComponent.h"
#include "GameObject.h"
#include "Vector.h"
#include <Pawn.h>

using namespace MyEngine;

namespace RoguelikeGame
{
	class AI
	{
		public:

			AI(const Vector2Df& position, GameObject* player);
			GameObject* GetGameObject();

			GameObject* player = nullptr;

		private:

			GameObject* gameObject;
	};
}