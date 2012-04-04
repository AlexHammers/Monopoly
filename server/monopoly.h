#ifndef MONOPOLY_H
#define MONOPOLY_H
#define NULL	0
namespace monopoly {
enum COLOR {BROWN, LIGHT_BLUE, PINK, ORANGE, RED, YELLOW, GREEN, BLUE};
namespace server{
class server;
}
namespace game{
class bank;
class player;
class board;
class board_space;
class property;
class residence;
class utility;
class railroad;
class tax;
class income_tax;
class luxury_tax;
class draw;
class community_chest;
class chance;
class go;
class jail;
class free_parking;
class go_to_jail;
}
}

#endif
