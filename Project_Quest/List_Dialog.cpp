#include "List_Dialog.h"
#include <string>
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

#include "Maze.h"

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

List_Dialog::List_Dialog(string chapter_file_name,player *p)
{
    this->head=nullptr;
    Lista_initiala(chapter_file_name,p->r_Name());///Creaza lista initiala cu toate caracteristicile unui nod

}

List_Dialog::~List_Dialog()
{
    //dtor
}


void List_Dialog::Lista_initiala(string chapter_file_name,string Player_name)
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
    }while(this->head->ID_NextA!=0);

    this->head=first_head;
    modifica_caractere();
    modifica_caractere_player_name(Player_name);

    aranjeaza_lista(ch,chapter_file_name);  ///Cauta nodurile si modifica legaturile dintre noduri
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

        for(;L->ID_NextA!=0;L=L->next_A)
        {
            if(L->ID_Nod==n1)
                n_1=L;
            if(L->ID_Nod==n2)
                n_2=L;
        }

        make_link(n_1,n_2,c);/// Face legatura intre nodul n_1 pe pozitia c cu nodul n_2
    }


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
        while(L->Voice.find("_") != string::npos)
        {
            L->Voice.replace(L->Voice.find("_"),1," ");
        }

    }

}

void List_Dialog::modifica_caractere_player_name(std::string name)
{
    struct Dialog *L;
    L=this->head;

    for(;L;L=L->next_A)
    {
        if(L->Voice=="(Player):")
        {
            L->Voice=name+":";
        }

        while(L->Text.find("(Player)") != string::npos)
        {
            L->Text.replace(L->Text.find("(Player)"),8,name);
        }
    }


}

char List_Dialog::HIGH(char b)
{
    return toupper(b);
}




void List_Dialog::Afisare(player *p)
{
    struct Dialog *tHead=this->head;
    std::cout<<tHead->Voice<<tHead->Text<<'\n';

    if(tHead->next_A!=nullptr)
        tHead=tHead->next_A;
    else
        exit(0);
    /// Afisare Titlu Capitol

    do
    {
        if(tHead->ID_NextB==0)
        {
            std::cout<<tHead->Voice<<tHead->Text<<'\n';
            tHead=tHead->next_A;


        }
///     Zona De Verificare Noduri   ///
/// Imposibil de accesat primele 2 dialoguri

        if(tHead->ID_Nod == 0)
           {
                std::cin.ignore();
                Maze a;
                a.afis(p);
                std::cin.ignore();
                system("cls");
           }


/// --------------------------------------------- ///
        if(tHead->ID_NextB!=0)
        {
            std::cout<<tHead->Voice<<tHead->Text<<'\n';

            std::cout<<tHead->next_A->Voice<<tHead->next_A->Text<<'\n'
                     <<tHead->next_B->Voice<<tHead->next_B->Text<<'\n';
            if(tHead->ID_NextC != 0)
            std::cout<<tHead->next_C->Voice<<tHead->next_C->Text<<'\n';
            std::cout<<"Choice: ";
            char C;
                std::cin>>C;
                if(HIGH(C)=='A')
                {
                    tHead=tHead->next_A->next_A;
                }
                else if(HIGH(C)=='B')
                {
                    tHead=tHead->next_B->next_A;
                }
                else if(HIGH(C)=='C')
                {
                    tHead=tHead->next_C->next_A;
                }
        }
    }while(tHead->ID_NextA!=0);
}
