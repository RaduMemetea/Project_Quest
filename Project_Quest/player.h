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
        int HP;
        int HP_A;
        char Gender;
        int Age;
        int Money;
        short Weapon_DMG;
        short Armor;

};

#endif // PLAYER_H
