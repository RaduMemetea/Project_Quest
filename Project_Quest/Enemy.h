#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class player;

class Enemy
{
    public:
        Enemy();
        virtual ~Enemy();

        std::string r_Name();
        int r_HP();
        short r_Wmin();
        short r_WMax();
        short r_Armor();
        void Heal(int p);
        void Damage(int d);

    protected:

    private:

        std::string E_Name;
        int EHP;
        int Weapon_DMG_Min;
        int Weapon_DMG_Max;
        int Armor;

};

#endif // ENEMY_H
