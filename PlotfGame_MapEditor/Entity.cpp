#include"Entity.h"
#include"Level.h"
#include<iostream>

Player::Player(){}


Player::Player(sf::Vector2f coord) 
{
	Gravity = 20;
	width = 24; length = 32;
	RectPlayer.setSize(sf::Vector2f(width, length));
	RectPlayer.setPosition(coord);
	RectPlayer.setFillColor(sf::Color::Red);
	RectPlayer.setOrigin(width / 2, length / 2);
	Speed = 300;
	speedX = 0;
	speedY = 0;
	Walking = false;
	JumpForce = 800;
	LastCoord = coord;
	RightWall = false;
	LeftWall = false;

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
	if (!RightWall) if (sf::Keyboard::isKeyPressed(Right)) RectPlayer.move(Speed * Time->asSeconds(), 0);
	if (!LeftWall) if (sf::Keyboard::isKeyPressed(Left)) RectPlayer.move(-Speed * Time->asSeconds(), 0);
};

sf::RectangleShape* Player::getRectangle() 
{
	return &RectPlayer;
}

void Player::Force(sf::Time* Time)
{
	
	if (!Walking) speedY += Gravity; else speedY = 0; //////////////////////////
	if ((sf::Keyboard::isKeyPressed(Up)) && (Walking)) { speedY = -JumpForce; Walking = false; };
	RectPlayer.move(speedX * Time->asSeconds(), speedY * Time->asSeconds());
}


void Player::Collision(std::vector<std::vector<bool>>& Wall)
{

	if ((Wall[(RectPlayer.getPosition().y + RectPlayer.getSize().y / 2 ) / 32]
		[(RectPlayer.getPosition().x - RectPlayer.getSize().x / 2) / 32]) || 
			(Wall[(RectPlayer.getPosition().y + RectPlayer.getSize().y / 2) / 32]
			[(RectPlayer.getPosition().x + RectPlayer.getSize().x / 2) / 32]) || 
				(Wall[(RectPlayer.getPosition().y - RectPlayer.getSize().y / 2 + 1) / 32]
				[(RectPlayer.getPosition().x - RectPlayer.getSize().x / 2) / 32]) || 
					(Wall[(RectPlayer.getPosition().y - RectPlayer.getSize().y / 2 + 1) / 32]
					[(RectPlayer.getPosition().x + RectPlayer.getSize().x / 2) / 32]))
			{ 
		sf::Vector2f CurrentCoord(RectPlayer.getPosition());
		int dx(0), dy(0);
		while ((Wall[(RectPlayer.getPosition().y + RectPlayer.getSize().y / 2) / 32]
			[(RectPlayer.getPosition().x - RectPlayer.getSize().x / 2) / 32]) ||
			(Wall[(RectPlayer.getPosition().y + RectPlayer.getSize().y / 2) / 32]
				[(RectPlayer.getPosition().x + RectPlayer.getSize().x / 2) / 32]) ||
				(Wall[(RectPlayer.getPosition().y - RectPlayer.getSize().y / 2 + 1) / 32]
					[(RectPlayer.getPosition().x - RectPlayer.getSize().x / 2) / 32]) ||
					(Wall[(RectPlayer.getPosition().y - RectPlayer.getSize().y / 2 + 1) / 32]
						[(RectPlayer.getPosition().x + RectPlayer.getSize().x / 2) / 32]))
		{
			if (CurrentCoord.y + dy < LastCoord.y) dy++; else if (CurrentCoord.y + dy > LastCoord.y) dy--;
			if (CurrentCoord.x + dx < LastCoord.x) dx++; else if (CurrentCoord.x + dx > LastCoord.x) dx--;
			RectPlayer.setPosition(sf::Vector2f(CurrentCoord.x + dx, CurrentCoord.y + dy));
			speedX = 0;
			speedY = 0;
		};
				
			}
	 if((Wall[(RectPlayer.getPosition().y + RectPlayer.getSize().y / 2 + 1) / 32]
		[(RectPlayer.getPosition().x - RectPlayer.getSize().x / 2) / 32]) ||
		(Wall[(RectPlayer.getPosition().y + RectPlayer.getSize().y / 2 + 1) / 32]
			[(RectPlayer.getPosition().x + RectPlayer.getSize().x / 2) / 32])) Walking = true;
	else Walking = false;

	if ((Wall[(RectPlayer.getPosition().y + RectPlayer.getSize().y / 2 - 1) / 32]
		[(RectPlayer.getPosition().x + RectPlayer.getSize().x / 2 + 1) / 32 ]) ||
		(Wall[(RectPlayer.getPosition().y - RectPlayer.getSize().y / 2 + 1) / 32]
			[(RectPlayer.getPosition().x + RectPlayer.getSize().x / 2 + 1) / 32])) RightWall = true;
	else RightWall = false;

	if ((Wall[(RectPlayer.getPosition().y + RectPlayer.getSize().y / 2 - 1) / 32]
		[(RectPlayer.getPosition().x - RectPlayer.getSize().x / 2 - 1) / 32]) ||
		(Wall[(RectPlayer.getPosition().y - RectPlayer.getSize().y / 2 + 1) / 32]
			[(RectPlayer.getPosition().x - RectPlayer.getSize().x / 2- 1)  / 32])) LeftWall = true;
	else LeftWall = false;

};

void Player::UpdateLastCoord()
{
	LastCoord = RectPlayer.getPosition();
}

