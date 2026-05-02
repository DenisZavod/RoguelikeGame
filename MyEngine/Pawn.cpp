#include "pch.h"
#include "Pawn.h"
#include <iostream>

namespace MyEngine
{
	Pawn::Pawn(GameObject* gameObject)
		: gameObject(gameObject) 
	{
	}

	Pawn::~Pawn()
	{
		std::cout << "Deleted component: " << this << std::endl;
	}

	GameObject* Pawn::GetGameObject()
	{
		return gameObject;
	}
}