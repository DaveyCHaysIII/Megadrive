#include "ctx.h"
#include <cmath>

void Ctx::Init(int arg)
{
	//todo
};

Ctx::state Ctx::getState()
{
	return gamestate;
};

int Ctx::getTurn()
{
	return turn;
};

void Ctx::Update(float dt)
{
	//todo
};

Rectangle Rectangles::getMarquisSrcRec(float m_off)
{
	float x         = 0.0f;
	float y         = 0.0 + (32.0 * m_off);
	float width     = 64.0f;
	float height    = 16.0f;
	
	Rectangle rec = { x, y, width, height };
	
	return (rec);
};

Rectangle Rectangles::getBackdropSrcRec(float b_off)
{
	float x         = 80.0f * (std::fmod(b_off, 2.0f));
	float y         = 60.0f * (std::floor(b_off / 2.0f));
	float width     = 80.0f;
	float height    = 60.0f;

	Rectangle rec = { x, y, width, height };

	return (rec);
};

Rectangle Rectangles::getSpriteSrcRec(float s_off, float disposition, float expression, float movement)
{
	float x         = 0.0f + (16.0f * expression) + (16.0f * movement);
	float y         = 0.0f + (32.0f * s_off) + (16.0f * disposition);
	float width     = 16.0f;
	float height    = 16.0f;

	Rectangle rec = { x, y, width, height };

	return (rec);
};

Rectangle Rectangles::getDirectionalSrcRec(float d_off)
{
	float x         = 0.0f;
	float y         = 0.0f * (48.0f * d_off);
	float width     = 48.0f;
	float height    = 48.0f;

	Rectangle rec = { x, y, width, height };

	return (rec);
};


Rectangle Rectangles::getCompassNSrcRec(float c_off)
{
	float x         = 0.0f;
	float y         = 0.0f * (16.0f * c_off);
	float width     = 8.0f;
	float height    = 8.0f;

	Rectangle rec = { x, y, width, height };

	return (rec);
};


Rectangle Rectangles::getCompassSSrcRec(float c_off)
{
	float x         = 8.0f;
	float y         = 0.0f * (16.0f * c_off);
	float width     = 8.0f;
	float height    = 8.0f;

	Rectangle rec = { x, y, width, height };

	return (rec);
};


Rectangle Rectangles::getCompassESrcRec(float c_off)
{
	float x         = 0.0f;
	float y         = 0.0f * (16.0f * c_off) + 8.0f;
	float width     = 8.0f;
	float height    = 8.0f;

	Rectangle rec = { x, y, width, height };

	return (rec);
};


Rectangle Rectangles::getCompassWSrcRec(float c_off)
{
	float x         = 8.0f;
	float y         = 0.0f * (16.0f * c_off) + 8.0f;
	float width     = 8.0f;
	float height    = 8.0f;

	Rectangle rec = { x, y, width, height };

	return (rec);
};

Rectangle Rectangles::getScoreSrcRec()
{
	float x         = 0.0f;
	float y         = 0.0f;
	float width     = 80.0f;
	float height    = 60.0f;

	Rectangle rec = { x, y, width, height };

	return (rec);
};



