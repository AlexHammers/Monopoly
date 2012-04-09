#ifndef UTILITY_H
#define UTILITY_H
#include "monopoly.h"
#include "property.h"
#include "player.h"
#include <boost/array.hpp>
#include <string>

using std::string;

class monopoly::game::utility : public monopoly::game::property{
public:
	utility();
	utility(int price, int mortgage_value, int space, string name,
			boost::array<int, 3> mults);

private:
	int get_rent(monopoly::game::player * actor, int dice_roll);
	boost::array<int, 3> rent_mults;
};

#endif
