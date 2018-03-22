#include "Story_Node.h"
#include <string>
#include <fstream>
#include <iostream>

std::ifstream f("Project_Quest_Story.txt");

Story_Node::Story_Node()
{
    f>>this->ID>>this->ID_A>>this->ID_B>>this->ID_C;
    std::getline(f,this->Line);

}

Story_Node::~Story_Node()
{
    std::cout<<ID<<'\n'
        <<ID_A<<'\n'
        <<ID_B<<'\n'
        <<ID_C<<'\n'
        <<Line;
}
