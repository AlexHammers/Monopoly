#ifndef MONOPOLY_HPP_
#define MONOPOLY_HPP_

#define MaxNumOfPlayers 4
#define MaxBoardSize	40

//	Enums
enum SpaceType{Property, Railroad, Utility,
	 	 	   IncomeTax, LuxuryTax, CommunityChest,
	 	 	   Chance, Go, Jail, FreeParking, GoToJail};
//	End enums

// 	Structs
struct Player
{
	int money;
	int curPos;
	int numOfUtilities;
	int numOfRailroads;
	bool inJail;
	int inJailCounter;
};

struct Space
{
	const std::string name;
	const SpaceType spaceType;
	const int cost;
	const int rent[6];
	const int costPerHouse;
	const int groupedWith1;
	const int groupedWith2;
	int numOfHouses;
	int owner;
};

struct Cards
{
	const std::string name;
	const int payOut;	//Can be + or -
};
//	End Structs

//	Variables
Player players[MaxNumOfPlayers];
Space board[MaxBoardSize];
int curPlayer;
int numOfPlayers;
//	End Variables

//	Functions
void Move(int numOfSpaces);
void PayRent(int rent);
void Property(int curPos);
void Railroad(int numOfRailroadsOwned);
void Utility(int numOfUtilitiesOwned);
void IncomeTax();
void LuxuryTax();
void CommunityChest();
void Chance();
void Go();
void GoToJail();
//	End Functions

#endif /* MONOPOLY_HPP_ */
