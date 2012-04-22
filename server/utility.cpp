#include "utility.h"
using namespace monopoly::game;

utility::utility()
{
	rent_mults[0] = 0;
	rent_mults[1] = 0;
	rent_mults[2] = 0;
}

utility::utility(int price, int mortgage_value, int space,
	string name, boost::array<int, 3> mults) :
	property(price, mortgage_value, space, name)
{
	rent_mults = mults;
}

int utility::get_rent(player* actor, int dice_roll)
{
	if(owner == NULL || owner == actor)
		return 0;
	return rent_mults[owner->num_owned_utilities()] * dice_roll;
}
