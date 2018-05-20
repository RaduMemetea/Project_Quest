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
    set_Nume();

}

player::~player()
{
    //dtor
}

void player::set_Nume()
{
    std::string name;
    std::cout<<"Name: ";
    std::getline(std::cin,name);
    this->Name=name;
    system("cls");
}

void player::point_to_HP()
{
    this->HP_P-=1;
    this->HP_B=100;
}

std::string player::r_Name()
{
    return this->Name;
}

int player::r_HP_B()
{
    return this->HP_B;
}
int player::r_HP_P()
{
    return this->HP_P;
}
int player::r_Money()
{
    return this->Money;
}
short player::r_Wmin()
{
    return this->Weapon_DMG_Min;
}
short player::r_WMax()
{
    return this->Weapon_DMG_Max;
}
short player::r_Armor()
{
    return this->Armor;
}

void player::Heal(int p)
{
    if(this->HP_B+p <=100)
        this->HP_B+=p;
        else
            this->HP_B=100;
}
void player::Damage(int d)
{
    if(this->HP_B-d>=0)
        this->HP_B-=d;
        else
            this->HP_B=0;
}
void player::Set_Money(int g)
{
    if(this->Money+=g >=0)
        this->Money+=g;
    else
    {
        std::cout<<"\nNot Enough Money!\n";
    }
}
void player::Set_W_DMG(int Min, int Max)
{
    if(this->Weapon_DMG_Max+Max >= this->Weapon_DMG_Min)
        this->Weapon_DMG_Max+=Max;

    if(this->Weapon_DMG_Min+Min >= 0 && this->Weapon_DMG_Min+Min <=this->Weapon_DMG_Max)
        this->Weapon_DMG_Min+=Min;
}

