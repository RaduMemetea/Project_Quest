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

        void Lista_initiala(std::string chapter_file_name,std::string Player_name); ///Creaza o lista dublu inlantuita cu nodurile din fisierul 'chapter_file_name' + '.txt'
        void make_link(struct Dialog *n1, struct Dialog *n2, std::string n1_abc);   /// n1- nod initial, n2- nod urmator, n1_abc- pozitia de legatura a lui n2
        void aranjeaza_lista(std::string chapter_file_name);   /// Face legaturile dintre noduri cu informatii din 'chapter_file_name' + '_Links.txt'
        void modifica_caractere();  /// Inlocueste int toata lista "_" cu ' ', "0:" cu '' si "~:" cu Voce -a precedenta
        void modifica_caractere_player_name(std::string Player_name);   /// Inlocuieste int toata lista "(Player)" cu Numele jucatorului

        char HIGH(char);

};

#endif // LIST_DIALOG_H
