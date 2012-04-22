#include "board_space.h"
using namespace monopoly::game;

board_space::board_space(){
	name = "";
	space_num = -1;
}

board_space::board_space(int space, string n)
{
	space_num = space;
	name = n;
}
