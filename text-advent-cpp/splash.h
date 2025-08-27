#pragma once

#include <raylib.h>
#include <iostream>
#include "defines.h"
#include "timer.h"

class Splash {
	public:
		void Update(float dt);
		void Draw();
	private:
		Timer animation_timer;
};
