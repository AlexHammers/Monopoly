#include "monopoly.h"
#include "player.h"
#include "bank.h"
#include "property.h"
#include "inventory.h"
#include "board_space.h"
#include "utility.h"
#include "railroad.h"
#include "residence.h"

#include <iostream>
#include <typeinfo>
#include <string>
#include <stdexcept>
#include <boost/array.hpp>

using std::invalid_argument;
using std::range_error;
using std::string;
using std::endl;
using std::cout;
using std::cerr;

using boost::array;

using namespace monopoly::game;

int main ()//int argc, char* argv[])
{
	cout << "Hello\n";
	array<int, 5> mults;
	mults[0] = 0;
	mults[1] = 4;
	mults[2] = 10;
	mults[3] = 30;
	mults[4] = 90;
	board_space *test = new railroad(100, 50, 8, "Bob", mults);
	player actor, owner;
	try{
		owner.sell_railroad();
	} catch(range_error re) {
		cerr << re.what() << endl;
	}
	cout << test->action(&owner) << endl;
	test->set_owner(&owner);
	cout << typeid(test).name() << endl;
	cout << typeid(*test).name() << endl;
	cout << test->get_space() << endl << test->get_name() << endl;
	try{
		test->action(NULL);
	} catch (invalid_argument ia) {
		cerr << ia.what() << endl;
	}
	cout << test->action(&actor) << endl;
	owner.buy_railroad();
	cout << test->action(&actor) << endl;
	owner.buy_railroad();
	cout << test->action(&actor) << endl;
	owner.buy_railroad();
	cout << test->action(&actor) << endl;
	owner.buy_railroad();
	cout << test->action(&actor) << endl;
	return 0;
}
