/*
Lee's algorithm (breadth first search)

You are given a maze in the form of a binary matrix (0 -> obstacle & 1 -> free cell).
Find the shortest path from a source cell to a given destination cell.

         1, 1, 1, 1, 1
         0, 1, 1, 0, 1
A[nxm] = 1, 0, 1, 1, 1
         0, 0, 1, 1, 0
         1, 1, 1, 0, 0

Source: (3, 2)
Dest:   (0, 1)
Answer: 5
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>

using namespace std;

// maze dimentions
const size_t n = 10, m = 10;

// maze matrix
int maze[n][m] = 
{
/*       0  1  2  3  4  5  6  7  8  9  */
/* 0 */ {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
/* 1 */ {1, 0, 1, 1, 1, 1, 0, 1, 1, 0},
/* 2 */ {0, 1, 1, 1, 1, 1, 0, 0, 1, 0},
/* 3 */ {0, 0, 1, 1, 1, 0, 0, 0, 1, 0},
/* 4 */ {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
/* 5 */ {0, 1, 0, 1, 1, 1, 1, 0, 1, 1},
/* 6 */ {0, 1, 0, 0, 0, 1, 0, 1, 0, 1},
/* 7 */ {0, 1, 1, 1, 0, 1, 1, 1, 0, 1},
/* 8 */ {1, 0, 0, 1, 1, 1, 0, 1, 1, 1},
/* 9 */ {0, 1, 1, 1, 1, 0, 0, 1, 0, 1}
};


void printPath(int tracker[n][m], pair<int, int> dest)
{
    if (tracker[dest.first][dest.second] == 1)
    {
        return;
    }

    // check right
    if (dest.second > 0 && tracker[dest.first][dest.second - 1] == tracker[dest.first][dest.second] - 1)
    {
        printPath(tracker, make_pair(dest.first, dest.second - 1));
    }
    // check top
    else if (dest.first > 0 && tracker[dest.first - 1][dest.second] == tracker[dest.first][dest.second] - 1)
    {
        printPath(tracker, make_pair(dest.first - 1, dest.second));
    }
    // check right
    else if (dest.second < m - 1 && tracker[dest.first][dest.second + 1] == tracker[dest.first][dest.second] - 1)
    {
        printPath(tracker, make_pair(dest.first, dest.second + 1));
    }
    // check bottom
    else if (dest.first < n - 1 && tracker[dest.first + 1][dest.second] == tracker[dest.first][dest.second] - 1)
    {
        printPath(tracker, make_pair(dest.first + 1, dest.second));
    }
    
    cout << "(" << dest.first << "," << dest.second << ")" << endl;
}

int leeAlgDistance(const pair<int, int>& src, const pair<int, int>& dest)
{
    if (!maze[src.first][src.second] || !maze[dest.first][dest.second])
        return -1;

    int tracker[n][m];
    memset(&tracker, 0, sizeof(int)*n*m);
    tracker[src.first][src.second] = 1;

    queue<pair<int, int> > q;
    q.push(make_pair(src.first, src.second));
    
    while (!q.empty())
    {
        pair<int, int> cell = q.front();

        // reached destination
        if (cell.first == dest.first && cell.second == dest.second)
        {
            printPath(tracker, dest);
            return tracker[cell.first][cell.second] - 1;
        }

        q.pop();

        // add neighbor cells to the queue 

        // left
        if (cell.second > 0 && maze[cell.first][cell.second - 1] && tracker[cell.first][cell.second - 1] == 0)
        {
            tracker[cell.first][cell.second - 1] = tracker[cell.first][cell.second] + 1;
            q.push(make_pair(cell.first, cell.second - 1));
        }

        // top
        if (cell.first > 0 && maze[cell.first - 1][cell.second] && tracker[cell.first - 1][cell.second] == 0)
        {
            tracker[cell.first - 1][cell.second] = tracker[cell.first][cell.second] + 1;
            q.push(make_pair(cell.first - 1, cell.second));
        }

        // right
        if (cell.second < m - 1 && maze[cell.first][cell.second + 1] && tracker[cell.first][cell.second + 1] == 0)
        {
            tracker[cell.first][cell.second + 1] = tracker[cell.first][cell.second] + 1;
            q.push(make_pair(cell.first, cell.second + 1));
        }

        // bottom
        if (cell.first < n - 1 && maze[cell.first + 1][cell.second] && tracker[cell.first + 1][cell.second] == 0)
        {
            tracker[cell.first + 1][cell.second] = tracker[cell.first][cell.second] + 1;
            q.push(make_pair(cell.first + 1, cell.second));
        }
    }

    return -1;
}

int main()
{
    int srcR = 7, srcC = 1, destR = 4, destC = 3;
    int min_distance = leeAlgDistance(make_pair(srcR, srcC), make_pair(destR, destC));

    if (min_distance >= 0)
    {
        cout << "Minimum distance (" << srcR << "," << srcC << ") -> (" << destR << "," << destC << ") = " 
             << min_distance << endl;
    }
    else
    {
        cout << "There is no path (" << srcR << "," << srcC << ") -> (" << destR << "," << destC << ")" << endl;
    }
}