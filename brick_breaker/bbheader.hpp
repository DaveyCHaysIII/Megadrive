#ifndef BBHEADER_HPP_
#define BBHEADER_HPP_

/****** LIBRARIES ******/

#include <raylib.h>

/****** CLASSES ******/

namespace brickbreaker {
class Screen_Draw {
public:
	const char *game_title;
	float screen_width, screen_height;
	float viewport_width, viewport_height;
	Vector2 viewportCoord;

	Screen_Draw(const char *title, float screen_w, float screen_h, float viewport_w, float viewport_h)
	: game_title(title),
	  screen_width(screen_w),
	  screen_height(screen_h),
	  viewport_width(viewport_w),
	  viewport_height(viewport_h),
	  viewportCoord{(screen_width - viewport_width) / 2, (screen_height - viewport_width) / 2} {}

	void Init() {
		InitWindow(screen_width, screen_height, game_title);
	}

	void Scissor() {

	}

}; // Screen_Draw

} // namespace brick_breaker

#endif // BBHEADER_HPP_
