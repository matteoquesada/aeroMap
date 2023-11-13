#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

#include "../include/GUI.h"

// THE GUI BASICALLY HANDLES THE OVERALL GAME UI (BUTTONS, MAP, ETC)
// IT ALSO HANDLES THE USER INPUT ON TOP OF THE UI AS A LAYER WITH THE MEHTOD handleInput()
// THE GUI IS A COMPOSITION OF THE MAP OVERLAY AND THE UI ITSELF

int main() {

    RenderWindow window(VideoMode(1280, 720), "AeroMap v0.3 ALPHA");
    window.setFramerateLimit(144);

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
