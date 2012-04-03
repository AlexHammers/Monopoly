#ifndef PROPERTY_H
#define PROPERTY_H
#include "monopoly.h"
namespace monopoly{
namespace game{
class property{
public:
property();
property(int price, int house_price, int hotel_price, 
		int mortgage_value, int rent[], monopoly::color);
private:
int price;
int house_price;
int hotel_price;
int rent[];
int mortgage_value;
monopoly::COLOR color;
};
};
};

#endif
