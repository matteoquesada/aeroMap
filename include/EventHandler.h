#pragma once

#include "MapOverlay.h"

class EventHandler {

    MapOverlay overlay;
    
public:

    EventHandler();

    void handleMouseClick(int x, int y) {
        if (isInsideMapArea(x, y)) {
            // The click is inside the map area.
            //overlay.create_route(x, y);
        }
        else if (isInsideButton(x, y)) {
            // The click is inside a button or color palette.
            int buttonId = determineButtonId(x, y);
            //overlay.handleButtonClick(buttonId);
        }
    }

    bool isInsideMapArea(int x, int y);

    bool isInsideButton(int x, int y);

    int determineButtonId(int x, int y);

};
