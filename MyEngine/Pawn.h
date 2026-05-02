#pragma once

namespace MyEngine
{
	class GameObject;

	class Pawn
	{
		public:

			Pawn(GameObject* gameObject);
			virtual ~Pawn();

			virtual void Update(float deltaTime) = 0;

			GameObject* GetGameObject();

		protected:

			GameObject* gameObject;
	};
}


