#pragma once
#include<SFML\Graphics.hpp>

struct ControlKey
{
protected:
	sf::Keyboard::Key Up;
	sf::Keyboard::Key Down;
	sf::Keyboard::Key Right;
	sf::Keyboard::Key Left;
};

class Player: ControlKey
{
private:
	static int Gravity; 
	int JumpForce;
	int Speed;
	int speedX;
	int speedY;
	float width;
	float length;

	bool Walking;
	sf::RectangleShape RectPlayer;
	sf::Texture Texture;
	
public:
	sf::Vector3f Environment[4] = { };
	Player();
	Player(sf::Vector2f coord);
	void SetControl(sf::Keyboard::Key Up, sf::Keyboard::Key Down, sf::Keyboard::Key Right, sf::Keyboard::Key Left);
	void SetTexture(sf::Texture texture);
	void Force(sf::Time* Time);
	void Control(sf::Time* Time);
	sf::Vector2f getCoordinate();
	sf::RectangleShape* getRectangle();
	void Collision(std::vector<std::vector<int>> coord, std::vector<Block> idBlock);
};