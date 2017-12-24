#pragma once
#include<SFML\Graphics.hpp>
#include <vector>


class Level
{
private:

public:
	Level();
	std::vector<std::vector<bool>> Wall;
	//void updateEnvironment(sf::Vector2f, sf::Vector3f*);
};