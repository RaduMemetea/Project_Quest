#ifndef STORY_NODE_H
#define STORY_NODE_H
#include <string>

class Story_Node
{
    public:
        Story_Node();
        virtual ~Story_Node();

    protected:

    private:
        int ID;
        int ID_A, ID_B, ID_C;
        std::string Line;
        class Story_Node *prec;
        class Story_Node *next;
};

#endif // STORY_NODE_H
