// langtonsant.c
# include <stdio.h>
# include <time.h>
# include <stdlib.h>

# define HEIGHT 5
# define LENGTH 5
# define RIGHT 'E'
# define LEFT 'W'
# define UP 'N'
# define DOWN 'S'

// 1. draw a board
// 2. define the 1st step, its position and facing
// 3. define the 2nd step, its poslsition and facing, depend on the color of cell. 
// 4. in the following iterations, do the move, flip and print the board

// Use the structure to store ant's status. Its location and facing
// Use structure to define the ant's status is similar to the OOP (Objective Oriented Programming, e.g. C++, Java, etc.)
// You can call either the instance or the pointer of the structure.
// We can discuss in our next meeting.
typedef struct AntState {
    char facing;
    int x;
    int y;
} Ant; 

// Optional. Make the program fancier
char r2() {
    // random function, generate 0 or 1
    int r = (rand() % (1 - 0 + 1)) + 0; 
    if (r == 0) 
        return '.';
    else 
        return '#';
}

// Create the board. Only need to be called at the beginning of the main func
// Just like the code we wrote in our last meeting
void initBoard(char board[HEIGHT][LENGTH]) {
    // All the cells are black on the board now.
    // Consider to use random.
    for (int i=0; i < HEIGHT; i++) {
        for (int j=0; j < LENGTH; j++) {
            board[i][j] = r2();
            // to debug, I have set the board full of black or white, to verify the move conditions were correctly set.
            // board[i][j] = '#';
        }
    }
}

// Printout the board, called after each iteration
// Just like the code we wrote in our last meeting (similar to initBoard())
void printBoard(char board[HEIGHT][LENGTH]) {
    printf("=====START=====\n");
    for (int i=0; i < HEIGHT; i++) {
        for (int j=0; j < LENGTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    printf("=====END=====\n");
}

// Ant move on the board.
// Ant turns and moves
// Cell's color flip
// Just like conditions we wrote in last meeting
void moveOnBoard(char board[HEIGHT][LENGTH], Ant* ant) {
    // If the cell is white...
    if (board[ant->x][ant->y] == '#') {
      if (ant->facing == RIGHT) {
          ant->facing = DOWN;
          board[ant->x][ant->y] = '.';
          ant->x += 1;
      } 
      else if (ant->facing == LEFT) {
          ant->facing = UP;
          board[ant->x][ant->y] = '.';
          ant->x -= 1;
      } 
      else if (ant->facing == UP) {
          ant->facing = RIGHT;
          board[ant->x][ant->y] = '.';
          ant->y += 1;
      } 
      else if (ant->facing == DOWN) {
          ant->facing = LEFT;
          board[ant->x][ant->y] = '.';
          ant->y -= 1;
      }
    } 
    
    // If the cell is black
    else if (board[ant->x][ant->y] == '.') {
      if (ant->facing == RIGHT) {
          ant->facing = UP;
          board[ant->x][ant->y] = '#';
          ant->x -= 1;
      } 
      else if (ant->facing == LEFT) {
          ant->facing = DOWN;
          board[ant->x][ant->y] = '#';
          ant->x += 1;
      } 
      else if (ant->facing == UP) {
          ant->facing = LEFT;
          board[ant->x][ant->y] = '#';
          ant->y -= 1;
      } 
      else if (ant->facing == DOWN) {
          ant->facing = RIGHT;
          board[ant->x][ant->y] = '#';
          ant->y += 1;          
      }
    }
}

int main () {
    // for random, time as the seed
    srand(time(0));
    // Create the board
    char board[HEIGHT][LENGTH];
    // Fill the board with black and white colors
    initBoard(board);
    // For debug purpose, printout the Board after init
    printBoard(board);
    // create and init the Ant
    Ant ant;
    ant.facing = RIGHT;
    // Init Ant's orig position on the board. Need dynamic change
    ant.x = 3;
    ant.y = 2;

    // For debug purpose only. Limit iterations. Otherwise, use the range. Becareful! move in the range may take forever...
    // However, because the board were generated randomly... Thus, there is the risk that move out of the board within specified steps.
    for (int i = 0; i < 10; i++) {
    //while (ant.x < HEIGHT && ant.x > 0 && ant.y < HEIGHT && ant.y > 0) {
        // For debug purpose. Show where the ant is, and the ant's facing
        printf("Before moving, Ant is on the board: [%d, %d], and facing: %c\n", ant.x, ant.y, ant.facing);
        //move
        moveOnBoard(board, &ant);
        // For debug purpose. Show where the ant is, and the ant's facing
        printf("After moving, Ant is on the board: [%d, %d], and facing: %c\n", ant.x, ant.y, ant.facing);
        // Print out the board
        printBoard(board);
    }
    return 0;
}