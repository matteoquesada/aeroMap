#pragma once

#include "../CImg/CImg.h"
#include <iostream>

using namespace std;
using namespace cimg_library;

class Map {
private:

	CImg <unsigned char> map;

public:

	Map();

	Map(const char* filename);

};