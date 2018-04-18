#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

/**
 * analysis
 *
 * do with cycle
 *
 * the speed of the second hand = 360 degrees / 60       seconds = 6    degrees/second
 * the spend of the minute hand = 360 degrees / 60*60    seconds = 1    degrees/second
 * the spend of the hour   hand = 360 degrees / 60*60*12 seconds = 1/12 degrees/second
 *
 * so we need calculate cycle of the angle between each two hands is greater than or equal to degrees D,
 * then take intersection
 *
 *
 *
 */

// velocity
const double v_second = 6;
const double v_minute = 1;
const double v_hour   = 1.0/12;

// relative velocity
const double rv_second_minute = v_second - v_minute;
const double rv_second_hour   = v_second - v_hour;
const double rv_minute_hour   = v_minute - v_hour;

// seconds of 12 hours
const int seconds_1_hours = 60 * 60;
const int seconds_12_hours = 12 * seconds_1_hours;

// cycle time
const double t_second_minute = 360 / rv_second_minute;
const double t_second_hour   = 360 / rv_second_hour;
const double t_minute_hour   = 360 / rv_minute_hour;


struct node {
    mutable double l, r;
    node () {}
    node (double l, double r) : l(l), r(r) {}
    bool operator<(const node &rhs) const {
        return this->l < rhs.l;
    }
};

set<node> data;

void intersecte(node n) {
    bool l = false, r = false;
    for (auto it = data.begin(); it != data.end(); it++) {
        if (!l and !r and n.l < it->l and n.r > it->l) {
            return;
        }
        if (!l and n.l > it->l and n.l < it->r) {
            it->l = n.l;
            l = true;
        }
        if (!r and n.r > it->l and n.r < it->r) {
            it->r = n.r;
            r = true;
        }
    }
    if (!l and !r) {
        data.insert(n);
    }
}

int main() {
    rdIn("data.txt");


    int d;
    while (~scanf("%d", &d) and ~d) {
        // calculate the second hand and the minute hand
        node n;

        n.l =      d  / rv_second_minute;
        n.r = (360-d) / rv_second_minute;
        for (int i = 0; i < seconds_12_hours / t_second_minute; i++) {
            double b = t_second_minute*i;
            intersecte(node(b+n.l, b+n.r));
        }

        n.l = d / rv_second_hour;
        n.r = (360-d) / rv_second_hour;
        for (int i = 0; i < seconds_12_hours / t_second_hour; i++) {
            double b = t_second_hour*i;
            intersecte(node(b+n.l, b+n.r));
        }

        n.l = d / rv_minute_hour;
        n.r = (360-d) / rv_minute_hour;
        for (int i = 0; i < seconds_12_hours / t_minute_hour; i++) {
            double b = t_minute_hour*i;
            intersecte(node(b+n.l, b+n.r));
        }


        double valid = 0;
        for (auto i : data) {
            valid += i.r - i.l;
            printf("%lf, %lf\n", i.l, i.r);
        }

        printf("%.2lf\n", 100 * valid / seconds_12_hours);

    }


    return 0;
}