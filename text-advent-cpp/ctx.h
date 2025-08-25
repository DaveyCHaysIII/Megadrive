#pragma once
#include <raylib.h>
#include "defines.h"
#include "timer.h"

class Ctx {

	public:
		 getState();
		 getTurn();
		 void Update(float dt);

	private:
		enum class state { SPLASH, GAME, CREDITS };
		enum class turn { };
		Timer timer;

}
