#include "RNG_Dice.h"
#include <random>
#include <time.h>
#include <iostream>


struct Node
{
    int nr;
    Node *left;
    Node *right;
};

RNG_Dice::RNG_Dice()
{
    root=nullptr;

    srand(time(nullptr));
}

RNG_Dice::~RNG_Dice()
{
    //dtor
}

unsigned short RNG_Dice::roll()
{
    return rand()%6+1;
}
