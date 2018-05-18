#include "List_Chapter.h"
#include <iostream>
#include <string>
#include <fstream>

#include "List_Dialog.h"

using std::string;

typedef unsigned int uint;

struct Capitol
{
    List_Dialog D;
    struct Capitol *next;

};

List_Chapter::List_Chapter()
{
    this->head=nullptr;
    this->tail=nullptr;
    List_Creation();

    std::cout<<this->head->D.afisare_id();

}

List_Chapter::~List_Chapter()
{
    //dtor
}

void List_Chapter::Chapter_Adding(List_Dialog ND)
{
    struct Capitol *temp=new struct Capitol;

    temp->D=ND;

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

void List_Chapter::List_Creation()
{
    string *chapters_file_names[100];
    std::ifstream f("Project_Quest_Story\\Story_Chapters.txt");
    unsigned int k;
    f>>k;

    for(uint i=0;i<k;i++)
    {
        chapters_file_names[i]=new string;
        f>>*chapters_file_names[i];

    }

    for(uint i=0;i<k;i++)
    {
        List_Dialog *PH;
        PH=new List_Dialog(*chapters_file_names[i]);
        Chapter_Adding(*PH);
    }
}



