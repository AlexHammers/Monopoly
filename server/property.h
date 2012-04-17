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
  
  bool action(monopoly::game::player * actor);
 protected:
  int price;
  int mortgage_value;
  virtual int get_rent(monopoly::game::player * actor, int dice_roll) =0;
};

#endif
