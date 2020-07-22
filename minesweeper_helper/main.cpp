/*
Implement Minesweeper
Minesweeper is a game where the objective is correctly identify the location of all mines in a given grid. You are given a uniform grid of gray squares in the beginning of the game. Each square contains either a mine (indicated by a value of 9), or an empty square. Empty squares have a number indicating the count of mines in the adjacent squares. Empty squares can have counts from zero (no adjacent mines) up to 8 (all adjacent squares are mines).

If you were to take a complete grid, for example, you can see which squares have mines and which squares are empty:
0  0  0  0  0
0  0  0  0  0
1  1  1  0  0
1  9  1  0  0
1  2  2  1  0
0  1  9  1  0
0  1  1  1  0

The squares with "2" indicate that there 2 mines adjacent to that particular square.

Gameplay starts with a user un-hiding a square at random. If the square contains a mine, the game ends. If it is a blank, the number of adjacent mines is revealed.

Exposing a zero means that there are no adjacent mines, so exposing all adjacent squares is guaranteed safe. As a convenience to the player, the game continues to expose adjacent squares until a non-zero square is reached.

For example, if you click on the top right corner you get this ('-' means hidden):

0  0  0  0  0
0  0  0  0  0
1  1  1  0  0
-  -  1  0  0
-  -  2  1  0
-  -  -  1  0
-  -  -  1  0
*/

#include <iostream>
#include <vector>
using namespace std;

const vector<vector<int>> mine_field = {
        vector<int>({0, 0, 0, 0, 0}),
        vector<int>({0, 0, 0, 0, 0}),
        vector<int>({1, 1, 1, 0, 0}),
        vector<int>({1, 9, 1, 0, 0}),
        vector<int>({1, 2, 3, 1, 0}),
        vector<int>({0, 1, 9, 1, 0}),
        vector<int>({0, 1, 1, 1, 0}),
    };
const size_t N = mine_field.size();
const size_t M = mine_field.at(0).size();

vector<vector<bool>> is_opened;

void printOpenedField() {
    for (size_t r = 0; r < mine_field.size(); ++r) {
        for (size_t c = 0; c < mine_field.at(0).size(); ++c) {
            if (is_opened.at(r).at(c)) {
                cout << mine_field.at(r).at(c) << " ";
            } else {
                cout << "x ";
            }
        }
        cout << endl;
    }

    cout << endl;
}

enum GameState {
    Step = 0,
    Mine,
    Won
};

GameState click(int row, int col) {
    if (is_opened[row][col])
        return GameState::Step;

    is_opened[row][col] = true;
    if (mine_field[row][col] == 9)
        return GameState::Mine;

    if (mine_field[row][col] != 0)
        return GameState::Step;

    for (size_t r = (row > 0)? row-1: row; r <= ((row < N-1)? row+1: row); ++r) {
        for (size_t c = (col > 0)? col-1: col; c <= ((col < M-1)? col+1: col); ++c) {
            if (r == row && c == col)
                continue;
            click(r, c);
        }
    }

    return GameState::Step;
}

int main() {
    for (size_t r = 0; r < mine_field.size(); ++r) {
        is_opened.push_back(vector<bool>());
        for (size_t c = 0; c < mine_field.at(0).size(); ++c) {
            is_opened.at(r).push_back(false);
        }
    }

    printOpenedField();

    GameState game_state = Step;
    
    do {
        int row = 0, col = 0;
        // cout << "Enter row: ";
        // cin >> row;

        // cout << "Enter col: ";
        // cin >> col;

        game_state = click(row, col);
        printOpenedField();

        game_state = click(3, 0);
        printOpenedField();

        game_state = click(6, 0);
        printOpenedField();

        cout << endl;
        return 0;
    } while (game_state == GameState::Step);

    if (game_state == GameState::Won)
        cout << "You won!" << endl;
    else
        cout << "You lost" << endl;
}