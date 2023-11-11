#include "../include/GUI.h"


GUI::GUI() {
}

// THE GUI BASICALLY HANDLES THE OVERALL GAME UI
GUI::GUI(RenderWindow& window) {
	initializeTextureAndSprite(map_texture, map_sprite, "assets/wallpaper/map.bmp", 0, 0, 1.0, 1.0); // Texture, Sprite, Directory, x cord, y cord, x scale, y scale
	initializeTextureAndSprite(red_texture, red_sprite, "assets/UI/red.bmp", 1180, 622, 1.0, 1.0);
	initializeTextureAndSprite(blue_texture, blue_sprite, "assets/UI/blue.bmp", 1110, 622, 1.0, 1.0);
	initializeTextureAndSprite(green_texture, green_sprite, "assets/UI/green.bmp", 1040, 622, 1.0, 1.0);
	initializeTextureAndSprite(yellow_texture, yellow_sprite, "assets/UI/yellow.bmp", 970, 622, 1.0, 1.0);
	initializeTextureAndSprite(orange_texture, orange_sprite, "assets/UI/orange.bmp", 900, 622, 1.0, 1.0);
}

void GUI::initializeTextureAndSprite(Texture& texture, Sprite& sprite, string dir, int x, int y, float x_scale, float y_scale) {
	texture.loadFromFile(dir);
	sprite.setTexture(texture);
	sprite.setScale(x_scale, y_scale);
	sprite.setPosition(x, y);
}

void GUI::draw(RenderWindow& window) {

	// MAP - UI BACKGROUND
	window.draw(map_sprite);

	// PALLETE OF COLORS
	window.draw(red_sprite);
	window.draw(blue_sprite);
	window.draw(green_sprite);
	window.draw(yellow_sprite);
	window.draw(orange_sprite);
}

// WORKS AS A HANDLE LAYER FOR USER INPUT ON TOP OF THE UI	
void GUI::handleInput(sf::Event& event) {
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {

			// CHECK IF THE MOUSE CLICKED ON A PALLETE COLOR
			if (handleMouseClick(event.mouseButton.x, event.mouseButton.y, red_sprite)) {
				cout << "RED" << endl;
			}
			else if (handleMouseClick(event.mouseButton.x, event.mouseButton.y, blue_sprite)) {
				cout << "BLUE" << endl;
			}
			else if (handleMouseClick(event.mouseButton.x, event.mouseButton.y, green_sprite)) {
				cout << "GREEN" << endl;
			}
			else if (handleMouseClick(event.mouseButton.x, event.mouseButton.y, yellow_sprite)) {
				cout << "YELLOW" << endl;
			}
			else if (handleMouseClick(event.mouseButton.x, event.mouseButton.y, orange_sprite)) {
				cout << "ORANGE" << endl;
			}
			else if (handleMouseClick(event.mouseButton.x, event.mouseButton.y, map_sprite))
			{
				if (event.mouseButton.x > 0 && event.mouseButton.x < 1280 && event.mouseButton.y > 0 && event.mouseButton.y < 600) {
					cout << "MAP" << endl;
				}
				else {
					cout << "OUTSIDE MAP - should handle different button" << endl;
				}
			}



		}
	}
}

bool GUI::handleMouseClick(int x, int y, const sf::Sprite& button) {
	if (isInsideButton(x, y, button)) {
		// Handle action for the clicked button.
		return true; // Indicate that a button was clicked.
	}
	return false; // No button was clicked.
}

bool GUI::isInsideButton(int x, int y, const sf::Sprite& button) {
	sf::FloatRect bounds = button.getGlobalBounds();
	return bounds.contains(static_cast<float>(x), static_cast<float>(y));
}