#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class player
{
    public:
        player();
        virtual ~player();

        void afis();
        void preluare_nou();

    protected:

    private:
        std::string Name;
        int HP_P;
        int HP_B;
        int Money;
        short Weapon_DMG_Min;
        short Weapon_DMG_Max;
        short Armor;

};

#endif // PLAYER_H
