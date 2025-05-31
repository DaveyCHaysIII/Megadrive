#pragma once

#include "bloons.h"
#include <vector>
#include <stdio.h>

class Game {

	public:
		Game();
		void Update();
		void Draw();
		void LogScore();
		void DrawScore();
		void DrawTime();

	private:
		int score = 0;
		int GameTime = 60;
		float TimeAccumulator = 0.0f;
		std::vector<Bloon> bloons;
		float spawntimer = 0.0f;
		float spawninterval = 1.0f;
};

