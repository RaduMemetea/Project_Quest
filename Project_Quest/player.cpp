#include "player.h"
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <random>
#include <time.h>

player::player()
{
    srand(time(NULL));

    this->HP_P=4;
    this->HP_B=100;
    this->Money=0;
    this->Weapon_DMG_Min=3+rand()%5;
    this->Weapon_DMG_Max=10+rand()%8;
    this->Armor=10;
    preluare_nou();

}

player::~player()
{
    //dtor
}

void player::preluare_nou()
{
    std::string name;
    std::cout<<"Name: ";
//    std::getline(std::cin,name);
    this->Name=name;
    system("cls");
}

void player::point_to_HP()
{
    this->HP_P-=1;
    this->HP_B=100;
}
