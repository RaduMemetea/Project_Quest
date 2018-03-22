#include <iostream>
#include <string>
#include <bits/stdc++.h>


#include "player.h"
#include "Story_Node.h"
#include "Enemy.h"


using namespace std;

int main()
{
    system("color A");
    Enemy b;



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

