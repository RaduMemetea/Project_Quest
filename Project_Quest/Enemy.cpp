#include "Enemy.h"
#include <fstream>
#include <random>
#include <time.h>
#include <string>
#include <iostream>

std::ifstream en("Enemy_Names.txt");

Enemy::Enemy()
{
    unsigned int n;
    std::string name;
    en>>n;
    srand(time(NULL));
    for(unsigned int i=1;i<=rand()%n+1;i++)
        std::getline(en,name);
    this->E_Name=name;

    this->EHP=100;
    this->Armor=5+rand()%21;    ///armura intre 6-25
    this->Weapon_DMG_Min=2+rand()%4;
    this->Weapon_DMG_Max=10+rand()%6;   ///dmg intre 2-5 si 10-15
}

Enemy::~Enemy()
{
    //dtor

}
