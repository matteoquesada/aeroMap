#include "../include/Routes.h"

Routes::Routes() : selected_route(-1) {
}

void Routes::add_route() {
	routes.push_back(Route());
}

