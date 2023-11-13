#include "../include/GUI.h"

GUI::GUI() {
}

// CONSTRUCTOR THAT INITIALIZES THE GUI WITH THE MAP AND THE UI
GUI::GUI(RenderWindow& window) {
	initialize_texture_and_sprite(map_texture, map_sprite, "assets/wallpaper/map.bmp", 0, 0, 1.0f, 1.0f); initialize_texture_and_sprite(orange_texture, orange_sprite, "assets/UI/orange.bmp", 900, 622, 1.0f, 1.0f);
	initialize_texture_and_sprite(blue_texture, blue_sprite, "assets/UI/blue.bmp", 1110, 622, 1.0f, 1.0f); initialize_texture_and_sprite(red_texture, red_sprite, "assets/UI/red.bmp", 1180, 622, 1.0f, 1.0f);
	initialize_texture_and_sprite(green_texture, green_sprite, "assets/UI/green.bmp", 1040, 622, 1.0f, 1.0f); initialize_texture_and_sprite(yellow_texture, yellow_sprite, "assets/UI/yellow.bmp", 970, 622, 1.0f, 1.0f);
	initialize_texture_and_sprite(create_route_texture, create_route_sprite, "assets/UI/create_route.bmp", 15, 615, 0.35f, 0.35f); initialize_texture_and_sprite(delete_route_texture, delete_route_sprite, "assets/UI/delete_route.bmp", 15, 660, 0.35f, 0.35f);
	initialize_texture_and_sprite(delete_mode_off_texture, delete_mode_off_sprite, "assets/UI/delete_mode_off.bmp", 685, 615, 0.35f, 0.35f); initialize_texture_and_sprite(delete_mode_on_texture, delete_mode_on_sprite, "assets/UI/delete_mode_on.bmp", 0, 0, 0.35f, 0.35f);
}

// INITIALIZES A TEXTURE AND A SPRITE WITH THE GIVEN PARAMETERS
void GUI::initialize_texture_and_sprite(Texture& texture, Sprite& sprite, string dir, int x, int y, float x_scale, float y_scale) {
	texture.loadFromFile(dir);
	sprite.setTexture(texture);
	sprite.setScale(x_scale, y_scale);
	sprite.setPosition(x, y);
}

// DRAWS THE GUI
void GUI::draw(RenderWindow& window) {

	// MAP - UI BACKGROUND
	window.draw(map_sprite);

	// DRAW THE MAP OVERLAY WITH ALL THE ROUTES AND NODES
	map_overlay.draw(window);

	// PALLETE OF COLORS
	window.draw(red_sprite); window.draw(blue_sprite);
	window.draw(green_sprite); window.draw(yellow_sprite);
	window.draw(orange_sprite);

	// DOCK OF BUTTONS
	window.draw(create_route_sprite);
	window.draw(delete_route_sprite);
	
	// DELETE MODE BEHAVIOR
	// MOVES OUT OF THE SCREEN WHEN NOT ACTIVE - MAKING IT INVISIBLE AND UNCLICKABLE
	if (map_overlay.delete_mode) {
		delete_mode_on_sprite.setPosition(685, 615);
		delete_mode_off_sprite.setPosition(-1000, -1000);
		window.draw(delete_mode_on_sprite);
	}
	else {
		delete_mode_off_sprite.setPosition(685, 615);
		delete_mode_on_sprite.setPosition(-1000, -1000);  // Move offscreen when not visible
		window.draw(delete_mode_off_sprite);
	}
}

// WORKS AS A HANDLE LAYER FOR USER INPUT ON TOP OF THE UI	
void GUI::handle_input(Event& event) {
	if (event.type == Event::MouseButtonPressed) {
		if (event.mouseButton.button == Mouse::Left) {

			// CHECK IF THE MOUSE CLICKED ON A PALLETE COLOR
			if (handle_mouse_click(event.mouseButton.x, event.mouseButton.y, red_sprite)) {
				map_overlay.change_route_color(Color::Red);
				cout << "RED" << endl;
			}
			else if (handle_mouse_click(event.mouseButton.x, event.mouseButton.y, blue_sprite)) {
				map_overlay.change_route_color(Color::Blue);
				cout << "BLUE" << endl;
			}
			else if (handle_mouse_click(event.mouseButton.x, event.mouseButton.y, green_sprite)) {
				map_overlay.change_route_color(Color::Green);
				cout << "GREEN" << endl;
			}
			else if (handle_mouse_click(event.mouseButton.x, event.mouseButton.y, yellow_sprite)) {
				map_overlay.change_route_color(Color::Yellow);
				cout << "YELLOW" << endl;
			}
			else if (handle_mouse_click(event.mouseButton.x, event.mouseButton.y, orange_sprite)) {
				map_overlay.change_route_color(Color(255, 165, 0));
				cout << "ORANGE" << endl;
			}

			// CHECK IF THE MOUSE IS ON A BUTTON OF THE DOCK (outside the map)
			else if (handle_mouse_click(event.mouseButton.x, event.mouseButton.y, create_route_sprite)) {
			cout << "CREATE ROUTE" << endl;
			map_overlay.create_route();
			}
			else if (handle_mouse_click(event.mouseButton.x, event.mouseButton.y, delete_route_sprite)) {
				cout << "DELETE ROUTE" << endl;
			}
			else if (handle_mouse_click(event.mouseButton.x, event.mouseButton.y, delete_mode_off_sprite)) {
				cout << "DELETE MODE OFF" << endl;
				map_overlay.change_delete_mode();
			}
			else if (handle_mouse_click(event.mouseButton.x, event.mouseButton.y, delete_mode_on_sprite)) {
				cout << "DELETE MODE ON" << endl;
				map_overlay.change_delete_mode();
			}

			else if (handle_mouse_click(event.mouseButton.x, event.mouseButton.y, map_sprite)) {
				if (event.mouseButton.x > 0 && event.mouseButton.x < 1280 && event.mouseButton.y > 0 && event.mouseButton.y < 600) {
					if (map_overlay.selected_route == -1) {
						cout << "NO ROUTE SELECTED" << endl;
						// handle no route selected
					}
					else {
						if (map_overlay.delete_mode) {
							cout << "DELETE NODE" << endl;
							map_overlay.delete_node(event.mouseButton.x, event.mouseButton.y);
						}
						else {
							cout << "ADD NODE" << endl;
							map_overlay.add_node(event.mouseButton.x, event.mouseButton.y);
						}
					}
				}
			}
		}
	}
}


// CHECKS IF THE MOUSE CLICKED ON A BUTTON (WORKS LIKE A "INTEGRADED MODULE" FOR EACH UI ELEMENT)
bool GUI::handle_mouse_click(int x, int y, const Sprite& button) {
	if (is_inside_button(x, y, button)) {
		return true; 
	}
	return false; 
}

bool GUI::is_inside_button(int x, int y, const Sprite& button) {
	FloatRect bounds = button.getGlobalBounds();
	return bounds.contains(static_cast<float>(x), static_cast<float>(y));
}