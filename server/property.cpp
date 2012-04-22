#include "property.h"
#include <stdexcept>
#include "iostream"

using namespace monopoly::game;
using std::invalid_argument;
using std::cout;
using std::endl;

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

bool property::action(monopoly::game::player * actor)
{
	if(actor == NULL)
		throw invalid_argument("property::action: cannot accept NULL player argument");
	else if (owner == NULL)
		return true;
	else if(owner == actor)
		return false;
	else {
		int rent = get_rent(actor, 10);
		cout << "Rent: " << rent << endl;
		return false;
	}
}
