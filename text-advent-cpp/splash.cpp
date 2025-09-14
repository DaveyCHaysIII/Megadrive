#include "splash.h"
#include "timer.h"

void Splash::Update(float dt)
{
	animation_timer.Update(dt);
};

void Splash::Draw(const Ctx &ctx)
{
	Rectangle marquis_dest = { 256.0f, 200.0f, 768.0f, 192.0f };
	Rectangle sprite_dest = { 350.0f, 415.0f, 128.0f, 128.0f };
	Rectangle marquis_source = ctx.rectangles.marquis_source;
	Rectangle sprite_source = ctx.rectangles.lilgreen_base_source;
	Texture2D texture = ctx.textures.marquis;
	Texture2D sprite = ctx.textures.sprites;

	DrawText("Press [SPACE] to play!", 465, 550, 30, ctx.colors.narrator);
	DrawText("I'm ready for my next adventure!", 433, 420, 30, ctx.colors.lilgreen);
	DrawTexturePro(texture, marquis_source, marquis_dest, (Vector2){ 0, 0}, 0, WHITE);
	DrawTexturePro(sprite, sprite_source, sprite_dest, (Vector2){sprite_dest.width /2, sprite_dest.height / 2}, -30, WHITE);
};
