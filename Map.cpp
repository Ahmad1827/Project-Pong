#include "Map.h"
#include "game.h"
#include <fstream>
#include "TextureManager.h"


const Uint8* keystates = SDL_GetKeyboardState(NULL);
int keypressed[50];
int speed = 12,direction=5;


Map::Map()
{
	ball = TextureManager::LoadTexture("pics\\ball.png");
	rightpad = TextureManager::LoadTexture("pics\\paddle.png");
	leftpad = TextureManager::LoadTexture("pics\\paddle.png");

	src[1].x = src[1].y = 0;
	src[1].w = src[1].h = 30;
	dest[1].h = dest[1].w = 30;
	dest[1].x = 385;
	dest[1].y = 305;

	src[2].x = src[2].y = 0;
	src[2].w = 30;
	src[2].h = 120;
	dest[2].w = 30;
	dest[2].h = 120;
	dest[2].x = 15;
	dest[2].y = 260;

	src[3].x = src[3].y = 0;
	src[3].w = 30;
	src[3].h = 120;
	dest[3].w = 30;
	dest[3].h = 120;
	dest[3].x = 1155;
	dest[3].y = 260;

}

void Map::Updater()
{
	if (keystates[SDL_SCANCODE_UP])
	{
		if (dest[3].y - 15 >= 11)
		{
			dest[3].y-=11;
		}
	}
	if (keystates[SDL_SCANCODE_DOWN])
	{
		if (dest[3].y+dest[3].h+ 11 <=631)
		{
			dest[3].y+= 11;
		}
	}
	if (keystates[SDL_SCANCODE_W])
	{
		if (dest[2].y - 11 >= 11)
		{
			dest[2].y -= 11;
		}
	}
	if (keystates[SDL_SCANCODE_S])
	{
		if (dest[2].y + dest[2].h + 11 <= 631)
		{
			dest[2].y += 11;
		}
	}
	dest[1].x += speed;
	dest[1].y += direction;
	if (dest[1].y  <dest[2].y + dest[2].h && dest[1].y +dest[1].h >dest[2].y && dest[1].x + speed < dest[2].x + dest[2].w)
	{
		speed = 12;
		direction = (dest[1].y+dest[1].h/2 - (dest[2].y + 60)) / 4;
	}
	if (dest[1].y<dest[3].y + dest[3].h && dest[1].y + dest[1].h>dest[3].y && dest[1].x + speed+dest[1].w > dest[3].x)
	{
		speed = -12;
		direction = (dest[1].y + dest[1].h / 2 - (dest[3].y + 60))  /4;
	}
	if (dest[1].y + 30 + direction > 640)
	{
		direction *=-1;
	}
	if (dest[1].y + direction < 0)
	{
		direction *=-1;
	}
	if (dest[1].x +30 + speed > 1200)
	{
		dest[1].x = 600 - dest[1].w / 2;
		dest[1].y = 320 - dest[1].h / 2;
		speed *=-1;
	}
	if (dest[1].x + speed < 0)
	{
		dest[1].x = 600 - dest[1].w / 2;
		dest[1].y = 320 - dest[1].h / 2;
		speed *=-1;
	}
	DrawMap();
}

void Map::LoadMap(int arr[20][25])
{
	for (int row = 0; row < 20; ++row)
	{
		for (int column = 0; column < 25; ++column)
		{
			map[row][column] = arr[row][column];
		}
	}
}

void Map::DrawMap()
{
	TextureManager::Draw(ball, src[1], dest[1]);
	TextureManager::Draw(leftpad, src[2], dest[2]);
	TextureManager::Draw(rightpad, src[3], dest[3]);
}

