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
	test->set_name("Test");
	test->set_space(5);
	cout << typeid(test).name() << endl;
	cout << typeid(*test).name() << endl;
	cout << test->get_space() << endl << test->get_name() << endl;
	try{
		test->action(NULL);
	} catch (invalid_argument ia) {
		cerr << ia.what() << endl;
	}
	return 0;
}
