#include "splash.h"
#include "timer.h"

void Splash::Update(float dt)
{
	animation_timer.Update(dt);
}

void Splash::Draw(ctx)
{
	//this needs work, taken from the C version
	Rectangle marquis_dest = { 256.0f, 200.0f, 768.0f, 192.0f };
	Rectangle sprite_dest = { 350.0f, 415.0f, 128.0f, 128.0f };
	Rectangle marquis_source = ctx->rectangles[MARQUIS_SOURCE];
	Rectangle sprite_source = ctx->rectangles[LILGREEN_BASE_SOURCE];
	Texture2D texture = ctx->textures[MARQUIS];
	Texture2D sprite = ctx->textures[SPRITES];

	DrawText("Press [SPACE] to play!", 465, 550, 30, ctx.colors[NARRATOR_TEXT]);
	DrawText("I'm ready for my next adventure!", 433, 420, 30, ctx.colors[LILGREEN_TEXT]);
	DrawTexturePro(texture, marquis_source, marquis_dest, (Vector2){ 0, 0}, 0, WHITE);
	DrawTexturePro(sprite, sprite_source, sprite_dest, (Vector2){sprite_dest.width /2, sprite_dest.height / 2}, -30, WHITE);
}
