#include"Entity.h"
#include"Level.h"

Player::Player(){}

int Player::Gravity = 30;

Player::Player(sf::Vector2f coord) 
{
	width = 32; length = 40;
	RectPlayer.setSize(sf::Vector2f(width, length));
	RectPlayer.setPosition(coord);
	RectPlayer.setFillColor(sf::Color::Red);
	RectPlayer.setOrigin(width / 2, length / 2);
	Speed = 500;
	speedX = 0;
	speedY = 0;
	Walking = false;
	JumpForce = 900;

};

sf::Vector2f Player::getCoordinate()
{
	return RectPlayer.getPosition();
}

void Player::SetControl(sf::Keyboard::Key Up, sf::Keyboard::Key Down, sf::Keyboard::Key Right, sf::Keyboard::Key Left)
{
	 this->Up = Up;
	 this->Down = Down;
	 this->Right = Right;
	 this->Left = Left;
};

void Player::Control(sf::Time* Time) 
{
	//if (sf::Keyboard::isKeyPressed(Up)) RectPlayer.move(0, -Speed * Time->asSeconds());
	//if (sf::Keyboard::isKeyPressed(Down)) RectPlayer.move(0, Speed * Time->asSeconds());
	if (sf::Keyboard::isKeyPressed(Right)) RectPlayer.move(Speed * Time->asSeconds(), 0);
	if (sf::Keyboard::isKeyPressed(Left)) RectPlayer.move(-Speed * Time->asSeconds(), 0);
};

sf::RectangleShape* Player::getRectangle() 
{
	return &RectPlayer;
}

void Player::Force(sf::Time* Time)
{
	
	if (!Walking) speedY += Gravity; else speedY = 0; ///////////////////////////
	if ((sf::Keyboard::isKeyPressed(Up)) && (Walking)) { speedY = -JumpForce; Walking = false; };
	RectPlayer.move(speedX * Time->asSeconds(), speedY * Time->asSeconds());
}

void Player::Collision(std::vector<std::vector<int>> coord, std::vector<Block> idBlocku)
{
	//if ( (Environment[2].z = 1) && (RectPlayer.getPosition().y + length/2 > Environment[2].x * 50) ) { Walking = true;};
	//if (Environment[2].z = 0)  Walking = false;
	for(int i = (RectPlayer.getPosition().y - length / 2) /50; i < (RectPlayer.getPosition().y + length / 2) / 50; i++)
		for (int j = (RectPlayer.getPosition().x - width / 2) / 50; j < (RectPlayer.getPosition().x + width) /50; j++)
		{
			if (*((coord + j) + i) == 1)
		};

}
