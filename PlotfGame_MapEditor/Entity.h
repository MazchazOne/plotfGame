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

class EntityBase
{
protected:
	int Gravity; 
	float width;
	float length;
public:

};

class Player: ControlKey, EntityBase
{
private:
	
	int JumpForce;
	int Speed;
	int speedX;
	int speedY;
	bool RightWall, LeftWall;

	bool Walking;
	sf::RectangleShape RectPlayer;

	sf::Vector2f LastCoord;
	
public:
	Player();
	Player(sf::Vector2f coord);
	void SetControl(sf::Keyboard::Key Up, sf::Keyboard::Key Down, sf::Keyboard::Key Right, sf::Keyboard::Key Left);;
	void Force(sf::Time* Time);
	void Control(sf::Time* Time);
	sf::Vector2f getCoordinate();
	sf::RectangleShape* getRectangle();
	void Collision(std::vector<std::vector<bool>>&);
	void UpdateLastCoord();
};