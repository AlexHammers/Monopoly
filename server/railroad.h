#ifndef RAILROAD_H
#define RAILROAD_H

#include "monopoly.h"
#include "property.h"

#include <boost/array.hpp>

using boost::array;
namespace mg = monopoly::game;

class monopoly::game::railroad : public monopoly::game::property {
 public:
  railroad();
  railroad(int price, int mortgage_value, int space, string name, array<int, 5> rents);
 private:
  int get_rent(mg::player*, int dice_roll);
  array<int, 5> rent;
};

#endif
