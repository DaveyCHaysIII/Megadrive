#pragma once

#include <raylib.h>
#include <iostream>
#include "defines.h"
#include "timer.h"
#include "ctx.h"

class Splash {
	public:
		void Update(float dt);
		void Draw(const Ctx& ctx);
	private:
		Timer animation_timer;
};
