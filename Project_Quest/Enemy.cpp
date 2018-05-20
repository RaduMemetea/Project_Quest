#include "Enemy.h"
#include <fstream>
#include <random>
#include <time.h>
#include <string>
#include <iostream>

Enemy::Enemy()
{
    std::string name[]{"Troll", "Goblin", "Slime", "Ooze", "Orc", "Wolf", "Vampire", "Rat", "Dragon", "Dwarf", "Lizard", "Skeleton", "Witch", "Bear", "Crow"};
    int n=sizeof(name)/sizeof(name[0]);

    srand(time(nullptr));
    this->E_Name=name[rand()%n];

    this->EHP=100;
    this->Armor=5+rand()%21;    ///armura intre 6-25
    this->Weapon_DMG_Min=2+rand()%4;
    this->Weapon_DMG_Max=10+rand()%6;   ///dmg intre 2-5 si 10-15
}

Enemy::~Enemy()
{
    //dtor

}

std::string Enemy::r_Name()
{
    return this->E_Name;
}

int Enemy::r_HP()
{
    return this->EHP;
}
short Enemy::r_Wmin()
{
    return this->Weapon_DMG_Min;
}
short Enemy::r_WMax()
{
    return this->Weapon_DMG_Max;
}
short Enemy::r_Armor()
{
    return this->Armor;
}
void Enemy::Heal(int p)
{
    this->EHP+=p;
}
void Enemy::Damage(int d)
{
    this->EHP-=d;
}
