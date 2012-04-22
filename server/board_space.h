#ifndef BOARD_SPACE_H
#define BOARD_SPACE_H

#include "monopoly.h"
#include "player.h"
#include <string>

using std::string;

class monopoly::game::board_space{
public:
	board_space();
	board_space(int space_num, string name);

	string get_name(){return name;};
	int get_space(){return space_num;};

	void set_owner(monopoly::game::player * new_owner) {owner = new_owner;};
	void set_name(string new_name) { name = new_name;};
	void set_space(int new_space) {space_num = new_space;};

	virtual bool action(monopoly::game::player * actor) =0;
protected:
	int space_num;
	string name;
	monopoly::game::player * owner;
};

#endif
