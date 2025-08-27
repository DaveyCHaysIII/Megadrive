#pragma once
#include <raylib.h>
#include "defines.h"
#include "timer.h"

class Ctx {

	public:
		getState();
		getTurn();
		void Update(float dt);

		float m_off; //0-5
		float s_off;
		float d_off;
		float b_off; //0-3
		float disposition; //0-1
		float expression; //0-5
		float movement; //0-1

		std::vector<Color> colors;
		std::vector<Texture2D> textures;
		std::vector<Timer> timers;
		std::vector<Rectangle> rectangles;

	private:
		enum class state { SPLASH, GAME, CREDITS };
		enum class turn { };
}
