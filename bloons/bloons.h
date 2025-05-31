#pragma once

#include <raylib.h>
#include <iostream>

#define SPAWNX_MAX 400
#define SPAWNX_MIN 880
#define SPAWNY_MAX 450
#define SPAWNY_MIN 600

class Bloon {
	public:
		Bloon();
		void Update();
		void Draw();
		void Reset();
		Vector2 getPosition();
		int getRadius();

		bool active;
		static void LoadBloonTexture(const char* filepath);
		static void UnloadBloonTexture();

	private:
		Vector2 position;
		float speed;
		float radius;
		Color color;
		static Texture2D texture;
};
