#ifndef LIST_DIALOG_H
#define LIST_DIALOG_H
#include <string>

class List_Dialog
{
    public:
        List_Dialog();
        List_Dialog(std::string chapter_file_name);/// numele fisierului fara extensie dar care trebuie sa fie .txt
        virtual ~List_Dialog();
        unsigned int afisare_id();
    protected:

    private:
        struct Dialog *head;

        void Lista_initiala(std::string chapter_file_name);
        void make_link(struct Dialog *n1, struct Dialog *n2, std::string n1_abc);/// n1- nod initial, n2- nod urmator, n1_abc- pozitia de legatura a lui n2
        void aranjeaza_lista(unsigned int ch,std::string chapter_file_name);
        void modifica_caractere();

};

#endif // LIST_DIALOG_H
