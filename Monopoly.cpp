#include "Monopoly.h"
#include "stdlib.h"

void initGame(int numPlayers)
{
  srand( time(NULL));
    numOfPlayers = numPlayers;

    gameEnd = false;

    for (int i = 0; i < numOfPlayers; i++)
    {
        players[i].curPos = 0;
        players[i].inJail = false;
        players[i].inJailCounter = 0;
        players[i].money = 1500;
        players[i].numOfRailroads = 0;
        players[i].numOfUtilities = 0;
	players[i].inGame = true;
    }

    curPlayer = 0;

    board[0].name = "GO";
    board[0].spaceType = _Go;
    board[0].xCoord = 560;
    board[0].yCoord = 560;
    board[0].cost = 0;
    board[0].costPerHouse = 0;
    board[0].groupedWith1 = -1;
    board[0].groupedWith2 = -1;
    board[0].numOfHouses = 0;
    board[0].owner = -1;
    for (int i = 0; i < 6; i++)
    {
        board[0].rent[i] = 0;
    }

    board[1].name = "Bombette";
    board[1].spaceType = _Property;
    board[1].xCoord = 490;
    board[1].yCoord = 560;
    board[1].cost = 60;
    board[1].costPerHouse = 50;
    board[1].groupedWith1 = 3;
    board[1].groupedWith2 = -1;
    board[1].numOfHouses = 0;
    board[1].owner = -1;
    board[1].rent[0] = 2;
    board[1].rent[1] = 10;
    board[1].rent[2] = 30;
    board[1].rent[3] = 90;
    board[1].rent[4] = 160;
    board[1].rent[5] = 250;

    board[2].name = "Star Spirits";
    board[2].spaceType = _CommunityChest;
    board[2].xCoord = 445;
    board[2].yCoord = 560;
    board[2].cost = 0;
    board[2].costPerHouse = 0;
    board[2].groupedWith1 = -1;
    board[2].groupedWith2 = -1;
    board[2].numOfHouses = 0;
    board[2].owner = -1;
    for (int i = 0; i < 6; i++)
    {
        board[2].rent[i] = 0;
    }

    board[3].name = "Koopa Bros";
    board[3].spaceType = _Property;
    board[3].xCoord = 395;
    board[3].yCoord = 560;
    board[3].cost = 60;
    board[3].costPerHouse = 50;
    board[3].groupedWith1 = 1;
    board[3].groupedWith2 = -1;
    board[3].numOfHouses = 0;
    board[3].owner = -1;
    board[3].rent[0] = 4;
    board[3].rent[1] = 20;
    board[3].rent[2] = 60;
    board[3].rent[3] = 180;
    board[3].rent[4] = 320;
    board[3].rent[5] = 450;

    board[4].name = "Kent C. Koopa";
    board[4].spaceType = _IncomeTax;
    board[4].xCoord = 350;
    board[4].yCoord = 560;
    board[4].cost = 300;
    board[4].costPerHouse = 0;
    board[4].groupedWith1 = -1;
    board[4].groupedWith2 = -1;
    board[4].numOfHouses = 0;
    board[4].owner = -1;
    for (int i = 0; i < 6; i++)
    {
        board[4].rent[i] = 0;
    }

    board[5].name = "All or Nothing Badge";
    board[5].spaceType = _Railroad;
    board[5].xCoord = 300;
    board[5].yCoord = 560;
    board[5].cost = 200;
    board[5].costPerHouse = 0;
    board[5].groupedWith1 = -1;
    board[5].groupedWith2 = -1;
    board[5].numOfHouses = 0;
    board[5].owner = -1;
    board[5].rent[0] = 25;
    board[5].rent[1] = 50;
    board[5].rent[2] = 100;
    board[5].rent[3] = 200;
    board[5].rent[4] = 0;
    board[5].rent[5] = 0;

    board[6].name = "Parakapry";
    board[6].spaceType = _Property;
    board[6].xCoord = 255;
    board[6].yCoord = 560;
    board[6].cost = 100;
    board[6].costPerHouse = 50;
    board[6].groupedWith1 = 8;
    board[6].groupedWith2 = 9;
    board[6].numOfHouses = 0;
    board[6].owner = -1;
    board[6].rent[0] = 6;
    board[6].rent[1] = 30;
    board[6].rent[2] = 90;
    board[6].rent[3] = 270;
    board[6].rent[4] = 400;
    board[6].rent[5] = 550;

    board[7].name = "?Block";
    board[7].spaceType = _Chance;
    board[7].xCoord = 205;
    board[7].yCoord = 560;
    board[7].cost = 0;
    board[7].costPerHouse = 0;
    board[7].groupedWith1 = -1;
    board[7].groupedWith2 = -1;
    board[7].numOfHouses = 0;
    board[7].owner = -1;
    for (int i = 0; i < 6; i++)
    {
        board[7].rent[i] = 0;
    }

    board[8].name = "Stone Chomp";
    board[8].spaceType = _Property;
    board[8].xCoord = 160;
    board[8].yCoord = 560;
    board[8].cost = 100;
    board[8].costPerHouse = 50;
    board[8].groupedWith1 = 6;
    board[8].groupedWith2 = 9;
    board[8].numOfHouses = 0;
    board[8].owner = -1;
    board[8].rent[0] = 6;
    board[8].rent[1] = 30;
    board[8].rent[2] = 90;
    board[8].rent[3] = 270;
    board[8].rent[4] = 400;
    board[8].rent[5] = 550;

    board[9].name = "Tutanedopa";
    board[9].spaceType = _Property;
    board[9].xCoord = 110;
    board[9].yCoord = 560;
    board[9].cost = 120;
    board[9].costPerHouse = 50;
    board[9].groupedWith1 = 6;
    board[9].groupedWith2 = 8;
    board[9].numOfHouses = 0;
    board[9].owner = -1;
    board[9].rent[0] = 8;
    board[9].rent[1] = 40;
    board[9].rent[2] = 100;
    board[9].rent[3] = 300;
    board[9].rent[4] = 450;
    board[9].rent[5] = 600;

    board[10].name = "In Jail/Just Visiting";
    board[10].spaceType = _Jail;
    board[10].xCoord = 40;
    board[10].yCoord = 560;
    board[10].cost = 0;
    board[10].costPerHouse = 0;
    board[10].groupedWith1 = -1;
    board[10].groupedWith2 = -1;
    board[10].numOfHouses = 0;
    board[10].owner = -1;
    for (int i = 0; i < 6; i++)
    {
        board[10].rent[i] = 0;
    }

    board[11].name = "Lady Bow";
    board[11].spaceType = _Property;
    board[11].xCoord = 40;
    board[11].yCoord = 490;
    board[11].cost = 140;
    board[11].costPerHouse = 100;
    board[11].groupedWith1 = 13;
    board[11].groupedWith2 = 14;
    board[11].numOfHouses = 0;
    board[11].owner = -1;
    board[11].rent[0] = 10;
    board[11].rent[1] = 50;
    board[11].rent[2] = 150;
    board[11].rent[3] = 450;
    board[11].rent[4] = 625;
    board[11].rent[5] = 750;

    board[12].name = "Mushroom";
    board[12].spaceType = _Utility;
    board[12].xCoord = 40;
    board[12].yCoord = 440;
    board[12].cost = 150;
    board[12].costPerHouse = 0;
    board[12].groupedWith1 = -1;
    board[12].groupedWith2 = -1;
    board[12].numOfHouses = 0;
    board[12].owner = -1;
    for (int i = 0; i < 6; i++)
    {
        board[12].rent[i] = 0;
    }

    board[13].name = "Tubba Blubba's Heart";
    board[13].spaceType = _Property;
    board[13].xCoord = 40;
    board[13].yCoord = 395;
    board[13].cost = 140;
    board[13].costPerHouse = 100;
    board[13].groupedWith1 = 11;
    board[13].groupedWith2 = 14;
    board[13].numOfHouses = 0;
    board[13].owner = -1;
    board[13].rent[0] = 10;
    board[13].rent[1] = 50;
    board[13].rent[2] = 150;
    board[13].rent[3] = 450;
    board[13].rent[4] = 625;
    board[13].rent[5] = 750;

    board[14].name = "Tubba Blubba";
    board[14].spaceType = _Property;
    board[14].xCoord = 40;
    board[14].yCoord = 345;
    board[14].cost = 160;
    board[14].costPerHouse = 100;
    board[14].groupedWith1 = 11;
    board[14].groupedWith2 = 13;
    board[14].numOfHouses = 0;
    board[14].owner = -1;
    board[14].rent[0] = 12;
    board[14].rent[1] = 60;
    board[14].rent[2] = 180;
    board[14].rent[3] = 500;
    board[14].rent[4] = 700;
    board[14].rent[5] = 900;

    board[15].name = "Feeling Fine Badge";
    board[15].spaceType = _Railroad;
    board[15].xCoord = 40;
    board[15].yCoord = 300;
    board[15].cost = 200;
    board[15].costPerHouse = 0;
    board[15].groupedWith1 = -1;
    board[15].groupedWith2 = -1;
    board[15].numOfHouses = 0;
    board[15].owner = -1;
    board[15].rent[0] = 25;
    board[15].rent[1] = 50;
    board[15].rent[2] = 100;
    board[15].rent[3] = 200;
    board[15].rent[4] = 0;
    board[15].rent[5] = 0;

    board[16].name = "Watt";
    board[16].spaceType = _Property;
    board[16].xCoord = 40;
    board[16].yCoord = 250;
    board[16].cost = 180;
    board[16].costPerHouse = 100;
    board[16].groupedWith1 = 18;
    board[16].groupedWith2 = 19;
    board[16].numOfHouses = 0;
    board[16].owner = -1;
    board[16].rent[0] = 14;
    board[16].rent[1] = 70;
    board[16].rent[2] = 200;
    board[16].rent[3] = 550;
    board[16].rent[4] = 750;
    board[16].rent[5] = 950;

    board[17].name = "Star Spirits";
    board[17].spaceType = _CommunityChest;
    board[17].xCoord = 40;
    board[17].yCoord = 205;
    board[17].cost = 0;
    board[17].costPerHouse = 0;
    board[17].groupedWith1 = -1;
    board[17].groupedWith2 = -1;
    board[17].numOfHouses = 0;
    board[17].owner = -1;
    for (int i = 0; i < 6; i++)
    {
        board[17].rent[i] = 0;
    }

    board[18].name = "Big Lantern Ghost";
    board[18].spaceType = _Property;
    board[18].xCoord = 40;
    board[18].yCoord = 155;
    board[18].cost = 180;
    board[18].costPerHouse = 100;
    board[18].groupedWith1 = 16;
    board[18].groupedWith2 = 19;
    board[18].numOfHouses = 0;
    board[18].owner = -1;
    board[18].rent[0] = 14;
    board[18].rent[1] = 70;
    board[18].rent[2] = 200;
    board[18].rent[3] = 550;
    board[18].rent[4] = 750;
    board[18].rent[5] = 950;

    board[19].name = "General Guy";
    board[19].spaceType = _Property;
    board[19].xCoord = 40;
    board[19].yCoord = 110;
    board[19].cost = 200;
    board[19].costPerHouse = 100;
    board[19].groupedWith1 = 16;
    board[19].groupedWith2 = 18;
    board[19].numOfHouses = 0;
    board[19].owner = -1;
    board[19].rent[0] = 16;
    board[19].rent[1] = 80;
    board[19].rent[2] = 220;
    board[19].rent[3] = 600;
    board[19].rent[4] = 800;
    board[19].rent[5] = 1000;

    board[20].name = "Free Parking";
    board[20].spaceType = _FreeParking;
    board[20].xCoord = 40;
    board[20].yCoord = 40;
    board[20].cost = 0;
    board[20].costPerHouse = 0;
    board[20].groupedWith1 = -1;
    board[20].groupedWith2 = -1;
    board[20].numOfHouses = 0;
    board[20].owner = -1;
    for (int i = 0; i < 6; i++)
    {
        board[20].rent[i] = 0;
    }

    board[21].name = "Sushie";
    board[21].spaceType = _Property;
    board[21].xCoord = 110;
    board[21].yCoord = 40;
    board[21].cost = 220;
    board[21].costPerHouse = 150;
    board[21].groupedWith1 = 23;
    board[21].groupedWith2 = 24;
    board[21].numOfHouses = 0;
    board[21].owner = -1;
    board[21].rent[0] = 18;
    board[21].rent[1] = 90;
    board[21].rent[2] = 250;
    board[21].rent[3] = 700;
    board[21].rent[4] = 875;
    board[21].rent[5] = 1050;

    board[22].name = "?Block";
    board[22].spaceType = _Chance;
    board[22].xCoord = 155;
    board[22].yCoord = 40;
    board[22].cost = 0;
    board[22].costPerHouse = 0;
    board[22].groupedWith1 = -1;
    board[22].groupedWith2 = -1;
    board[22].numOfHouses = 0;
    board[22].owner = -1;
    for (int i = 0; i < 6; i++)
    {
        board[22].rent[i] = 0;
    }

    board[23].name = "Putrid Piranha";
    board[23].spaceType = _Property;
    board[23].xCoord = 205;
    board[23].yCoord = 40;
    board[23].cost = 220;
    board[23].costPerHouse = 150;
    board[23].groupedWith1 = 21;
    board[23].groupedWith2 = 24;
    board[23].numOfHouses = 0;
    board[23].owner = -1;
    board[23].rent[0] = 18;
    board[23].rent[1] = 90;
    board[23].rent[2] = 250;
    board[23].rent[3] = 700;
    board[23].rent[4] = 875;
    board[23].rent[5] = 1050;

    board[24].name = "Lava Piranha";
    board[24].spaceType = _Property;
    board[24].xCoord = 250;
    board[24].yCoord = 40;
    board[24].cost = 240;
    board[24].costPerHouse = 150;
    board[24].groupedWith1 = 21;
    board[24].groupedWith2 = 24;
    board[24].numOfHouses = 0;
    board[24].owner = -1;
    board[24].rent[0] = 20;
    board[24].rent[1] = 100;
    board[24].rent[2] = 300;
    board[24].rent[3] = 750;
    board[24].rent[4] = 925;
    board[24].rent[5] = 1100;

    board[25].name = "Power Judge Badge";
    board[25].spaceType = _Railroad;
    board[25].xCoord = 300;
    board[25].yCoord = 40;
    board[25].cost = 200;
    board[25].costPerHouse = 0;
    board[25].groupedWith1 = -1;
    board[25].groupedWith2 = -1;
    board[25].numOfHouses = 0;
    board[25].owner = -1;
    board[25].rent[0] = 25;
    board[25].rent[1] = 50;
    board[25].rent[2] = 100;
    board[25].rent[3] = 200;
    board[25].rent[4] = 0;
    board[25].rent[5] = 0;

    board[26].name = "Lakilester";
    board[26].spaceType = _Property;
    board[26].xCoord = 350;
    board[26].yCoord = 40;
    board[26].cost = 260;
    board[26].costPerHouse = 150;
    board[26].groupedWith1 = 27;
    board[26].groupedWith2 = 29;
    board[26].numOfHouses = 0;
    board[26].owner = -1;
    board[26].rent[0] = 22;
    board[26].rent[1] = 110;
    board[26].rent[2] = 330;
    board[26].rent[3] = 800;
    board[26].rent[4] = 975;
    board[26].rent[5] = 1150;

    board[27].name = "Amazee Dayzee";
    board[27].spaceType = _Property;
    board[27].xCoord = 395;
    board[27].yCoord = 40;
    board[27].cost = 260;
    board[27].costPerHouse = 150;
    board[27].groupedWith1 = 26;
    board[27].groupedWith2 = 29;
    board[27].numOfHouses = 0;
    board[27].owner = -1;
    board[27].rent[0] = 22;
    board[27].rent[1] = 110;
    board[27].rent[2] = 330;
    board[27].rent[3] = 800;
    board[27].rent[4] = 975;
    board[27].rent[5] = 1150;

    board[28].name = "Fire Flower";
    board[28].spaceType = _Utility;
    board[28].xCoord = 440;
    board[28].yCoord = 40;
    board[28].cost = 150;
    board[28].costPerHouse = 0;
    board[28].groupedWith1 = -1;
    board[28].groupedWith2 = -1;
    board[28].numOfHouses = 0;
    board[28].owner = -1;
    for (int i = 0; i < 6; i++)
    {
        board[28].rent[i] = 0;
    }

    board[29].name = "Huff N Puff";
    board[29].spaceType = _Property;
    board[29].xCoord = 490;
    board[29].yCoord = 40;
    board[29].cost = 280;
    board[29].costPerHouse = 150;
    board[29].groupedWith1 = 26;
    board[29].groupedWith2 = 27;
    board[29].numOfHouses = 0;
    board[29].owner = -1;
    board[29].rent[0] = 24;
    board[29].rent[1] = 120;
    board[29].rent[2] = 360;
    board[29].rent[3] = 850;
    board[29].rent[4] = 1025;
    board[29].rent[5] = 1200;

    board[30].name = "Go To Jail";
    board[30].spaceType = _GoToJail;
    board[30].xCoord = 560;
    board[30].yCoord = 40;
    board[30].cost = 0;
    board[30].costPerHouse = 0;
    board[30].groupedWith1 = -1;
    board[30].groupedWith2 = -1;
    board[30].numOfHouses = 0;
    board[30].owner = -1;
    for (int i = 0; i < 6; i++)
    {
        board[30].rent[i] = 0;
    }

    board[31].name = "Mario";
    board[31].spaceType = _Property;
    board[31].xCoord = 560;
    board[31].yCoord = 110;
    board[31].cost = 300;
    board[31].costPerHouse = 200;
    board[31].groupedWith1 = 32;
    board[31].groupedWith2 = 34;
    board[31].numOfHouses = 0;
    board[31].owner = -1;
    board[31].rent[0] = 26;
    board[31].rent[1] = 130;
    board[31].rent[2] = 390;
    board[31].rent[3] = 900;
    board[31].rent[4] = 1100;
    board[31].rent[5] = 1275;

    board[32].name = "Dupughost";
    board[32].spaceType = _Property;
    board[32].xCoord = 560;
    board[32].yCoord = 155;
    board[32].cost = 300;
    board[32].costPerHouse = 200;
    board[32].groupedWith1 = 31;
    board[32].groupedWith2 = 34;
    board[32].numOfHouses = 0;
    board[32].owner = -1;
    board[32].rent[0] = 26;
    board[32].rent[1] = 130;
    board[32].rent[2] = 390;
    board[32].rent[3] = 900;
    board[32].rent[4] = 1100;
    board[32].rent[5] = 1275;

    board[33].name = "Star Spirits";
    board[33].spaceType = _CommunityChest;
    board[33].xCoord = 560;
    board[33].yCoord = 205;
    board[33].cost = 0;
    board[33].costPerHouse = 0;
    board[33].groupedWith1 = -1;
    board[33].groupedWith2 = -1;
    board[33].numOfHouses = 0;
    board[33].owner = -1;
    for (int i = 0; i < 6; i++)
    {
        board[33].rent[i] = 0;
    }

    board[34].name = "Crystal King";
    board[34].spaceType = _Property;
    board[34].xCoord = 560;
    board[34].yCoord = 250;
    board[34].cost = 320;
    board[34].costPerHouse = 200;
    board[34].groupedWith1 = 31;
    board[34].groupedWith2 = 32;
    board[34].numOfHouses = 0;
    board[34].owner = -1;
    board[34].rent[0] = 28;
    board[34].rent[1] = 150;
    board[34].rent[2] = 450;
    board[34].rent[3] = 1000;
    board[34].rent[4] = 1200;
    board[34].rent[5] = 1400;

    board[35].name = "Slow Go Badge";
    board[35].spaceType = _Railroad;
    board[35].xCoord = 560;
    board[35].yCoord = 300;
    board[35].cost = 200;
    board[35].costPerHouse = 0;
    board[35].groupedWith1 = -1;
    board[35].groupedWith2 = -1;
    board[35].numOfHouses = 0;
    board[35].owner = -1;
    board[15].rent[0] = 25;
    board[15].rent[1] = 50;
    board[15].rent[2] = 100;
    board[15].rent[3] = 200;
    board[15].rent[4] = 0;
    board[15].rent[5] = 0;

    board[36].name = "?Block";
    board[36].spaceType = _Chance;
    board[36].xCoord = 560;
    board[36].yCoord = 345;
    board[36].cost = 0;
    board[36].costPerHouse = 0;
    board[36].groupedWith1 = -1;
    board[36].groupedWith2 = -1;
    board[36].numOfHouses = 0;
    board[36].owner = -1;
    for (int i = 0; i < 6; i++)
    {
        board[36].rent[i] = 0;
    }

    board[37].name = "Kammy Koopa";
    board[37].spaceType = _Property;
    board[37].xCoord = 560;
    board[37].yCoord = 395;
    board[37].cost = 360;
    board[37].costPerHouse = 200;
    board[37].groupedWith1 = 39;
    board[37].groupedWith2 = -1;
    board[37].numOfHouses = 0;
    board[37].owner = -1;
    board[37].rent[0] = 35;
    board[37].rent[1] = 175;
    board[37].rent[2] = 500;
    board[37].rent[3] = 1100;
    board[37].rent[4] = 1300;
    board[37].rent[5] = 1500;

    board[38].name = "Masters Lessons";
    board[38].spaceType = _LuxuryTax;
    board[38].xCoord = 560;
    board[38].yCoord = 440;
    board[38].cost = 75;
    board[38].costPerHouse = 0;
    board[38].groupedWith1 = -1;
    board[38].groupedWith2 = -1;
    board[38].numOfHouses = 0;
    board[38].owner = -1;
    for (int i = 0; i < 6; i++)
    {
        board[38].rent[i] = 0;
    }

    board[39].name = "King Bowser";
    board[39].spaceType = _Property;
    board[39].xCoord = 560;
    board[39].yCoord = 490;
    board[39].cost = 400;
    board[39].costPerHouse = 200;
    board[39].groupedWith1 = 37;
    board[39].groupedWith2 = -1;
    board[39].numOfHouses = 0;
    board[39].owner = -1;
    board[39].rent[0] = 50;
    board[39].rent[1] = 200;
    board[39].rent[2] = 600;
    board[39].rent[3] = 1400;
    board[39].rent[4] = 1700;
    board[39].rent[5] = 2000;
}

void Move(int numOfSpaces)
{
    players[curPlayer].curPos += numOfSpaces;

    if (players[curPlayer].curPos >= 40)
    {
        players[curPlayer].curPos -= 40;

        //passed go
        players[curPlayer].money += 200;
    }

    //do board space
    switch (board[players[curPlayer].curPos].spaceType)
    {
        case _Property:
            Property(players[curPlayer].curPos);
            break;
        case _Railroad:
            Railroad();
            break;
        case _Utility:
            Utility(numOfSpaces);
            break;
        case _IncomeTax:
            IncomeTax();
            break;
        case _LuxuryTax:
            LuxuryTax();
            break;
        case _CommunityChest:
            CommunityChest();
            break;
        case _Chance:
            Chance();
            break;
        case _Go:
            break;
        case _Jail:
            break;
        case _FreeParking:
            break;
        case _GoToJail:
            GoToJail();
            break;
    }

    //increase player + evaluate
    int previousPlayer = curPlayer;
    curPlayer = (curPlayer + 1)%numOfPlayers;
    while(!players[curPlayer].inGame)
        curPlayer = (curPlayer + 1)%numOfPlayers;

    if(curPlayer==previousPlayer)
        endGame();
}

void endGame()
{
    gameEnd = true;
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
    int owner = board[players[curPlayer].curPos].owner;
    //Don't want to pay rent if unnessecary...
    if(owner != curPlayer)
    {
        players[owner].money += rent;
        players[curPlayer].money -= rent;
        if(players[curPlayer].money < 0)
        {
            killPlayer(curPlayer);
        }
    }
}

void killPlayer(int playerNum)
{
    players[playerNum].inGame = false;
    for(int i = 0; i < MaxBoardSize; i++)
    {
	if(board[i].owner == playerNum)
	{
	    board[i].numOfHouses = 0;
            board[i].owner = -1;
	}
    }
    players[playerNum].inJail = false;
    players[playerNum].inJailCounter = 0;
}

void buySpace(int player)
{
    int space = players[player].curPos;
    board[space].owner = player;
    players[player].money -= board[space].cost;
}

void Property(int curPos)
{
    if (board[curPos].owner != -1)
    {
        PayRent(board[curPos].rent[board[curPos].numOfHouses]);
    }
}

void Railroad()
{
    if (board[players[curPlayer].curPos].owner != -1)
    {
    	int numOfRailroadsOwned = players[board[players[curPlayer].curPos].owner].numOfRailroads;
        //Railroads rent[0] = 25, [1] = 50, [2] = 100, [3] = 200
        PayRent(board[players[curPlayer].curPos].rent[numOfRailroadsOwned-1]);
        PayRent(board[players[curPlayer].curPos].rent[numOfRailroadsOwned -1]);
    }
}

void Utility(int diceRoll)
{
    if (board[players[curPlayer].curPos].owner != -1)
    {
    	int numOfUtilitiesOwned = players[board[players[curPlayer].curPos].owner].numOfUtilities;
        int rent = 0;
        switch(numOfUtilitiesOwned)
        {
        case 1:
            rent = 4*diceRoll;
            break;
        case 2:
            rent = 10*diceRoll;
            break;
        default:
            break;
        }

        PayRent(rent);
    }
}

void IncomeTax()
{
    players[curPlayer].money -= board[players[curPlayer].curPos].cost;
}

void LuxuryTax()
{
    players[curPlayer].money -= board[players[curPlayer].curPos].cost;
}

void CommunityChest()
{
    int num = (rand() % 5);

    switch (num)
    {
        case 0:
            players[curPlayer].money += 10;
            break;
        case 1:
            players[curPlayer].money += 20;
            break;
        case 2:
            players[curPlayer].money += 30;
            break;
        case 3:
            players[curPlayer].money -= 10;
            break;
        case 4:
            players[curPlayer].money -= 20;
            break;
    }
}

void Chance()
{
    int num = (rand() % 5);

    switch (num)
    {
        case 0:
            players[curPlayer].money -= 35;
            break;
        case 1:
            players[curPlayer].money -= 20;
            break;
        case 2:
            players[curPlayer].money -= 10;
            break;
        case 3:
            players[curPlayer].money += 10;
            break;
        case 4:
            players[curPlayer].money += 20;
            break;
    }
}

void GoToJail()
{
    players[curPlayer].inJail = true;
    players[curPlayer].curPos = 10;
}
