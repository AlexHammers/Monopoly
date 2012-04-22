#ifndef MONOPOLY_HPP_
#define MONOPOLY_HPP_

#define MaxNumOfPlayers 6
#define MaxBoardSize 40

#include <string>

// Enums
enum SpaceType{_Property, _Railroad, _Utility,
                _IncomeTax, _LuxuryTax, _CommunityChest,
               _Chance, _Go, _Jail, _FreeParking, _GoToJail};
// End enums

// Structs
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
const int payOut; //Can be + or -
};
// End Structs

<<<<<<< HEAD
// Variables
=======
//	Variables
>>>>>>> 48538659540f257439bac2b97abb43a75a6f5703
extern int numOfPlayers;
extern int curPlayer;
extern Space board[MaxBoardSize];
extern Player players [MaxNumOfPlayers];
<<<<<<< HEAD
// End Variables
=======
//	End Variables
>>>>>>> 48538659540f257439bac2b97abb43a75a6f5703

// Functions
void initGame(int numPlayers);
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
bool evaluateJail(int dice1, int dice2);
// End Functions

#endif /* MONOPOLY_HPP_ */
