#include"Level.h"

Block::Block()
{
	RectBlock.setSize(sf::Vector2f(50, 50));
	bounce = 0;
	
};

Level::Level()
{

}

void Level::updateEnvironment(sf::Vector2f coord, sf::Vector3f* Block)
{
	
	*Block = { coord.x / 50, coord.y / 50 - 1, static_cast<float>(BlockCoordinate[coord.y / 50 - 1][coord.x / 50]) };
	*(Block + 1) = { coord.x / 50 + 1, coord.y / 50 , static_cast<float>(BlockCoordinate[coord.y / 50 ][coord.x / 50 + 1]) };
	*(Block + 2) = { coord.x / 50, coord.y / 50 + 1, static_cast<float>(BlockCoordinate[coord.y / 50 + 1][coord.x / 50] )};
	*(Block + 3) = { coord.x / 50 - 1, coord.y / 50, static_cast<float>(BlockCoordinate[coord.y / 50 ][coord.x / 50 - 1] )};
}