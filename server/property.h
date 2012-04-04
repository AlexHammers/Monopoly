#ifndef PROPERTY_H
#define PROPERTY_H
#include "monopoly.h"
#include "board_space.h"
#include <string>

using std::string;

class monopoly::game::property : public monopoly::game::board_space{
public:
	property();
	property(int price, int mortgage_value, int space, string name);

	bool action(monopoly::game::player * player);
protected:
	int price;
	int mortgage_value;
	monopoly::game::player * owner;
	virtual int get_rent() =0;
};

#endif
