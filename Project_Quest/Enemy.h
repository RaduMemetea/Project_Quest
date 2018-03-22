#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy
{
    public:
        Enemy();
        virtual ~Enemy();

    protected:
        std::string E_Name;
        int HP;
        int Armor;
        int Weapon_DMG_Min;
        int Weapon_DMG_Max;
    private:

};

#endif // ENEMY_H
