#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
using namespace std;



class GUI {

private:




public:

	Texture map_texture;
	Sprite map_sprite;

	Texture red_texture;
	Sprite red_sprite;

	Texture blue_texture;
	Sprite blue_sprite;

	Texture green_texture;
	Sprite green_sprite;

	Texture yellow_texture;
	Sprite yellow_sprite;

	Texture orange_texture;
	Sprite orange_sprite;

	GUI();

	GUI(RenderWindow& window);

	void initializeTextureAndSprite(Texture& texture, Sprite& sprite, string dir, int x, int y, float x_scale, float y_scale);
	
	void draw(RenderWindow& window);

	void handleInput(sf::Event& event);

	bool handleMouseClick(int x, int y, const sf::Sprite& button);

	bool isInsideButton(int x, int y, const sf::Sprite& button);

};