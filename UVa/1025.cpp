/*
 * Dynamic programming
 * A Spy in the Metro, ACM/ICPC World Finals 2003, UVa1025
 *
 * Sample Input
 * 4 55 5 10 15 4 0 5 10 20 4 0 5 10 15 4 18 1 2 3 5 0 3 6 10 12 6 0 3 5 7 12 15 2 30 20 1 20 7 1 3 5 7 11 13 17 0
 *
 * Sample Output
 * Case Number 1: 5
 * Case Number 2: 0
 * Case Number 3: impossible
 */

#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
const int INF = 0xFFFF;

int n; // number of stations. (2 <= n <= 50)
int T; // time T to meet a Spy in the station n. (0 <= T <= 200)
int t[100]; // travel time, t[i] mean time from station i to station i+1. (1 <= ti <= 70)
int M[2];
int d[2][100]; // departure time, (0 <= di <= 250)
int has_train[200][100][2]; // [time][station][direction]
int dp[200][200];
int ncase = 0;

int foo(int time = 0, int station = 1) {
    if (time > T || station > n) {
        return INF;
    }
    if (time == T) {
        if (station != n)
            return INF;
        return 0;
    }
    if (dp[time][station] == -1) {
        int data[3] = {INF, INF, INF};

        // wait one minute
        data[0] = foo(time+1, station) + 1;
        // to right
        if (has_train[time][station][0]) {
            data[1] = foo(time+t[station], station+1);
        }
        // to left
        if (has_train[time][station][1]) {
            data[2] = foo(time+t[station-1], station-1);
        }
        // sort to get min value
        sort(data, data+3);
        dp[time][station] = data[0];
    }
    return dp[time][station];
}

int main() {
    rdIn("data.txt");

    while (cin >> n >> T) {
        memset(t, 0, sizeof(t));
        memset(d, 0, sizeof(d));
        memset(has_train, 0, sizeof(has_train));
        memset(dp, -1, sizeof(dp));

        // receive input
        for (int i = 1; i < n; i++) {
            cin >> t[i];
        }
        for (int i = 0; i < 2; i++) {
            cin >> M[i];
            for (int j = 1; j <= M[i]; j++) {
                cin >> d[i][j];
            }
        }
        //////////////////////////////////////

        // handle has_train
        // L2R
        for (int i = 1; i <= M[0]; i++) {
            int time = d[0][i];
            for (int j = 1; j < n; j++) {
                time += t[j-1];
                has_train[time][j][0] = 1;
            }
        }
        // R2L
        for (int i = 1; i <= M[1]; i++) {
            int time = d[1][i];
            for (int j = n; j >= 1; j--) {
                time += t[j];
                has_train[time][j][1] = 1;
            }
        }
        /////////////////////////////////////////
        cout << "Case Number " << ++ncase << ": ";
        int wait = foo();
        if (wait < INF) {
            cout << wait << endl;
        } else {
            cout << "impossible" << endl;
        }
    }
    return 0;
}
