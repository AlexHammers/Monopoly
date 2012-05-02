#include "railroad.h"

using namespace monopoly::game;

railroad::railroad()
{
  rent[0] = 0;
  rent[1] = 0;
  rent[2] = 0;
  rent[3] = 0;
  rent[4] = 0;
}

railroad::railroad(int price, int mortgage, int space, string name, array<int, 5> rents) : property(price, mortgage, space, name)
{
  rent = rents;
}

int railroad::get_rent(player* actor, int dice_roll)
{
  dice_roll = dice_roll;
  if(owner == NULL || owner == actor)
    return 0;
  return rent[owner->num_owned_railroads()];
}
