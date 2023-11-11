#include "../include/EventHandler.h"

EventHandler::EventHandler() {
}

bool EventHandler::isInsideMapArea(int x, int y) {
    // Define the map area boundaries based on your specific layout.
    int mapAreaX1 = 0;/* define the top-left X-coordinate */;
    int mapAreaY1 = 0;/* define the top-left Y-coordinate */;
    int mapAreaX2 = 1080/* define the bottom-right X-coordinate */;
    int mapAreaY2 = 1500/* define the bottom-right Y-coordinate */;

    return (x >= mapAreaX1 && x <= mapAreaX2 && y >= mapAreaY1 && y <= mapAreaY2);
}