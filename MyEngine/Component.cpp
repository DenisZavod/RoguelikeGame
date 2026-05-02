#include "pch.h"
#include "Component.h"
#include <iostream>
#include "Logger.h"

namespace MyEngine
{
	Component::Component(GameObject* gameObject) : gameObject(gameObject) {}

	Component::~Component()
	{
		LOG_INFO("Deleted component: " + std::string("this"));
	}

	GameObject* Component::GetGameObject()
	{
		return gameObject;
	}
}