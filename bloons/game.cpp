#include "game.h"

void Game::DrawScore()
{
	int displayScore = (score > 99) ? 99 : score;

	char scoreText[16];

	snprintf(scoreText, sizeof(scoreText), "Score: %02d", displayScore);

	float text_x = 860.0f;
	float text_y = 680.0f;
	int text_size = 20;
	Color text_color = BLACK;
	DrawText(scoreText, text_x, text_y, text_size, text_color);
}

void Game::DrawTime()
{
	int displayTime = GameTime;

	char timeText[16];

	snprintf(timeText, sizeof(timeText), "%02d", displayTime);

	float text_x = 610.0f;
	float text_y = 160.0f;
	int text_size = 40;
	Color text_color = GRAY;
	DrawText(timeText, text_x, text_y, text_size, text_color);
}

Game::Game()
{
	bloons.resize(10);
}

void Game::LogScore()
{
	std::cout << "Score: " << score << "\n";
}

void Game::Update(float dt)
{
	for (Bloon& b : bloons)
	{
		Vector2 position = b.getPosition();
		int radius = b.getRadius();

		if(CheckCollisionPointCircle(GetMousePosition(), position, radius) &&
		IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
		b.active)
		{
			score++;
			LogScore();
			b.Reset();
		}
		b.Update();
	}

	spawntimer += dt;
	if (spawntimer >= spawninterval)
	{
		spawntimer = 0.0f;

		for (Bloon& b : bloons)
		{
			if (!b.active)
			{
				b.active = true;
				break;
			}
		}
	}

	TimeAccumulator += dt;
	if (TimeAccumulator >= 1.0f)
	{
		if (GameTime > 0)
			GameTime--;

		TimeAccumulator = 0.0f;
	}
}

void Game::Draw()
{

	for (Bloon& b : bloons)
		b.Draw();

	DrawScore();
	DrawTime();
}

int Game::GetGameTime()
{
	return GameTime;
}
