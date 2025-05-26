#include "bloons.h"
#include <iostream>

float getRandomFloatSpeed()
{
	int step = GetRandomValue(0,10);
	return 0.5f + step * 0.1f;
}

float getRandomXPos()
{
	return (float)GetRandomValue(SPAWNX_MIN, SPAWNX_MAX);
}

float getRandomYPos()
{
	return (float)GetRandomValue(SPAWNY_MIN, SPAWNY_MAX);
}

Color getRandomColor()
{
	static const Color colors[]
	{
		RED,
		BLUE,
		PURPLE,
		GOLD,
		GREEN
	};
	int index = GetRandomValue(0, sizeof(colors)/sizeof(colors[0]) -1);
	return colors[index];
}


Bloon::Bloon()
{
	this -> position = { getRandomXPos(), getRandomYPos() };
	this -> speed = getRandomFloatSpeed();
	this -> radius = 30.0f;
	this -> color = getRandomColor();
	this -> active = false;
}


void Bloon::Reset()
{
	this -> position = { getRandomXPos(), getRandomYPos() };
	this -> speed = getRandomFloatSpeed();
	this -> radius = 30.0f;
	this -> color = getRandomColor();
	this -> active = false;
}

void Bloon::Draw()
{
	if (active)
		DrawCircle(position.x, position.y, radius, color);
}

bool Bloon::isMouseOver() const
{
	return CheckCollisionPointCircle(GetMousePosition(), position, radius);
}

bool Bloon::isClicked() const
{
	return isMouseOver() && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

void Bloon::Update()
{
	if (isClicked() || position.y < 50)
		Reset();
	if (active)
		position.y -= speed;
}

void Bloon::logPos()
{
	std::cout << "bloonPos: (" << position.x << ", " << position.y << ")\n";
}
