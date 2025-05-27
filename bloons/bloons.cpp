#include "bloons.h"
#include <iostream>

Texture2D Bloon::texture = { 0 };

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

void Bloon::LoadBloonTexture(const char* filepath)
{
	texture = LoadTexture(filepath);
};

void Bloon::UnloadBloonTexture()
{
	UnloadTexture(texture);
};

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
	if (!active)
		return;

	int spriteindex = 3;
	int spritewidth = 192;
	int spriteheight = 304;

	Rectangle sourceRec = {
		static_cast<float>(spriteindex * spritewidth),
		0,
		static_cast<float>(spritewidth),
		static_cast<float>(spriteheight)
	};

	Rectangle destRec = {
		position.x,
		position.y,
		static_cast<float>(spritewidth),
		static_cast<float>(spriteheight)
	};

	Vector2 origin = {
		spritewidth / 2.0f,
		spriteheight / 2.0f
	};

	DrawTexturePro(texture,
		       sourceRec,
		       destRec,
		       origin,
		       0,
		       color
		       );

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
