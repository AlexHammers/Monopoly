#ifndef PLAYER_H
#define PLAYER_H
#include "monopoly.h"

using monopoly::COLOR;

namespace mg = monopoly::game;
using namespace mg;

class mg::player {
public:
	player(); 

	int num_owned_utilities() { return owned_utilities;};
	int num_owned_railroads() { return owned_railroads;};

	void buy_utility() {owned_utilities++;};
	void sell_utility();

	void buy_railroad() {owned_railroads++;};
	void sell_railroad();

	bool owns_monopoly(COLOR col) {col = col; return true;};

private:
	int owned_utilities;
	int owned_railroads;
	
};

#endif
