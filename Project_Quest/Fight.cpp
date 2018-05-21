#include "Fight.h"

#include <iostream>
#include <string>


Fight::Fight(player *pp)
{
    this->p=pp;
}

void Fight::Dead_End()
{
    std::cout<<"\nEnd Of You're Jurney!";
    exit(1);
}

int Fight::DAMAGE(player &p,Enemy &e,bool a) ///decide cat dmg da player(0)/enemy(1)
{

    if(a)///enemy
    {
        int x=rand()%(e.r_WMax()-e.r_Wmin()+1)+e.r_Wmin();
        int xr=x-p.r_Armor()*x/100;
        return xr;

    }
    else///player
    {
        int x=rand()%(p.r_WMax()-p.r_Wmin()+1)+p.r_Wmin();
        int xr=x-e.r_Armor()*x/100;
        return xr;
    }
}

int Fight::HEAL(player &p,Enemy &e,bool a)///decide cat heal primeste player(0)/enemy(1)
{
    if(!a)///player
    {
        int r=e.r_WMax()/2+rand()%((e.r_WMax()+3)/2);
        return r;
    }
    else///enemy
    {
        int r=p.r_WMax()/2+rand()%((p.r_WMax()+1)/2);
        return r;
    }
}


bool Fight::Start()
{
    player &p=*this->p;
    Enemy e;
    if(p.r_HP_B()<=50)
    {
        std::cout<<"You Have "<<p.r_HP_B()<<" Health \nWanna spend 3 Gold to heal? [Y/N]";
        std::string c;
        std::cin>>c;
        if(HIGH(c) == "Y")
        {
            if(p.r_Money()-3>=0)
                {
                    p.Set_Money(-3);
                    p.Heal(100);
                }
            else
            {
                std::cout<<"Not Enough Money!\n";
            }

        }
    }
    std::cout<<p.r_Name()<<"'s Hp: "<<p.r_HP_B()<<" "<<e.r_Name()<<" Hp: "<<e.r_HP();

    while(p.r_HP_B()>0 && e.r_HP()>0)
    {
        std::string choice;

            std::cout<<"\nAttack(A)/Heal(H): ";std::cin>>choice;

            system("cls");

        if(HIGH(choice) =="A")
        {
            int d=0;
            d=DAMAGE(p,e,0);
            std::cout<<p.r_Name()<<" dealt "<<d<<" damage to "<<e.r_Name()<<'\n';
            e.Damage(d);
        }

        if(HIGH(choice) =="H")
        {
            if(p.r_HP_B()<100)
                {
                    int r;
                    r=HEAL(p,e,0);
                    if(p.r_HP_B()+r<=100)
                        {
                            std::cout<<p.r_Name()<<" recovered "<<r<<" HP points\n";
                            p.Heal(r);
                        }
                        else
                        if(p.r_HP_B()+r>100)
                            {
                                std::cout<<p.r_Name()<<" recovered "<<100-p.r_HP_B()<<" HP points\n";
                                p.Heal(100-p.r_HP_B());
                            }
                }
        }

        if(e.r_HP()>0)
        {
            int ec=((rand()+rand()-rand())*rand())%2;

            if(ec==1 && e.r_HP()==100)
                ec=0;

            if(ec)/// 1 heal
            {
                int r=HEAL(p,e,1);
                if(e.r_HP()+r<=100)
               {
                    std::cout<<e.r_Name()<<" recovered "<<r<<" HP points\n";
                    e.Heal(r);
               }
               else
                if(e.r_HP()+r>100)
               {
                    std::cout<<e.r_Name()<<" recovered "<<100-e.r_HP()<<" HP points\n";
                    e.Heal(100-e.r_HP());
               }

            }
            else/// 0 attack
            {
                int de=0;
                de=DAMAGE(p,e,1);
                std::cout<<e.r_Name()<<" dealt "<<de<<" damage to "<<p.r_Name()<<"\n";
                p.Damage(de);


            }
        }
                std::cout<<"\n"<<p.r_Name()<<"'s Hp: "<<p.r_HP_B()<<" "<<e.r_Name()<<" Hp: "<<e.r_HP();


    }

    if(p.r_HP_B()<=0)
    {
        if(p.r_HP_P()>0)
        {
            p.point_to_HP();
            std::cout<<"\nYou lost 1 life, you have "<<p.r_HP_P()<<" left\n";
            return 0;
        }
        else
        {
            Dead_End();
        }
    }
    else
        if(e.r_HP()<=0)
        {
            std::cout<<"\nYou Won against the "<<e.r_Name()<<'\n';
        }
    return 1;
}

std::string Fight::HIGH(std::string b)
{
    b[0]=std::toupper(b[0]);
    return b;
}

