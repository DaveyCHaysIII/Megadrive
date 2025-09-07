#pragma once
#include <raylib.h>
#include "defines.h"
#include "timer.h"


struct Offsets
{
	float m_off; //0-5
	float s_off;
	float d_off;
	float b_off; //0-3
	float disposition; //0-1
	float expression; //0-5
	float movement; //0-1

	void set_off(float m, float s, float d, float b)
	{
		m_off = m;
		s_off = s;
		d_off = d;
		b_off = b;
		disposition = 0;
		expression = 0;
		movement = 0;
	}
}

struct Colors
{
	Color background;
	Color dialogue;
	Color lilgreen_text;
	Color narrator_text;
	Color window_background;
	Color window_text;
	Color accent;

	void set_colors(Color b, Color d, Color l, Color n, Color wb, Color wt, Color a)
	{
		background        = b;
		dialogue          = d;
		lilgreen_text     = l;
		narrator_text     = n;
		window_background = wb;
		window_text       = wt;
		accent            = a;
	}
}

struct Textures
{
	//todo

	void set_textures()
	{
		//todo
	}
}

struct Rectangles
{
	Rectangle marquis_source = {};
	Rectangle marquis
}

class Ctx {

	public:
		void Init()
		int getState();
		int getTurn();
		void Update(float dt);

		Offsets offsets;
		Colors colors;
		Textures textures;
		Rectangles rectangles;


	private:
		enum class state { SPLASH, GAME, CREDITS };
		int turn;
}
