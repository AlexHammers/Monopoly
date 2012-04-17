#ifndef MONOPOLY_HPP_
#define MONOPOLY_HPP_

#define MaxNumOfPlayers 6
#define MaxBoardSize	40

#include <string>

//	Enums
enum SpaceType{_Property, _Railroad, _Utility,
                _IncomeTax, _LuxuryTax, _CommunityChest,
               _Chance, _Go, _Jail, _FreeParking, _GoToJail};
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
  std::string name;
  SpaceType spaceType;
  int cost;
  int rent[6];
  int costPerHouse;
  int groupedWith1;
  int groupedWith2;
  int numOfHouses;
  int owner;
  int xCoord;
  int yCoord;
};

struct Cards
{
	const std::string name;
	const int payOut;	//Can be + or -
};
//	End Structs

//	Variables
extern int numOfPlayers;
extern int curPlayer;
extern Space board[MaxBoardSize];
extern Player players [MaxNumOfPlayers];
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
bool evalutateJail(int dice1, int dice2);
//	End Functions

#endif /* MONOPOLY_HPP_ */