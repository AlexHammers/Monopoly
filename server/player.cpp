#include "player.h"
#include <stdexcept>

using std::range_error;

using namespace monopoly::game;

player::player() {
	owned_utilities = 0;
	owned_railroads = 0;
}


void player::sell_utility(){
	if(owned_utilities)
		owned_utilities--;
	else
		throw range_error("player::sell_utility: Player does not own any utilities");
}

void player::sell_railroad(){
	if(owned_railroads)
		owned_railroads--;
	else
		throw range_error("player::sell_railroad: Player does not own any railroads");
}
