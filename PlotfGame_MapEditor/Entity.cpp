#include"Entity.h"
#include"Level.h"
#include<iostream>

Player::Player(){}


Player::Player(sf::Vector2f coord) 
{
	Gravity = 50;
	Size = sf::Vector2f(20,28);
	Coorinate = coord;
	Speed_G = 500;
	Speed = sf::Vector2f(0, 0);
	Walking = false;
	JumpForce = 1000;
	LastCoord = coord;
	RightWall = false;
	LeftWall = false;
};

sf::Vector2f Player::getCoordinate()
{
	return Coorinate;
}

void Player::SetControl(sf::Keyboard::Key Up, sf::Keyboard::Key Down, sf::Keyboard::Key Right, sf::Keyboard::Key Left)
{
	 this->Up = Up;
	 this->Down = Down;
	 this->Right = Right;
	 this->Left = Left;
};

void Player::Control(sf::Time& Time) 
{
	//if (sf::Keyboard::isKeyPressed(Up)) RectPlayer.move(0, -Speed * Time->asSeconds());
	//if (sf::Keyboard::isKeyPressed(Down)) RectPlayer.move(0, Speed * Time->asSeconds());
	if (!RightWall) if (sf::Keyboard::isKeyPressed(Right)) Coorinate = Coorinate + sf::Vector2f(Speed_G * Time.asSeconds(), 0);
	if (!LeftWall) if (sf::Keyboard::isKeyPressed(Left)) Coorinate = Coorinate + sf::Vector2f(-Speed_G * Time.asSeconds(), 0);
};

void Player::Force(sf::Time& Time)
{
	
	if (!Walking) Speed.y += Gravity; else Speed.y = 0; //////////////////////////
	if ((sf::Keyboard::isKeyPressed(Up)) && (Walking)) { Speed.y = -JumpForce; Walking = false; };
	Coorinate = Coorinate + sf::Vector2f(Speed.x * Time.asSeconds(), Speed.y * Time.asSeconds());
}


void Player::Collision(std::vector<std::vector<bool>>& Wall)
{
	int i = 1; //Интервал
	if ((Wall[(Coorinate.y + Size.y / 2) / 32] // Если один из уголов находится в сене
		[(Coorinate.x - Size.x / 2) / 32]) ||
		(Wall[(Coorinate.y + Size.y / 2) / 32]
			[(Coorinate.x + Size.x / 2) / 32]) ||
			(Wall[(Coorinate.y - Size.y / 2 ) / 32]
				[(Coorinate.x - Size.x / 2) / 32]) ||
				(Wall[(Coorinate.y - Size.y / 2 ) / 32]
					[(Coorinate.x + Size.x / 2) / 32]))
	{
		sf::Vector2f CurrentCoord(Coorinate);
		while ((Wall[(Coorinate.y + Size.y / 2) / 32] // То пока он в стене
			[(Coorinate.x - Size.x / 2) / 32]) ||
			(Wall[(Coorinate.y + Size.y / 2) / 32]
				[(Coorinate.x + Size.x / 2) / 32]) ||
				(Wall[(Coorinate.y - Size.y / 2 ) / 32]
					[(Coorinate.x - Size.x / 2) / 32]) ||
					(Wall[(Coorinate.y - Size.y / 2) / 32]
						[(Coorinate.x + Size.x / 2) / 32]))
		{
			if (CurrentCoord.y < LastCoord.y) CurrentCoord.y++; else if (CurrentCoord.y > LastCoord.y) CurrentCoord.y--; // Менять координату на белее близкую к прошлой позиции
			if (CurrentCoord.x < LastCoord.x) CurrentCoord.x++; else if (CurrentCoord.x > LastCoord.x) CurrentCoord.x--;
			Coorinate = sf::Vector2f( (int)(CurrentCoord.x), (int)(CurrentCoord.y));
		};

	}
	if ((Wall[(Coorinate.y + Size.y / 2 + i) / 32] //Если под одним из нижнич углов стена 
		[(Coorinate.x - Size.x / 2) / 32]) ||
		(Wall[(Coorinate.y + Size.y / 2 + i) / 32]
			[(Coorinate.x + Size.x / 2) / 32])) Walking = true; //то идти
	else Walking = false;

	if ((Wall[(Coorinate.y - Size.y / 2 - i) / 32] //Если под одним из верхних углов стена 
		[(Coorinate.x - Size.x / 2) / 32]) ||
		(Wall[(Coorinate.y - Size.y / 2 - i) / 32]
			[(Coorinate.x + Size.x / 2) / 32])) Speed.y = 0;// то вертикальная скорость = 0

	if ((Wall[(Coorinate.y + Size.y / 2) / 32]//Если под одним из правых углов стена 
		[(Coorinate.x + Size.x / 2 + i) / 32]) ||
		(Wall[(Coorinate.y - Size.y / 2) / 32]
			[(Coorinate.x + Size.x / 2 + i) / 32])) RightWall = true; //то отмечать что справа стена
	else RightWall = false;

	if ((Wall[(Coorinate.y + Size.y / 2 ) / 32]//Если под одним из левых углов стена 
		[(Coorinate.x - Size.x / 2 - i) / 32]) ||
		(Wall[(Coorinate.y - Size.y / 2) / 32]
			[(Coorinate.x - Size.x / 2 - i) / 32])) LeftWall = true;//то отмечать что слева стена
	else LeftWall = false;

};

void Player::UpdateLastCoord()
{
	LastCoord = Coorinate;
}

void Player::PlayerFoctions(sf::Time& Time, std::vector<std::vector<bool>>& Wall)
{
	Control(Time);
	Force(Time);
	Collision(Wall);
	UpdateLastCoord();
}
