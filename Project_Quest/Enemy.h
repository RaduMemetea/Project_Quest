#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class player;

class Enemy
{
    public:
        Enemy();
        virtual ~Enemy();

        friend bool Fight(player );
        friend DAMAGE(player &,Enemy &,bool );///decide cat dmg da player(0)/enemy(1)
        friend int HEAL(player &p,Enemy &e,bool a);///decide cat heal primeste player(0)/enemy(1)

            friend bool test();

    protected:

    private:

        std::string E_Name;
        int EHP;
        int Armor;
        int Weapon_DMG_Min;
        int Weapon_DMG_Max;

};

#endif // ENEMY_H
