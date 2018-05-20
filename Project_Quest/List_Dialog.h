#ifndef LIST_DIALOG_H
#define LIST_DIALOG_H
#include <string>

#include "player.h"

class List_Dialog
{
    public:
        List_Dialog();
        List_Dialog(std::string chapter_file_name,player *p);/// numele fisierului fara extensie dar care trebuie sa fie .txt
        virtual ~List_Dialog();

        void Afisare(player *p);

    protected:

    private:
        struct Dialog *head;

        void Lista_initiala(std::string chapter_file_name,std::string Player_name);
        void make_link(struct Dialog *n1, struct Dialog *n2, std::string n1_abc);/// n1- nod initial, n2- nod urmator, n1_abc- pozitia de legatura a lui n2
        void aranjeaza_lista(unsigned int ch,std::string chapter_file_name);
        void modifica_caractere();
        void modifica_caractere_player_name(std::string Player_name);

        char HIGH(char);

};

#endif // LIST_DIALOG_H
