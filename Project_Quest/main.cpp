#include <iostream>
#include <string>
#include <bits/stdc++.h>

#include "player.h"
#include "List_Chapter.h"

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


int main()
{
    system("color A");
    player p;
    List_Chapter c1(&p);
}

