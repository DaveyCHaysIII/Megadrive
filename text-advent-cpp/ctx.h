#pragma once
#include <raylib.h>
#include "defines.h"
#include "timer.h"


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
};

struct Textures
{
	//todo

	void set_textures()
	{
		//todo
	}
};

struct Rectangles
{
	// marquis
	// backdrop
	// sprites
	// directional
	// N
	// S
	// E
	// W
	// score

	Rectangle getMarquisSrcRec(float m_off);
	Rectangle getBackdropSrcRec(float b_off);
	Rectangle getSpriteSrcRec(float s_off, float disposition, float expression, float movement);
	Rectangle getDirectionalSrcRec(float d_off);	
	Rectangle getCompassNSrcRec(float c_off);
	Rectangle getCompassSSrcRec(float c_off);
	Rectangle getCompassESrcRec(float c_off);
	Rectangle getCompassWSrcRec(float c_off);
	Rectangle getScoreSrcRec();

};

class Ctx {

	private:
		enum class state { SPLASH, GAME, CREDITS };
		state gamestate;
		int turn;

	public:
		void Init(int arg);
		state getState();
		int getTurn();
		void Update(float dt);
		float m_off;
		float s_off;
		float b_off;
		float d_off;
		float c_off;
		float disposition;
		float expression;
		float movement;

		Colors colors;
		Textures textures;
		Rectangles rectangles;
};
