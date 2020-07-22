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

vector<vector<int>> mine_field;
vector<vector<bool>> is_opened;

const size_t N_rows = 10;
const size_t M_cols = 10;


void generateMainField(size_t mines) {

    srand(time(0));

    if (mines >= N_rows*M_cols) {
        throw out_of_range("too many mines");
    }

    mine_field.clear();
    is_opened.clear();

    // Initialize empry mine field
    for (size_t r = 0; r < N_rows; ++r) {
        is_opened.push_back(vector<bool>());
        mine_field.push_back(vector<int>());
        for (size_t c = 0; c < M_cols; ++c) {
            is_opened.at(r).push_back(false);
            mine_field.at(r).push_back(0);
        }
    }

    while (mines > 0) {
        size_t row = rand() % N_rows;
        size_t col = rand() % M_cols;

        if (mine_field[row][col] == 9)
            continue;
        
        --mines;
        mine_field[row][col] = 9;

        for (size_t r = (row > 0)? row-1: row; r <= ((row < N_rows-1)? row+1: row); ++r) {
            for (size_t c = (col > 0)? col-1: col; c <= ((col < M_cols-1)? col+1: col); ++c) {
                if (mine_field[r][c] != 9)
                    ++mine_field[r][c];
            }
        }
    }
}

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

    for (size_t r = (row > 0)? row-1: row; r <= ((row < N_rows-1)? row+1: row); ++r) {
        for (size_t c = (col > 0)? col-1: col; c <= ((col < M_cols-1)? col+1: col); ++c) {
            if (r == row && c == col)
                continue;
            click(r, c);
        }
    }

    return GameState::Step;
}

int main() {
    generateMainField(10);

    printOpenedField();

    GameState game_state;
    
    do {
        int row = 0, col = 0;
        cout << "Enter row: ";
        cin >> row;

        cout << "Enter col: ";
        cin >> col;

        game_state = click(row, col);
        printOpenedField();

        cout << endl;
    } while (game_state == GameState::Step);

    if (game_state == GameState::Won)
        cout << "You won!" << endl;
    else
        cout << "You lost" << endl;
}