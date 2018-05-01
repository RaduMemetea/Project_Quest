#ifndef LIST_DIALOG_H
#define LIST_DIALOG_H


class List_Dialog
{
    public:
        List_Dialog();
        virtual ~List_Dialog();

    protected:
        void Lista_initiala();

    private:
        struct Dialog *head;
};

#endif // LIST_DIALOG_H
