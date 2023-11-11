#include <iostream>
#include "../include/GUI.h"
#include <SFML/Graphics.hpp>
using namespace sf;

int main() {

    RenderWindow window(VideoMode(1280, 720), "SFML works!");
    window.setFramerateLimit(60);

    GUI gui(window);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            else if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    gui.handleInput(event);
                }
            }
        }

        window.clear();
        gui.draw(window);
        window.display();
    }

    return 0;
}
