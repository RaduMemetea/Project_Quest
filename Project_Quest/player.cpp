#include "player.h"
#include <iostream>
#include <string>
#include <bits/stdc++.h>

void Sentence(std::string &b);

player::player()
{
    this->HP=100;
    this->HP_A=100;
    this->Money=0;
    this->Weapon_DMG=10;
    this->Armor=15;
    preluare_nou();

}

player::~player()
{
    //dtor
}

void player::preluare_nou()
{
    std::string name;
    char gender;
    int age;

        std::cout<<"Name: ";std::getline(std::cin,name);
        Sentence(name);
        this->Name=name;

        do{
        std::cout<<"Gender[M/F]: ";std::cin>>gender;
        if(gender>='a'&&gender<='z')
            gender=gender-'a'+'A';
        }while(!(gender=='M'||gender=='F'));          ///asigura intrarea corecta a datelor
        this->Gender=gender;

        do{
        std::cout<<"Age: ";std::cin>>age;
        }while(age<0);     ///asigura intrarea corecta a datelor (Bug: citirea de cifre seteaza valoarea 0)
        this->Age=age;
        system("cls");
}

void player::afis()
{
    std::cout         <<this->Name
                <<'\n'<<this->HP
                <<'\n'<<this->Gender
                <<'\n'<<this->Age
                <<'\n'<<this->Money
                <<'\n'<<this->Weapon_DMG
                <<'\n'<<this->Armor;
}

void Sentence(std::string &b)       /// ( aNDrei gabRi8eL )-->( Andrei Gabri8el)
{
    b[0]=std::toupper(b[0]);

    for(unsigned int i=1; i <= b.size(); i++)
        {
            if(b[i-1]==' ')
                b[i]=std::toupper(b[i]);
                else
                    b[i]=std::tolower(b[i]);

        }
}

