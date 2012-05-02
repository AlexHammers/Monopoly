#include "residence.h"

using namespace monopoly::game;

residence::residence()
{
  rent[0] = 0;
  rent[1] = 0;
  rent[2] = 0;
  rent[3] = 0;
  rent[4] = 0;
  rent[5] = 0;
  monopoly_multiplier = 0;
  house_price = 0;
  hotel_price = 0;
  num_houses = 0;
}

residence::residence(int price, int mortgage, int space, string name, array<int, 6> rents, int monopoly_mult, int house_p, int hotel_p, monopoly::COLOR col) : property (price, mortgage, space, name)
{
  rent = rents;
  monopoly_multiplier = monopoly_mult;
  house_price = house_p;
  hotel_price = hotel_p;
  num_houses = 0;
  color = col;
}

int residence::get_rent(mg::player* actor, int dice_roll)
{
  dice_roll = dice_roll;
  if(owner == NULL || actor == owner)
    return 0;
  if(num_houses)
    return rent[num_houses];
  if(owner->owns_monopoly(color))
    return rent[0] * monopoly_multiplier;
  else return rent[0];
}
