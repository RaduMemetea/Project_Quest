#include "Maze.h"
#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include <unistd.h>

#include "Fight.h"

void Create_node(int parent[], int i, Node *created[], Node **root);

struct Node
{
	unsigned int ID;
	struct Node *left, *right, *prev;
};

Maze::Maze()
{

    std::ifstream f("Maze_Vector.txt");
    unsigned int n;
    f>>n;
    int parent[n]={};
    for(unsigned int i=0;i<n;i++)
        f>>parent[i];


	this->root = Create_tree(parent,n);
	PlusOne(this->root);
}

Maze::~Maze()
{

}


Node *newNode(int ID)
{
	Node *temp = new Node;
	temp->ID = ID;
	temp->left = temp->right = temp->prev = nullptr;
	return temp;
}

Node* Maze::Create_tree(int parent[], unsigned int n)
{
	Node *created[n];
	for (unsigned int i=0; i<n; i++)
		created[i] = nullptr;

	Node *tRoot = nullptr;
	for (unsigned int i=0; i<n; i++)
		Create_node(parent, i, created, &tRoot);

	return tRoot;
}

void Create_node(int parent[], int i, Node *created[], Node **root)
{
	if (created[i] != nullptr)
		return;

	created[i] = newNode(i);

	if (parent[i] == -1)
	{
		*root = created[i];
		return;
	}

	if (created[parent[i]] == nullptr)
		Create_node(parent, parent[i], created, root);

	Node *p = created[parent[i]];

	if (p->left == nullptr)
		{
		    p->left = created[i];
		    p->left->prev = p;
		}
	else
    {
        p->right = created[i];
        p->right->prev = p;
    }
}

void Maze::PlusOne(Node *r)
{
	if (r != nullptr)
	{
		PlusOne(r->left);
		r->ID=r->ID+1;
		PlusOne(r->right);
	}
}

void inorder(Node *r)/// afisarea arborelui
{
	if (r != nullptr)
	{
		inorder(r->left);
		std::cout<<r->ID<<' ';
		inorder(r->right);
	}
}


char Maze::HIGH(char b)
{
    return toupper(b);
}

bool verificare_tip_nod(int ID,int tip)
{
    std::ifstream f("Maze_node_tipes.txt");
    int n;
    f>>n;/// nr. tipuri de noduri

    for(int i=0;i<n;i++)
    {
        int k;
        f>>k;/// elemente de tipul k pe linia i
        int elem[k]={};

        for(int j=0;j<k;j++)
            f>>elem[j];

        for(int j=0;j<k;j++)
            if(elem[j] == ID && i==tip)
                return 1;
    }

    return 0;

}



void Maze::afis(player *pp)
{
	player &p=*pp;
    Node *pl=this->root;
    int pas=0;

        std::string
            h0={"<---------------------------------------->\n"},

            h1={"^                                        ^\n"},

            he={"^       Press [ENTER] to continue        ^\n"},

            hc={"^    [L]           [B]            [R]    ^\n"},

            hcnb={"^    [L]                          [R]    ^\n"},

            hu={h0+h1+h1},
            hd={h1+hc},
            hn={h1+he},


            hlr={hu+
                "^    You can move Left[L] or Right[R]    ^\n"
                +h1+hcnb},

            hlbr={hu+
                "^    You can move Left[L] , Right[R]     ^\n"+
                "^              or Back[B]                ^\n"
                +hd},

            hBB={hu+
                "^     You have reached a Battle Stage,   ^\n"+
                "^             Prepare to die!            ^\n"
                +h1+h1},

            h00={hu+
                "^            Empty room...               ^\n"+
                "^               Good luck next time!     ^\n"
                +hn},

            hTR={hu+
                "^     You have reached a Treasure Room,  ^\n"+
                "^         You Are lucky this time!       ^\n"
                +hn},

            hHE={hu+
                "^     You have reached a Heal Spot,      ^\n"+
                "^       Hope you enjoyed the spa!        ^\n"
                +hn},
            hz={hu+
                "^  Congratulation You escaped The Maze   ^\n"
                +h1+hn};


        if(pl->ID == 1)
            {
                system("cls");
            std::cout<<"<---------------------------------------->"<<'\n'
                    << "^                                        ^"<<'\n'
                    << "^         Welcome to The Maze!           ^"<<'\n'
                    << "^                                        ^"<<'\n'
                    << "^                                        ^"<<'\n'
                    << "^                                        ^"<<'\n'
                    << "^                                        ^"<<'\n'
                    << "^       Press [ENTER] to continue        ^"<<'\n'
                    << "<---------------------------------------->"<<'\n';

                std::cin.ignore();
                system("cls");

            }

    for(;pl != nullptr;)
    {
        std:: string hp={"^                  "+std::to_string(pas)+"                     ^\n"};
        if(hp.size()>h0.size())
        {
            hp[h0.size()-2]='^';
            hp[h0.size()-1]='\0';
        }
        hp=hp+h0;

        if(pl->ID == 1) /// nodul Radacina
        {
            system("cls");
            std::cout<<hlr<<hp;
            char C;
            std::cin>>C;
            if(HIGH(C) == 'L')
                pl=pl->left;
            if(HIGH(C) == 'R')
                pl=pl->right;
                pas++;
        }

        else if(verificare_tip_nod(pl->ID,0)) /// noduri de tip Drum
        {
            system("cls");
            std::cout<<hlbr<<hp;
            char C;
            std::cin>>C;
            if(HIGH(C) == 'L')
                pl=pl->left;
            if(HIGH(C) == 'B')
                pl=pl->prev;
            if(HIGH(C) == 'R')
                pl=pl->right;
                pas++;
        }
        else if(verificare_tip_nod(pl->ID,1)) /// noduri de tip Battle
        {
            system("cls");
            std::cout<<hBB<<hp;
            std::cin.ignore();
            std::cin.ignore();
            pl=pl->prev;
            pas++;
            Fight f(&p);
            f.Start()? p.Set_Money(3) : p.Set_Money(0);
            std::cin.ignore();
            std::cin.ignore();

        }
        else if(verificare_tip_nod(pl->ID,2)) /// noduri de tip Heal
        {
            system("cls");
            std::cout<<hHE<<hp;
            std::cin.ignore();
            std::cin.ignore();
            pl=pl->prev;
            pas++;
            p.Heal(50);



        }
        else if(verificare_tip_nod(pl->ID,3)) /// noduri de tip 0
        {
            system("cls");
            std::cout<<h00<<hp;
            std::cin.ignore();
            std::cin.ignore();
            pl=pl->prev;
            pas++;
        }
        else if(verificare_tip_nod(pl->ID,4)) /// noduri de tip Treasure
        {
            system("cls");
            std::cout<<hTR<<hp;
            std::cin.ignore();
            std::cin.ignore();
            pl=pl->prev;
            pas++;
            p.Set_W_DMG(1,1);


        }
        else if(verificare_tip_nod(pl->ID,5)) /// noduri de tip End
        {
            system("cls");
            std::cout<<hz<<hp;
            usleep(999999);/// 1 sec
            break;
        }

    }

}

std::string HIGH(std::string b)
{
    b[0]=std::toupper(b[0]);
    return b;
}



