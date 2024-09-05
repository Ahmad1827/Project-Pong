#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>


class Map {
public:
	Map();
	

	void LoadMap(int arr[20][25]);
	void DrawMap();
	void Updater();
private:
	SDL_Rect src[50], dest[50];
	SDL_Texture* leftpad;
	SDL_Texture* rightpad;
	SDL_Texture* ball;
	int map[20][25];
};