#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Enemy;

class player
{
    public:
        player();
        virtual ~player();

        void afis();
        void preluare_nou();
        void point_to_HP();/// transforma punctele de viata(HP_P) intr-o viata plina(HP_B)

        friend bool Fight(player );
        friend DAMAGE(player &,Enemy &,bool );///decide cat dmg da player(0)/enemy(1)
        friend int HEAL(player &p,Enemy &e,bool a);///decide cat heal primeste player(0)/enemy(1)
    friend bool test(player p);


    protected:

    private:
        std::string Name;
        int HP_B;
        int HP_P;
        int Money;
        short Weapon_DMG_Min;
        short Weapon_DMG_Max;
        short Armor;



};

#endif // PLAYER_H
