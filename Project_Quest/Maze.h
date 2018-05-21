#ifndef MAZE_H
#define MAZE_H
#include "player.h"
#include "Enemy.h"

class Maze
{
    public:
        Maze();
        virtual ~Maze();

        void afis(player *p);

    protected:

    private:
        struct Node *root;

        Node* Create_tree(int parent[], unsigned int n);
        void PlusOne(Node *r);

        char HIGH(char);

};

#endif // MAZE_H
