#ifndef FIGHT_H
#define FIGHT_H

#include "player.h"
#include "Enemy.h"

class Fight
{
    public:
        Fight(player *pp);
        bool Start();

    protected:

    private:
        player *p;

        int DAMAGE(player &p,Enemy &e,bool a);
        int HEAL(player &p,Enemy &e,bool a);
        void Dead_End();
        std::string HIGH(std::string a);
};

#endif // FIGHT_H
