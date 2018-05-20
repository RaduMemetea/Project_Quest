#ifndef LIST_CHAPTER_H
#define LIST_CHAPTER_H

#include <string>

#include "player.h"

class List_Dialog;

class List_Chapter
{
    public:
        List_Chapter(player *p);
        virtual ~List_Chapter();
    protected:

    private:
        struct Capitol *head,*tail;

        int List_Creation(player *p);
        void Chapter_Adding(List_Dialog ND);
        void Afisare(int k,player *p);


};

#endif // LIST_CHAPTER_H
