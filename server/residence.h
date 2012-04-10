#ifndef RESIDENCE_H
#define RESIDENCE_H
#include "monopoly.h"
#include "property.h"

#include <string>
#include <boost/array.hpp>

using boost::array;
using std::string;

namespace mg = monopoly::game;

class mg::residence : mg::property {
public:
	residence();
	residence(int price, int mortgage, int space, string name, array<int, 6> rents, int monopoly_mult, int house_price, int hotel_price, monopoly::COLOR col);
private:
	int get_rent(mg::player *, int);
	array<int, 6> rent;
	int monopoly_multiplier;
	int house_price;
	int hotel_price;
	int num_houses;
	monopoly::COLOR color;
};

#endif
