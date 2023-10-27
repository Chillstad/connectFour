#include <iostream>
#include <string>

using namespace std;

//change these to change the grid size
const int WIDTH = 10;
const int HEIGHT = 7;

//function prototypes
void gridToOutput(string inputGrid);
int coordToIndex(int x, int y);
string initializeGrid();
bool dropToken(char token, string& grid);
bool checkWin(char token, string& grid);
bool checkWin(char token, string& grid);
bool checkVertical(char token, string& grid, int x, int y);
bool checkHorizontal(char token, string& grid, int x, int y);
bool checkNegativeOne(char token, string& grid, int x, int y);
bool checkOne(char token, string& grid, int x, int y);

int main() {
    //create grid string
    string grid = initializeGrid();

    //keep track of game state
    bool gameOver = false;

    //title screen
    cout << "XXXX | C O N N E C T   F O U R | OOOO" << endl << endl;

    //print out the grid
    gridToOutput(grid); 

    //gameplay loop. continue until game ends
    while(!gameOver) {

        //inform player
        cout << "Player X's turn." << endl;

        //get user to drop in a token. stop them if they do it wrong.
        while(!dropToken('X', grid)) {
            cout << "Oops, you can't place there! Try again." << endl;
        };

        //show new state
        gridToOutput(grid);

        //check to see if they won
        gameOver = checkWin('X', grid);

        //if they won, stop the loop.
        if (gameOver) {
            cout << "Player X won!" << endl;
            break;
        }

        //inform player
        cout << "Player O's turn." << endl;

        //get user to drop in a token. stop them if they do it wrong.
        while(!dropToken('O', grid)) {
            cout << "Oops, you can't place there! Try again." << endl;
        };

        //show new state
        gridToOutput(grid);

        //check to see if they won
        gameOver = checkWin('O', grid);

        //if they won, stop the loop.
        if (gameOver) {
            cout << "Player O won!" << endl;
            break;
        }
    }
}

//calculate the size of the grid string and create it 
string initializeGrid() {
  string grid = "";
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      grid += "-";
    }
  }
  return grid;
}

//print out the grid's contents
void gridToOutput(string inputGrid) {
  for (int y = HEIGHT - 1; y >= 0; y--) {
    for (int x = 0; x < WIDTH; x++) {
      cout << inputGrid[coordToIndex(x, y)];
    }
    cout << endl;
  }
  cout << "0123456789" << endl;
}

//take a coordinate and convert it to an index in the grid
int coordToIndex(int x, int y) {
  int index = ((y)*WIDTH);
  index += x;
  return index;
}

//asks for player input, then drops a token. returns false if it failed.
bool dropToken(char token, string& grid) {
    int x;
    cout << "Please enter where you would like to drop a token: ";
    cin >> x;
    while (x >= WIDTH) {
        cout << "Please enter a valid number: ";
        cin >> x;
    }
    for (int y = 0; y < HEIGHT; y++) {
        if (grid[coordToIndex(x, y)] == '-') {
            grid[coordToIndex(x,y)] = token;
            return true;
        }
    }
    return false;
}

//uses the other check methods to see if someone won
bool checkWin(char token, string& grid) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (checkVertical(token, grid, x, y)) {
                return true;
            } else if (checkHorizontal(token, grid, x, y)) {
                return true;
            } else if (checkNegativeOne(token, grid, x, y)) {
                return true;
            } else if (checkOne(token, grid, x, y)) {
                return true;
            }
        }
    }
    return false;
}

//checks vertically for a win
bool checkVertical(char token, string& grid, int x, int y) {
    int streak = 0;
    for (int ySelection = 0; ySelection < HEIGHT; ySelection++) {
        if (grid[coordToIndex(x, ySelection)] == token) {
            streak++;
        } else {
            streak = 0;
        }

        if (streak >= 4) {
            return true;
        }
    }

    return false;
}

//checks horizontally for a win
bool checkHorizontal(char token, string& grid, int x, int y) {
    int streak = 0;
    for (int xSelection = 0; xSelection < WIDTH; xSelection++) {
        if (grid[coordToIndex(xSelection, y)] == token) {
            streak++;
        } else {
            streak = 0;
        }

        if (streak >= 4) {
            return true;
        }
    }

    return false;
}

//checks diagonal down for a win
bool checkNegativeOne(char token, string& grid, int x, int y) {
    int streak = 0;
    int steps = 0;
    int xVar = x;
    int yVar = y;

    while((steps < 4) && ((xVar < WIDTH) && (yVar < HEIGHT))) {
        if (grid[coordToIndex(xVar, yVar)] == token) {
            streak += 1;
        } else {
            streak = 0;
        }
        
        xVar++;
        yVar--;

        if (streak >= 4) {
            return true;
        }

        steps++;
    }
    return false;
}

//checks diagonal up for a win
bool checkOne(char token, string& grid, int x, int y) {
    int streak = 0;
    int steps = 0;
    int xVar = x;
    int yVar = y;

    while((steps < 4) && ((xVar < WIDTH) && (yVar < HEIGHT))) {
        if (grid[coordToIndex(xVar, yVar)] == token) {
            streak += 1;
        } else {
            streak = 0;
        }
        
        xVar++;
        yVar++;

        if (streak >= 4) {
            return true;
        }

        steps++;
    }
    return false;
}
