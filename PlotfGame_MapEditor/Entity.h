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
	sf::Vector2f Coorinate;
	sf::Vector2f Size;
	int Speed_G;
	sf::Vector2f Speed;
	sf::Vector2f LastCoord;
public:

};

class Player: ControlKey, EntityBase
{
private:
	int JumpForce;
	bool RightWall, LeftWall;
	bool Walking;
	
public:
	Player();
	Player(sf::Vector2f coord);
	void SetControl(sf::Keyboard::Key Up, sf::Keyboard::Key Down, sf::Keyboard::Key Right, sf::Keyboard::Key Left);;
	void Force(sf::Time& Time);
	void Control(sf::Time& Time);
	sf::Vector2f getCoordinate();
	void Collision(std::vector<std::vector<bool>>&);
	void UpdateLastCoord();
	void PlayerFoctions(sf::Time& Time, std::vector<std::vector<bool>>&);
};