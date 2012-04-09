#ifndef PLAYER_H
#define PLAYER_H
#include "monopoly.h"

namespace mg = monopoly::game;
using namespace mg;

class mg::player {
public:
	player(); 
	int num_owned_utilities() { return owned_utilities;};
	int num_owned_railroads() { return owned_railroads;};
private:
	int owned_utilities;
	int owned_railroads;
};

#endif
