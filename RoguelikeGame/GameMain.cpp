// Arkanoid.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Engine.h"
#include "ResourceSystem.h"
#include "DeveloperLevel.h"
#include <windows.h>
#include "Matrix2D.h"
#include <Logger.h>

using namespace RoguelikeGame;

int main()
{
	auto logger = std::make_shared<Logger>();
	logger->addSink(std::make_shared<ConsoleSink>());
	logger->addSink(std::make_shared<FileSink>("log.txt"));
	LoggerRegistry::getInstance().registerLogger("global", logger);

	//Выделяем консоль и перенаправляем вывод
	if(AllocConsole())
	{
		FILE* fp;
		freopen_s(&fp, "CONOUT$", "w", stdout); //Перенаправляем stdout в консоль
		freopen_s(&fp, "CONOUT$", "w", stderr); //Перенаправляем stderr в консоль
	}
	else
	{
		LOG_ERROR("Failed to allocate console.");
	}

	RenderSystem::Instance()->SetMainWindow(new sf::RenderWindow(sf::VideoMode(1280, 720), "Roguelike"));

	ResourceSystem::Instance()->LoadTextureMap("player", "Resources/TextureMaps/Player.png", { 48, 63 }, 4, false);
	ResourceSystem::Instance()->LoadTextureMap("AI", "Resources/TextureMaps/Player.png", { 48, 63 }, 4, false);
	ResourceSystem::Instance()->LoadTextureMap("level_floors", "Resources/TextureMaps/Floor.png", { 16, 16 }, 49, false);
	ResourceSystem::Instance()->LoadTextureMap("level_walls", "Resources/TextureMaps/Wall.png", { 16, 16 }, 48, false);
	

	ResourceSystem::Instance()->LoadSound("music", "Resources/Sounds/Background.wav");
	

	auto developerLevel = std::make_shared<DeveloperLevel>();
	developerLevel->Start();

	/*MyEngine::Matrix2D zeroMatrix;
	zeroMatrix.Print();

	MyEngine::Matrix2D translationMatrix = MyEngine::Matrix2D(Vector2Df(12.f, 5.f), 0.f, Vector2Df(1.f, 1.f));
	translationMatrix.Print();

	MyEngine::Matrix2D rotationMatrix = MyEngine::Matrix2D(Vector2Df(0.f, 0.f), 90.f, Vector2Df(1.f, 1.f));
	rotationMatrix.Print();

	(rotationMatrix * translationMatrix).Print();

	MyEngine::Matrix2D someMatrix = MyEngine::Matrix2D(Vector2Df(13.f, 25.f), 90.f, Vector2Df(1.5f, 1.f));
	someMatrix.Print();

	(someMatrix * someMatrix.GetInversed()).Print();*/

	MyEngine::Engine::Instance()->Run();

	return 0;
}