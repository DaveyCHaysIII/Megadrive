#pragma once

#include "bloons.h"
#include <vector>
#include <stdio.h>

class Game {

	public:
		Game();
		void Update(float dt);
		void Draw();
		void LogScore();
		void DrawScore();
		void DrawTime();
		int GetGameTime();
	private:
		int score = 0;
		int GameTime = 5;
		float TimeAccumulator = 0.0f;
		std::vector<Bloon> bloons;
		float spawntimer = 0.0f;
		float spawninterval = 1.0f;
};

