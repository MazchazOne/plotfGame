#include<SFML\Graphics.hpp>
#include<iostream>
#include<fstream>
#include"Level.h"
#include"Entity.h"



int main()
{
	sf::ContextSettings Settings;
	Settings.antialiasingLevel = 6;

	sf::RenderWindow window(sf::VideoMode(1600, 900), "Plotformer", sf::Style::Default, Settings);
	window.setVerticalSyncEnabled(true);

	//sf::Font Font;
	//Font.loadFromFile("ARIAL.TTF");
	//std::vector<sf::Text> Texts(10);
	//sf::Text Text;
	Level Current_Level;
	Current_Level.idBlocks.resize(2);
	Current_Level.idBlocks[0].penetration =true;
	Current_Level.idBlocks[1].id = 1;
	Current_Level.idBlocks[1].penetration = false;
	Current_Level.idBlocks[1].RectBlock.setFillColor(sf::Color::Black);


	Current_Level.BlockCoordinate = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
	};
	//std::ifstream file("LevelTest", std::ios::binary);
	//file.read(reinterpret_cast<char*> (&Current_Level), sizeof(Current_Level));
	//file.close();

	//for (int i = 0; i < Current_Level.BlockCoordinate.size(); i++) {
	//	for (int j = 0; j < Current_Level.BlockCoordinate[i].size(); j++)
	//		std::cout << Current_Level.BlockCoordinate[i][j];
	//	std::cout << std::endl;
	//}


	Player TestPlayer(sf::Vector2f(800,450));
	TestPlayer.SetControl(sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Right, sf::Keyboard::Left);

	sf::View Camera(sf::Vector2f(800,450), sf::Vector2f(1600,900));
	sf::Clock clock;


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Time Time = clock.restart();
		window.setView(Camera);

		window.clear(sf::Color::White);
		
		for (int i = 0; i < Current_Level.BlockCoordinate.size(); i++)
			for (int j = 0; j < Current_Level.BlockCoordinate[i].size(); j++)
			{
				Current_Level.idBlocks[Current_Level.BlockCoordinate[i][j]].RectBlock.setPosition(sf::Vector2f(j * 50, i * 50));
				window.draw(Current_Level.idBlocks[Current_Level.BlockCoordinate[i][j]].RectBlock);
			}

		//Current_Level.updateEnvironment(TestPlayer.getCoordinate(), TestPlayer.Environment);
		TestPlayer.Collision(Current_Level.BlockCoordinate, Current_Level.idBlocks);
		TestPlayer.Control(&Time);
		TestPlayer.Force(&Time);
		window.draw(*TestPlayer.getRectangle());

		window.display();
	};
	return 0;
}