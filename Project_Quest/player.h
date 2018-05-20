#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Enemy;

class player
{
    public:
        player();
        virtual ~player();

        int r_HP_B();
        int r_HP_P();
        std::string r_Name();
        int r_Money();
        short r_Wmin();
        short r_WMax();
        short r_Armor();

        void Heal(int p);
        void Damage(int d);
        void point_to_HP();/// transforma punctele de viata(HP_P) intr-o viata plina(HP_B)
        void Set_Money(int g);
        void Set_W_DMG(int Min, int Max);

    protected:
        void set_Nume();

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
