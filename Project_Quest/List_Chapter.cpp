#include "List_Chapter.h"

#include <iostream>
#include <string>
#include <fstream>
#include "List_Dialog.h"

struct Capitol
{
    List_Dialog D;
    struct Capitol *next;

};

List_Chapter::List_Chapter(player *p)
{
    this->head=nullptr;
    this->tail=nullptr;
    int k;
    k=List_Creation(p);    ///creadre lista cu capitole si returnarea nr. de capitole

    Afisare(k,p);
}

List_Chapter::~List_Chapter()
{
    //dtor
}


int List_Chapter::List_Creation(player *p)
{
    std::string *chapters_file_names[100];
    std::ifstream f("Project_Quest_Story\\Story_Chapters.txt");

    unsigned int k;
    f>>k;

    for(unsigned int i=0;i<k;i++)
    {
        chapters_file_names[i]=new std::string;
        f>>*chapters_file_names[i];

    }

    for(unsigned int i=0;i<k;i++)
    {
        List_Dialog *PH;
        PH=new List_Dialog(*chapters_file_names[i],p);
        Chapter_Adding(PH);
    }

    return k;
}


void List_Chapter::Chapter_Adding(List_Dialog *ND)
{
    struct Capitol *temp=new struct Capitol;

    temp->D=*ND;

    temp->next=nullptr;

    if(this->head==nullptr)
    {
        this->head=temp;
        this->tail=temp;
    }
    else
    {
        this->tail->next=temp;
        this->tail=temp;
    }

}

void List_Chapter::Afisare(int k,player *p)
{
    struct Capitol *tHead;
    tHead=this->head;

    for(int i=0;i<k;i++)
    {
        tHead->D.Afisare(p);
        if(tHead->next!=nullptr)
            tHead=tHead->next;
        else
            break;
    }
}
