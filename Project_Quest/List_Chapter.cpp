#include "List_Chapter.h"
#include <iostream>
#include <string>
using std::string;

struct Dialog
{
    struct Dialog *prev;
    unsigned int ID_Nod, ID_NextA, ID_NextB, ID_NextC;
    string Voce;
    string Text;
    struct Dialog *next_A,*next_B,*next_C;
};

struct Capitol
{
    struct Dialog L;
    struct Capitol *next;
};

List_Chapter::List_Chapter()
{
    head=nullptr;
    tail=nullptr;
}

List_Chapter::~List_Chapter()
{
    //dtor
}

void List_Chapter::Chapter_Adding(struct Dialog NL)
{
    struct Capitol *tmp=new struct Capitol;
    tmp->L=NL;
    tmp->next=nullptr;
    if(this->head==nullptr)
    {
        head=tmp;
        tail=tmp;
        tmp=nullptr;
    }
    else
    {
        tail->next=tmp;
        tail=tmp;
    }

}

