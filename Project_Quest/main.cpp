#include <iostream>
#include <string>
#include <bits/stdc++.h>


#include "player.h"
#include "Enemy.h"
#include "List_Chapter.h"
#include "List_Dialog.h"

using std::cout;
using std::cin;
using std::string;

void Sentence(std::string &b);       /// ( aNDrei gabRi8eL )-->( Andrei Gabri8el)
bool Fight(player p);

void Dead_End()
{
    std::cout<<"\nEnd Of You're Lifes";
    exit(1);
}

/**
struct Dialog
{
    struct Dialog *prev;
    unsigned int ID_Nod, ID_NextA, ID_NextB, ID_NextC;
    string Voce;
    string Text;
    struct Dialog *next_A,*next_B,*next_C;
};

struct Capitol
{
    struct Dialog L;
    struct Capitol *next;
};
*/




int DAMAGE(player &p,Enemy &e,bool a) ///decide cat dmg da player(0)/enemy(1)
{

    if(a)///enemy
    {
        int x=rand()%(e.Weapon_DMG_Max-e.Weapon_DMG_Min+1)+e.Weapon_DMG_Min;
        int xr=x-p.Armor*x/100;
        return xr;

    }
    else///player
    {
        int x=rand()%(p.Weapon_DMG_Max-p.Weapon_DMG_Min+1)+p.Weapon_DMG_Min;
        int xr=x-e.Armor*x/100;
        return xr;
    }
}

int HEAL(player &p,Enemy &e,bool a)///decide cat heal primeste player(0)/enemy(1)
{
    if(!a)///player
    {
        int r=e.Weapon_DMG_Max/2+rand()%((e.Weapon_DMG_Max+3)/2);
        return r;
    }
    else///enemy
    {
        int r=p.Weapon_DMG_Max/2+rand()%((p.Weapon_DMG_Max+1)/2);
        return r;
    }
}

bool Battle_Stage(player &p,int n=0,int w=0)/// n=nr de lupte, w=nr de winuri  (best of 3)
{
    while(1)
    {
        if(n>3)
            return 0;
        if(w==2)
            return 1;
        bool r;
        r=Fight(p);
        if(r)
        {
            n++;
            w++;
        }
        else
            n++;

    }
}

bool Fight(player p)
{

    Enemy e;

    while(p.HP_B>0 && e.EHP>0)
    {
        std::string choice;

            cout<<"Attack(A)/Heal(H):";cin>>choice;
            Sentence(choice);

        if(choice=="A")
        {
            int d=0;
            d=DAMAGE(p,e,0);
            std::cout<<'\n'<<p.Name<<" dealt "<<d<<" damage to "<<e.E_Name;
            e.EHP-=d;
        }

        if(choice=="H")
        {
            if(p.HP_B<100)
                {
                    int r;
                    r=HEAL(p,e,0);
                    if(p.HP_B+r<=100)
                        {
                            cout<<'\n'<<p.Name<<" recovered "<<r<<" HP points";
                            p.HP_B+=r;
                        }
                        else
                        if(p.HP_B+r>100)
                            {
                                cout<<'\n'<<p.Name<<" recovered "<<100-p.HP_B<<" HP points";
                                p.HP_B=100;
                            }
                }
        }
        if(e.EHP>0)
        {
            int ec=((rand()+rand()-rand())*rand())%2;

            if(ec==1 && e.EHP==100)
                ec=0;

            if(ec)/// 1 heal
            {
                int r=HEAL(p,e,1);
                if(e.EHP+r<=100)
               {
                    cout<<'\n'<<e.E_Name<<" recovered "<<r<<" HP points";
                    e.EHP+=r;
               }
               else
                if(e.EHP+r>100)
               {
                    cout<<'\n'<<e.E_Name<<" recovered "<<100-e.EHP<<" HP points";
                    e.EHP=100;
               }

            }
            else/// 0 attack
            {
                int de=0;
                de=DAMAGE(p,e,1);
                std::cout<<'\n'<<e.E_Name<<" dealt "<<de<<" damage to "<<p.Name;
                p.HP_B-=de;


            }
        }

    cout<<'\n'<<p.HP_B<<" "<<e.EHP<<'\n';

    }

    if(p.HP_B<=0)
    {
        if(p.HP_P>0)
        {
            p.point_to_HP();
            std::cout<<"\nYou lost 1 life, you have "<<p.HP_P<<" left";
            return 0;
        }
        else
        {
            Dead_End();
        }
    }
    else
        if(e.EHP<=0)
        {
            std::cout<<"\nYou Won against "<<e.E_Name;
        }
            return 1;

}


bool test(player p)
{
    Enemy e;
    std::cout<<e.E_Name;

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




int main()
{
    system("color A");

    List_Chapter C1;

}

