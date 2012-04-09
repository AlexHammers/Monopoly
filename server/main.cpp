#include "monopoly.h"
#include "player.h"
#include "bank.h"
#include "property.h"
#include "inventory.h"
#include "board_space.h"
#include "utility.h"

#include <iostream>
#include <typeinfo>
#include <string>
#include <stdexcept>

using std::invalid_argument;
using std::string;
using std::endl;
using std::cout;
using std::cerr;

int main ()//int argc, char* argv[])
{
	std::cout << "Hello\n";
	monopoly::game::board_space *test = new monopoly::game::utility;
	monopoly::game::player actor, owner;
	test->set_name("Test");
	test->set_space(5);
	test->set_owner(&actor);
	cout << typeid(test).name() << endl;
	cout << typeid(*test).name() << endl;
	cout << test->get_space() << endl << test->get_name() << endl;
	try{
		test->action(NULL);
	} catch (invalid_argument ia) {
		cerr << ia.what() << endl;
	}
	cout << test->action(&actor) << endl;
	return 0;
}
