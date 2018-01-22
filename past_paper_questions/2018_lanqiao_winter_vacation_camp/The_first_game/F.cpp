#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }

int main() {
    rdIn("data.txt");

    int lines;
    while (cin >> lines) {
        for (int i = 0; i < lines; i++) {
            // 其中a为安全区外的扣血速度a%/s,b为角色和安全区的距离，c为急救包的数量。
            // 这扣血速度是按满血的算。。题目都没说，不懂的还以为是按当前血量算额，看下面的例子才懂。
            int a, b, c;
            cin >> a >> b >> c;
            int lose_value_per_sec = a, distance = b, kit_num = c;
            int value = 100;
            int min_value = lose_value_per_sec * 6 + 1;
            bool is_dead;
            while (true) {
                // every second
                value -= lose_value_per_sec; distance--;
                if (distance <= 0) {
                    is_dead = false;
                    break;
                }
                if (value <= 0) {
                    is_dead = true;
                    break;
                }
                // to check out whether need to use aid kit
                if (value - lose_value_per_sec > min_value) {
                    continue;
                }
                if (kit_num > 0) {
                    // use aid kit
                    kit_num--;
                    value = 80;
                }
            }
            cout << (is_dead ? "NO" : "YES") << endl;
        }
    }

  
    return 0;
}