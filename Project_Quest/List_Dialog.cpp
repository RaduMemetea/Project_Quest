#include "List_Dialog.h"
#include <string>
#include <fstream>
#include <iostream>


using std::string;

struct Dialog
{
    struct Dialog *prev;
    unsigned int ID_Nod, ID_NextA, ID_NextB, ID_NextC;
    string Voice;
    string Text;
    struct Dialog *next_A,*next_B,*next_C;
};

List_Dialog::List_Dialog()
{
    this->head=nullptr;
}

List_Dialog::List_Dialog(string chapter_file_name)
{
    this->head=nullptr;
    Lista_initiala(chapter_file_name);

}

List_Dialog::~List_Dialog()
{
    //dtor
}


void List_Dialog::Lista_initiala(string chapter_file_name)
{
    std::ifstream f(chapter_file_name+".txt");

    unsigned int ch;
    f>>ch;

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
        f>>temp->Voice;
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
    }while(this->head->ID_NextA!=(ch+1)*100000);

    this->head=first_head;
    modifica_caractere();

    aranjeaza_lista(ch,chapter_file_name);
}

void List_Dialog::make_link(struct Dialog *n1, struct Dialog *n2, string n1_abc)
{
    if(n1_abc=="A")
    {
        n1->next_A=n2;
    }

    if(n1_abc=="B")
    {
        n1->next_B=n2;
    }

    if(n1_abc=="C")
    {
        n1->next_C=n2;
    }
}

void List_Dialog::aranjeaza_lista(unsigned int ch,string chapter_file_name)
{
    std::ifstream f(chapter_file_name+"_Links.txt");

    unsigned int n1,n2;
    string c;
    struct Dialog *L, *n_1, *n_2;

    for(;f>>n1;)
    {
        f>>n2>>c;
        L=this->head;

        for(;L->ID_NextA!=(ch+1)*100000;L=L->next_A)
        {
            if(L->ID_Nod==n1)
                n_1=L;
            if(L->ID_Nod==n2)
                n_2=L;
        }

        make_link(n_1,n_2,c);
    }


}

void List_Dialog::modifica_caractere()
{
    struct Dialog *L;
    L=this->head;

    for(;L;L=L->next_A)
    {
        if(L->Voice=="~:")
        {
            L->Voice=L->prev->Voice;
        }
        if(L->Voice=="0:")
        {
            L->Voice="";
        }
        if(L->Voice=="(Player):")
        {
            L->Voice="[PlaceHolder]:";
        }

        while(L->Voice.find("_") != string::npos)
        {
            L->Voice.replace(L->Voice.find("_"),1," ");
        }

        while(L->Text.find("(Player)") != string::npos)
        {
            L->Text.replace(L->Text.find("(Player)"),8,"[PlaceHolder]");
        }
    }

}

unsigned int List_Dialog::afisare_id()
{
    return this->head->ID_Nod;
}
