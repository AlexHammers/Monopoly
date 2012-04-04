#include "property.h"
#include <stdexcept>

using namespace monopoly::game;
using std::invalid_argument;

property::property(){
	price = 0;
	mortgage_value = 0;
	owner = NULL;
}

property::property(int p, int mortgage, int space, string name) : board_space(space, name)
{
	price = p;
	mortgage_value = mortgage;
	owner = NULL;
}

bool property::action(monopoly::game::player * player)
{
	if(player == NULL)
		throw invalid_argument("action: cannot accept NULL player argument");
	if(owner == NULL)
		return true;
	
	return false;
}
