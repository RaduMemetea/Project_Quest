#ifndef LIST_CHAPTER_H
#define LIST_CHAPTER_H


class List_Chapter
{
    public:
        List_Chapter();
        virtual ~List_Chapter();
        void Chapter_Adding(struct Dialog NL);
    protected:

    private:
        struct Capitol *head,*tail;

};

#endif // LIST_CHAPTER_H
