#ifndef LIST_CHAPTER_H
#define LIST_CHAPTER_H

#include <string>

class List_Dialog;

class List_Chapter
{
    public:
        List_Chapter();
        virtual ~List_Chapter();
    protected:

    private:
        struct Capitol *head,*tail;

        void List_Creation();
        void Chapter_Adding(List_Dialog ND);


};

#endif // LIST_CHAPTER_H
