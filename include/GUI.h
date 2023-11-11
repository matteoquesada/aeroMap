#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
using namespace std;

#include "MapOverlay.h"



class GUI {

public:

	// MAP BUTTON-SPRITE
	Texture map_texture;
	Sprite map_sprite;

	// MAP OVERLAY
	MapOverlay map_overlay;

	// PALLETE BUTTONS
	Texture red_texture; Texture blue_texture; Texture green_texture; Texture yellow_texture; Texture orange_texture;
	Sprite red_sprite; Sprite blue_sprite; Sprite green_sprite; Sprite yellow_sprite; Sprite orange_sprite;

	// DOCK BUTTONS
	Texture create_route_texture; Texture delete_route_texture; Texture delete_mode_off_texture; Texture delete_mode_on_texture;  Texture save_texture; Texture load_texture;
	Sprite create_route_sprite; Sprite delete_route_sprite; Sprite delete_mode_off_sprite; Sprite delete_mode_on_sprite; Sprite save_sprite; Sprite load_sprite;


	GUI();

	GUI(RenderWindow& window);

	void initializeTextureAndSprite(Texture& texture, Sprite& sprite, string dir, int x, int y, float x_scale, float y_scale);
	
	void draw(RenderWindow& window);

	void handleInput(sf::Event& event);

	bool handleMouseClick(int x, int y, const sf::Sprite& button);

	bool isInsideButton(int x, int y, const sf::Sprite& button);

};