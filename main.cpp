#include <iostream>
#include <string>

using namespace std;

const int WIDTH = 10;
const int HEIGHT = 7;

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
  string grid = initializeGrid();
  int placement;
  bool gameOver = false;
  gridToOutput(grid); 

  while(!gameOver) {
    while(!dropToken('X', grid)) {
        cout << "Oops, you can't place there! Try again." << endl;
    };
    gridToOutput(grid);
    gameOver = checkWin('X', grid);
    if (gameOver) {
        continue;
    }
    while(!dropToken('O', grid)) {
        cout << "Oops, you can't place there! Try again." << endl;
    };
    gridToOutput(grid);
    gameOver = checkWin('O', grid);
  }
}

string initializeGrid() {
  string grid = "";
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      grid += "-";
    }
  }
  return grid;
}

void gridToOutput(string inputGrid) {
  for (int y = HEIGHT - 1; y >= 0; y--) {
    for (int x = 0; x < WIDTH; x++) {
      cout << inputGrid[coordToIndex(x, y)];
    }
    cout << endl;
  }
}

int coordToIndex(int x, int y) {
  int index = ((y)*WIDTH);
  index += x;
  return index;
}

bool dropToken(char token, string& grid) {
    int x;
    cout << "Please enter where you would like to drop a token:";
    cin >> x;
    for (int y = 0; y < HEIGHT; y++) {
        if (grid[coordToIndex(x, y)] == '-') {
            grid[coordToIndex(x,y)] = token;
            return true;
        }
    }
    return false;
}

bool checkWin(char token, string& grid) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (checkVertical(token, grid, x, y)) {
                return true;
            } else if (checkHorizontal(token, grid, x, y)) {
                return true;
            }
        }
    }
    return false;
}

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

bool checkNegativeOne(char token, string& grid, int x, int y) {

}

bool checkOne(char token, string& grid, int x, int y) {

}
