#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

int pen_width, height, width;

void print_pen(int pw) {
    for (int i = 0; i < pw; i++) {
        cout << "*";
    }
}

void print_dot(int n) {
    for (int i = 0; i < n; i++) {
        cout << ".";
    }
}

int main() {
    rdIn("data.txt");

    while (~scanf("%d %d", &pen_width, &height)) {
        width = height + pen_width - 1;
        bool half = false;
        int sd_dot_width = -1;
        for (int i = 0; i < height; i++) {
            if (half) {
                sd_dot_width--;
            } else {
                sd_dot_width++;
            }
            int mid_pot_width = width - 2*pen_width - 2*sd_dot_width;
            print_dot(sd_dot_width);
            if (mid_pot_width > 0) {
                print_pen(pen_width);
                print_dot(mid_pot_width);
                print_pen(pen_width);
            } else {
                int mid_width = width - 2*sd_dot_width;
                print_pen(mid_width);
                if (mid_width == pen_width) {
                    half = true;
                }
            }
            print_dot(sd_dot_width);
            cout << endl;
        }
        cout << endl;
    }
  
  
    return 0;
}