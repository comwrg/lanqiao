// eight queens puzzle

#include <iostream>
using namespace std;
#define SIZE 8

void show(const int chessboard[SIZE][SIZE]) {
    // print chessboard
    cout << "  ";
    for (int i = 0; i < SIZE; i++)
        cout << i << " ";
    cout << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << i << " ";
        for (int j = 0; j < SIZE; j++) {
            if (chessboard[i][j] == 0)
                cout << "| ";
            else
                cout << "# ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isValid(const int chessboard[SIZE][SIZE]) {
    // loop row and column
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (chessboard[i][j] == 0)
                continue;

            for (int k = 0; k < SIZE; k++) {
                // loop row
                if (k != j && chessboard[i][k] == 1)
                    return false;
                // loop column
                if (k != i && chessboard[k][j] == 1)
                    return false;
            }

            // loop diagonal
            int x, y;
            x = i; y = j;
            while (++x < SIZE && ++y < SIZE) {
                if (chessboard[x][y] == 1)
                    return false;
            }
            x = i; y = j;
            while (++x < SIZE && --y > -1) {
                if (chessboard[x][y] == 1)
                    return false;
            }
            x = i; y = j;
            while (--x > -1 && ++y < SIZE) {
                if (chessboard[x][y] == 1)
                    return false;
            }
            x = i; y = j;
            while (--x > -1 && --y > -1) {
                if (chessboard[x][y] == 1)
                    return false;
            }

        }
    }

    return true;
}

void eightQueensPuzzle(int chessboard[SIZE][SIZE], int times, int & sum) {
    if (times >= SIZE) {
        cout << ++sum << endl;
        show(chessboard);
        return;
    }

    int i = times;
    for (int j = 0; j < SIZE; j++) {
        if (chessboard[i][j] == 1)
            continue;
        chessboard[i][j] = 1;
        if (isValid(chessboard))
            eightQueensPuzzle(chessboard, times + 1, sum);
        chessboard[i][j] = 0;
    }
}

int main() {
    int chessboard[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            chessboard[i][j] = 0;

    int sum = 0;
    eightQueensPuzzle(chessboard, 0, sum);
    getchar();
    return 0;
}