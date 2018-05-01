#include "List_Dialog.h"
#include <string>
#include <fstream>
#include <iostream>

std::ifstream f("Project_Quest_Story.txt");

using std::string;

struct Dialog
{
    struct Dialog *prev;
    unsigned int ID_Nod, ID_NextA, ID_NextB, ID_NextC;
    string Voce;
    string Text;
    struct Dialog *next_A,*next_B,*next_C;
};

List_Dialog::List_Dialog()
{
    head=nullptr;
    Lista_initiala();
}

List_Dialog::~List_Dialog()
{
    //dtor
    delete head;
}


void List_Dialog::Lista_initiala()
{
    unsigned int ch=1;
    ch*=100000;

    struct Dialog *first_head;

    do
    {

        struct Dialog *temp;
        temp=new struct Dialog;
        temp->prev=nullptr;
        temp->next_A=nullptr;
        temp->next_B=nullptr;
        temp->next_C=nullptr;

        f>>temp->ID_Nod;
        f>>temp->ID_NextA;
        f>>temp->ID_NextB;
        f>>temp->ID_NextC;
        f>>temp->Voce;
        getline(f,temp->Text);

        if(this->head==nullptr)
        {
            this->head=temp;
            first_head=this->head;
        }
        else
        {
            temp->prev=this->head;
            this->head->next_A=temp;
            this->head=this->head->next_A;

        }

    }while(this->head->ID_NextA!=0);

    this->head=first_head;
}

void List_Dialog::()
{

}
