#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Enemy;

class player
{
    public:
        player();
        virtual ~player();

        int r_HP_B();   ///returneaza HP_B
        int r_HP_P();   ///returneaza HP_P
        std::string r_Name();   ///returneaza Numele
        int r_Money();   ///returneaza Money
        short r_Wmin();   ///returneaza Weapon_DMG_Min
        short r_WMax();   ///returneaza Weapon_DMG_Max
        short r_Armor();   ///returneaza Armor

        void Heal(int p);   /// Adauga 'p' la HP_B
        void Damage(int d); /// Scade 'd' din HP_B
        void point_to_HP(); /// transforma punctele de viata(HP_P) intr-o viata plina(HP_B)
        void Set_Money(int g);  /// Adauga 'g' la Money
        void Set_W_DMG(int Min, int Max);   /// Adauga 'Min' Weapon_DMG_Min la si 'Max' la Weapon_DMG_Max

    protected:
        void set_Name();

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
