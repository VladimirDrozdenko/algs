//
// Given a 2D grid map of .'s that represent land and #'s that represent water.
// An island is formed by connecting adjacent lend cells horizontally and vertically
// and is surounded by water. Find the number of islands and the max island size.
//

#include <iostream>
#include <vector>
using namespace std;

const vector<vector<char>> field = {
    vector<char>{'.', '#', '.', '#', '#', '.'},
    vector<char>{'#', '.', '.', '#', '.', '.'},
    vector<char>{'#', '.', '#', '.', '.', '#'},
    vector<char>{'#', '.', '.', '#', '#', '.'},
    vector<char>{'.', '.', '#', '.', '.', '.'},
    vector<char>{'#', '#', '.', '#', '#', '.'},
};

vector<vector<bool>> visited;


bool isValidCell(int r, int c) {
    if (r < 0 || r >= field.size() || c < 0 || c >= field[0].size()) {
        return false;
    }

    if (visited[r][c] || field[r][c] == '#') {
        return false;
    }

    return true;
}

void islandSize(int r, int c, int& island_size) {
    const static int dx[4] = {-1, 0, 1, 0};
    const static int dy[4] = {0, -1, 0, 1};

    visited[r][c] = true;
    ++island_size;

    for (int i = 0; i < 4; ++i) {
        if (isValidCell(r+dy[i], c+dx[i])) {
            islandSize(r+dy[i], c+dx[i], island_size);
        }
    }
}

int main() {
    // fill visited array
    for (int i = 0; i < field.size(); ++i) {
        visited.push_back(vector<bool>());
        for (int j = 0; j < field[0].size(); ++j) {
            visited[i].push_back(false);
        }
    }

    int count_islands = 0;
    int max_island_size = 0;

    for (int r = 0; r < field.size(); ++r) {
        for (int c = 0; c < field[0].size(); ++c) {
            if (isValidCell(r, c)) {
                ++count_islands;

                int island_size = 0;
                islandSize(r, c, island_size);
                max_island_size = max(max_island_size, island_size);
            }
        }
    }

    cout << "Number of islands: " << count_islands << endl;
    cout << "Max island size:   " << max_island_size << endl;
}