#ifndef UTILITY_H
#define UTILITY_H
#include "monopoly.h"
#include "property.h"
#include <boost/array.hpp>
#include <string>

using std::string;

class monopoly::game::utility : public monopoly::game::property{
public:
	utility();
	utility(int price, int mortgage_value, int space, string name, boost::array<int, 2> mults);

private:
	int get_rent();
	boost::array<int, 2> rent_mults;
};

#endif
