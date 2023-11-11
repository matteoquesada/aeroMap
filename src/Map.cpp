#include "../include/Map.h"

Map::Map() {

    // Constructor implementation, if needed
}

Map::Map(const char* filename) {
    
    try {
        map.load(filename);
    }
    catch (CImgException& e) {
        std::cerr << "Failed to load map: " << e.what() << std::endl;
    }

	// Constructor implementation, if needed
};





