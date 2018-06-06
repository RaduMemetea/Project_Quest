# Project_Quest

    This project is a short adventure game with multiple choises when it comes to the story part, 
    it incluses a labirinth as a mini gamemode to complement the other parts.
 
The program has internaly 4 main components and 2 secondary ones, <br>
    The main ones are :<br>
        the chapter list (implemented with a simple linked list), 
        the dialog list (implemented with a doubly linked lista with 3 exit points),
        the player component which stores the player data(as name, health, armour, and damage),
        and the maze (implemented with binary trees).<br>
    The secondary components are:<br>
        the enemy witch genereates randomly the names and stats
        and the fight which containst the fight elements.<br>
        

For the program to work it needs minimum 5 external files:<br>
    1. Maze_vector.txt which stores the tree parent vector on the second line and in the first the number of nodes<br>
    2. Maze_node_tipes.txt which stores what each nodes do when traversed as:<br>
          0: It's a link(rode) node to the other nodes<br>
          1: Battle node in withc the fight componend is called<br>
          2: Heal point (+50hp)<br>
          3: Empty node (like an empty room)<br>
          4: Treasure room witch gives the player +1 Min_Damage, +1 Max_Damage<br>
          5: End node which means the exit of the maze<br>
       This file is structured as: <br><br>
            line 1: number of node tipes ('6' at this moment because each tipe needs it's own code)<br>
            line 2-7: #1 how many nodes and #2 nodes ID |
                      ex: 3(nr. of nodes) 14 26 55(tree ID values +1) [an complete example in the project files]<br><br>
    3. A Project_Quest_Story folder with<br>
       a) Story_Chapters.txt in which you tell how many files you are working with and their paths (no extension mentioned int the path             here but the file should have .txt) on diferent lines.<br><br>
       b) {chapter_name}.txt    each line has:  own ID, the next node ID, 0, 0 (if it's a choice node swap the 0's with the choice options node ID), the voice ({something}: will stai the same, ~: will repete the last one, A/B/C: if a choice, (Player): will be swaped with the player name asked at the start of the program and 0: will set the voice to nothing), the text which can include "(Player)" and will be swaped with the player's name.<br><br>
          As the ID structure i used:<br>
            #1 digit the chapter number the next 2 the dialog line, next one the choice(if existend) number(1/2/3) and the last ones the choice dialog line ex: 109210  | 1-> chapter number, 09-> chapter main dialog line, 2-> second(B) option of the line 09, 10-> choice dialog line. or 115000 -> this is a main line with no choice parameters set.<br><br>
          To end the chapter the last dialog line should have the next line Id set to 0 and at the end shoul be a line with [0 0 0 0 0 0] that significates the end of chapter.<br><br>
       c) {chapter_name}_Links.txt in witch you link the nodes like: 103000 103200 B | node 103200 will be linked with node 103000 on the second(B) exit. In this file is required to link in pairs like [node 103200 will be linked to 10300 on B exit and the end of 103200's dialog in this case 103201 to be linked to the coresponding next dialog for the continuation of the story] or in case of 3 choices [first you need to link the coresponding nodes to the exit's of the choice node and then link the second choice dialog's end node to the coresponding exit then the end of the first choice to the coresponding end of that line of dialog].<br><br>
       The b) and c) step's can be repeated 8 more times in this structure to form 9 chapters but don't forget to mention them in the a)'s file.
