/* 
maze.cpp

Author:Nicole Fergie

Short description of this file:
This is the main file of the program. It reads in a maze,
searches the maze and replaces the shortest path with stars,
and prints out the final maze. 
*/

#include <iostream>
#include "mazeio.h"
#include "queue.h"

using namespace std;

// Prototype for maze_search, which you will fill in below.
int maze_search(char**, int, int);

//sets the current location to a star
Location set_star(char**, Location**, Location);

//checks to see if location hasnt been visited and is not wall
bool is_open(Location, char**, bool**);

//checks to see if the location is the finish location
bool is_finish(Location, Location);

//deletes all dynamically allocated memory
void del_all(Location** pred, bool** visit, int rows);

// main function to read, solve maze, and print result
int main() {
   int rows, cols, result = 0;
   char** mymaze;
   

   mymaze = read_maze(&rows, &cols);
   
   if (mymaze == NULL) {
      cout << "Error, input format incorrect" << endl;
      return 1;
   }

   // when working on Checkpoint 3, you will call maze_search here.
   // here. but for Checkpoint 1, just assume we found the path.
   result = maze_search(mymaze, rows, cols); 

   // examine value returned by maze_search and print appropriate output
   if (result == 1) { // path found!
      print_maze(mymaze, rows, cols);
   }
   else if (result == 0) { // no path :(
      cout << "No path could be found!" << endl;
   }
   else { // result == -1
      cout << "Invalid maze." << endl;
   }

   // ADD CODE HERE to delete all memory 
   // that read_maze allocated
      for(int i =0; i <rows; i++){
      delete[] mymaze[i];
   }
   delete[] mymaze;

   return 0;
}

/**************************************************
 * Attempt to find shortest path and return:
 *  1 if successful
 *  0 if no path exists
 * -1 if invalid maze (not exactly one S and one F)
 *
 * If path is found fill it in with '*' characters
 *  but don't overwrite the 'S' and 'F' cells
 *************************************************/
int maze_search(char** maze, int rows, int cols){
   int start= 0;
   int finish = 0;
   Location startLoc;
   Location finishLoc;
   for(int i = 0; i < rows; i++){
      for (int j = 0; j < cols; j++){
         if(maze[i][j] == 'S'){
            start = start +1;
            startLoc.row = i;
            startLoc.col = j;
         }
         if(maze[i][j]== 'F'){
            finishLoc.row = i;
            finishLoc.col = j;
            finish = finish +1;
         }
      }
   }

   if((finish != 1) || (start != 1)){
      return -1;
   }

   bool** visited = new bool*[rows];
   Location** pred = new Location*[rows];

   
   for(int i=0; i < rows; i++){
      visited[i]= new bool[cols];
      pred[i] = new Location[cols];
   }

   for(int i =0; i <rows; i++){
      for(int j = 0; j<cols; j++){
         visited[i][j] = 0;
         Location loc = pred[i][j];
         loc.row = -1;
         loc.col = -1;
      }
   }

   Queue bfsQueue(rows*cols);

   bfsQueue.add_to_back(startLoc);

   while(!bfsQueue.is_empty()){
      Location curr = bfsQueue.remove_from_front();
      int curRow = curr.row;
      int curCol = curr.col;
      Location nLoc;

      //north
      if((curRow-1) >= 0){
         nLoc.row = curRow - 1;
         nLoc.col =curCol;
         if(is_finish(nLoc, finishLoc)){
            while((curr.row != startLoc.row) 
               || (curr.col != startLoc.col)){
               curr= set_star(maze, pred, curr);
            }
            del_all(pred, visited, rows);
            return 1;
         }
         else if(is_open(nLoc, maze, visited)){
            bfsQueue.add_to_back(nLoc);
            visited[nLoc.row][nLoc.col] = 1;
            pred[nLoc.row][nLoc.col]= curr;
         }
      }
      //west
      if((curCol - 1) >= 0){
         nLoc.row = curRow;
         nLoc.col = curCol - 1;
         if(is_finish(nLoc, finishLoc)){
            while((curr.row != startLoc.row)
               || (curr.col != startLoc.col)){
               curr = set_star(maze, pred, curr);
            }
            del_all(pred, visited, rows);
            return 1;
         }
         else if(is_open(nLoc, maze, visited)){
            bfsQueue.add_to_back(nLoc);
            visited[nLoc.row][nLoc.col] = 1;
            pred[nLoc.row][nLoc.col]= curr;
         }
      }
      //south
      if((curRow+1) < rows){
         nLoc.row = curRow + 1;
         nLoc.col = curCol;
         if(is_finish(nLoc, finishLoc)){
            while((curr.row != startLoc.row)
               || (curr.col != startLoc.col)){
               curr = set_star(maze, pred, curr);
            }
            del_all(pred, visited, rows);
            return 1;
         }
         else if(is_open(nLoc, maze, visited)){
            bfsQueue.add_to_back(nLoc);
            visited[nLoc.row][nLoc.col] = 1;
            pred[nLoc.row][nLoc.col]= curr;
         }
      }
      //east
      if((curCol+1) < cols){
         nLoc.row = curRow;
         nLoc.col = curCol + 1;
         if(is_finish(nLoc, finishLoc)){
            while((curr.row != startLoc.row)
               || (curr.col != startLoc.col)){
               curr = set_star(maze, pred, curr);
            }
            del_all(pred, visited, rows);
            return 1;
         }
         else if(is_open(nLoc, maze, visited)){
            bfsQueue.add_to_back(nLoc);
            visited[nLoc.row][nLoc.col] = 1;
            pred[nLoc.row][nLoc.col]= curr;
         }
      }
   }
   del_all(pred, visited, rows);
   return 0;
}

bool is_open(Location nLoc, char** maze, bool** visit){
   if((maze[nLoc.row][nLoc.col] == '.')
   && (visit[nLoc.row][nLoc.col] == 0)){
      return true;
   }else{
      return false;
   }
}
bool is_finish(Location nLoc, Location finishLoc){
   if((nLoc.row == finishLoc.row)
      && (nLoc.col == finishLoc.col)){
      return true;
   }else{
      return false;
   }
}


Location set_star(char** maze, Location** pre, Location cur){
   maze[cur.row][cur.col] = '*';
   return pre[cur.row][cur.col];
}

void del_all(Location** pred, bool** visit, int rows){
   for(int i =0; i <rows; i++){
      delete[] visit[i];
      delete[] pred[i];
   }
   delete[] visit;
   delete[] pred;
}
