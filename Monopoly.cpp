#include "Monopoly.h"

void Move(int numOfSpaces)
{
    players[curPlayer].curPos += numOfSpaces;

    if (players[curPlayer].curPos >= 40)
    {
        players[curPlayer].curPos -= 40;

        //passed go
        if (players[curPlayer].curPos != 0)
        {
            players[curPlayer].money += 200;
        }
    }

    //do board space
    switch (board[players[curPlayer].curPos].spaceType)
    {
        case _Property:
            Property(players[curPlayer].curPos);
        case _Railroad:
            Railroad(players[curPlayer].numOfRailroads);
        case _Utility:
            Utility(players[curPlayer].numOfUtilities);
        case _IncomeTax:
            IncomeTax();
        case _LuxuryTax:
            LuxuryTax();
        case _CommunityChest:
            CommunityChest();
        case _Chance:
            Chance();
        case _Go:
            Go();
        case _Jail:
        case _FreeParking:
        case _GoToJail:
            GoToJail();
    }

    //increase player + evaluate
    curPlayer++;
    if (curPlayer == numOfPlayers)
    {
        curPlayer = 0;
    }
}

bool evaluateJail(int dice1, int dice2)
{
    if (!players[curPlayer].inJail)
    {
        return true;
    }
    else if (dice1 == dice2)
    {
        players[curPlayer].inJailCounter = 0;
        return true;
    }
    else if (players[curPlayer].inJailCounter == 2)
    {
        players[curPlayer].money -= 50;
        players[curPlayer].inJailCounter = 0;
        return true;
    }
    else
    {
        players[curPlayer].inJailCounter++;
        return false;
    }
}

void PayRent(int rent)
{

}

void Property(int curPos)
{

}

void Railroad(int numOfRailroadsOwned)
{

}

void Utility(int numOfUtilitiesOwned)
{

}

void IncomeTax()
{

}

void LuxuryTax()
{

}

void CommunityChest()
{

}

void Chance()
{

}

void Go()
{

}

void GoToJail()
{

}
