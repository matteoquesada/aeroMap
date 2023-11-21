#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

#include "../include/GUI.h"

// THE GUI BASICALLY HANDLES THE OVERALL GAME UI (BUTTONS, MAP, ETC)
// THE MapOverlay HANDLES THE ROUTES AND NODES AND THEIR DRAWING, ALMOST MIMICKING THE STRUCTURE OF A PHONE SCREEN
// THE GUI IS A COMPOSITION OF THE MAP OVERLAY AND THE UI ITSELF

// PROFE, PERDON POR LO DE HACER LA ESTRUCTURA CON MI PROPIO VECTOR, ESTABA MUY MUERTO CON CALCULO
// Y YA HABIENDO GASTADO 3 DIAS INTENTANDO MODIFICAR LA ESTRUCTURA GENERAL PARA LOGRAR HACER EL NODO TEMPLATE 
// ME GENERO DEMASIADOS PROBLEMAS, ESPERO QUE AL MENOS OBSERVE QUE APRENDI A HACER UN VECTOR DINAMICO TEMPLATE
// Y MANEJARLO CON UN OPERATOR[] Y DIFERENTES METODOS PICHUDOS <3 TENGO UNA COPIA DE UNA BETA CON ESTRUCTURA NODO TEMPLATE PERO
// NO COMPILA POR ERRORES DEMASIADO BIZARROS CON ERRORES DE CARACTERES ASIATICOS, PREFIERO DARLE ALGO UN POCO MAS REFINADO
// -10 PUNTOS NADA MAS =(? VEA QUE LO HICE RELATIVAMENTE DETALLADO EN TERMINOS DE UI Y FUNCIONALIDAD

//
// SI ES QUE PASO PROGRA ES CON EL DERECHO DE DECIR QUE NO DEPENDO DE UNA IA PARA HACER UN PROYECTO
//

int main() {

    RenderWindow window(VideoMode(1280, 720), "AeroMap v1.0 ALPHA");
    window.setFramerateLimit(15); // LIMIT THE FPS TO 15 TO SAVE RESOURCES 

    GUI gui(window); // GUI OBJECT - BASE OF THE ENTIRE UI AND ITS HANDLING

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            else if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    gui.handle_input(event);
                }
            }
        }

        // UPDATE CYCLE OF THE GUI
        window.clear();
        gui.draw(window);
        window.display();
    }

    return 0;
}
