#pragma once
#include<SFML\Graphics.hpp>
#include <vector>


class Block
{
public:
	sf::Texture Texture;
	sf::RectangleShape RectBlock;
	bool penetration;
	float friction, damage, bounce, speed, SpeedCoefficient;
	
	unsigned int id;
	void setTexture();
	Block();
};

class Level
{
private:

public:
	Level();
	std::vector<Block> idBlocks;
	std::vector<std::vector<int>> BlockCoordinate;
	void updateEnvironment(sf::Vector2f, sf::Vector3f*);
};