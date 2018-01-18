/**
 *
 * 碱基
 *
 * 生物学家正在对n个物种进行研究。
 * 其中第i个物种的DNA序列为s[i]，其中的第j个碱基为s[i][j],碱基一定是A、T、G、C之一。
 * 生物学家想找到这些生物中一部分生物的一些共性，他们现在关注那些至少在m个生物中出现的长度为k的连续碱基序列。准确的说，科学家关心的序列用2m元组(i1,p1,i2,p2....im,pm)表示，
 * 满足:
 * 1<=i1<i2<....<im<=n;
 * 且对于所有q(0<=q<k), s[i1][p1+q]=s[i2][p2+q]=....=s[im][pm+q]。
 *
 * 现在给定所有生物的DNA序列，请告诉科学家有多少的2m元组是需要关注的。如果两个2m元组有任何一个位置不同，则认为是不同的元组。
 *
 * 【输入格式】
 * 输入的第一行包含三个整数n、m、k，两个整数之间用一个空格分隔，意义如题目所述。
 * 接下来n行，每行一个字符串表示一种生物的DNA序列。
 * DNA序列从1至n编号，每个序列中的碱基从1开始依次编号，不同的生物的DNA序列长度可能不同。
 *
 * 【输出格式】
 * 输出一个整数，表示关注的元组个数。
 * 答案可能很大，你需要输出答案除以1000000007的余数。
 *
 * 【样例输入】
 * 3 2 2
 * ATC
 * TCG
 * ACG
 *
 * 【样例输出】
 * 2
 *
 * 再例如：
 * 【样例输入】
 * 4 3 3
 * AAA
 * AAAA
 * AAA
 * AAA
 *
 * 【样例输出】
 * 7
 *
 *
 * 【数据规模与约定】
 * 对于20%的数据，k<=5,所有字符串总长L满足L <=100
 * 对于30%的数据，L<=10000
 * 对于60%的数据，L<=30000
 * 对于100%的数据，n<=5,m<=5,1<=k<=L<=100000
 * 保证所有DNA序列不为空且只会包含’A’ ’G’ ’C’ ’T’四种字母
 *
 * 资源约定：
 * 峰值内存消耗 < 256M
 * CPU消耗  < 1000ms
 *
 * 请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。
 *
 * 所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
 *
 * 注意: main函数需要返回0
 * 注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
 * 注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。
 *
 * 提交时，注意选择所期望的编译器类型。
 *
 */

#include <iostream>
#include <vector>
#include <map>
#include <ctime>

using namespace std;

#define NUM 1000000007

int n, m, k;
string s[5];
map<string, vector<int>> maps;


void foo() {
    // classification and count
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= s[i].size()-k; j++) {
            string str = s[i].substr(j, k);
            auto it = maps.find(str);
            if (it == maps.end()) {
                vector<int> v(n);
                for (int& k : v)
                    k = 0;
                v[i] = 1;
                pair<string, vector<int>> pa(str, v);
                maps.insert(pa);
            } else {
                maps[str][i]++;
            }
        }
    }

    // delete elements less than
    for (auto it = maps.begin(); it != maps.end();) {
        int times = 0;
        vector<int>& v = (*it).second;
        for (int i : v)
            times += (i > 0);
        if (times < m) {
            maps.erase(it++);
        } else {
            it++;
        }
    }
}

void calc(const vector<int>& v, int arr[], const int pos, long long& sum) {
    if (pos == m) {
        long long j = 1;
        for (int i = 0; i < m; i++) {
            j *= v[arr[i]];
            j %= NUM;
        }
        sum += j;
        sum %= NUM;
        return;
    }

    int i;
    if (pos == 0) {
        i = 0;
    } else {
        i = arr[pos-1] + 1;
    }
    for (; i < n; i++) {
        arr[pos] = i;
        calc(v, arr, pos+1, sum);
    }
}


int main() {
    /**
     * 4 3 3
     * AAA
     * AAAA
     * AAA
     * AAA
     *
     * same point
     * 0(1, 0)
     * 1(2, 0) 2(2, 1)
     * 3(3, 1)
     * 4(4, 1)
     *
     * combination
     * 0 1 3
     * 0 1 4
     * 0 2 3
     * 0 2 4
     * 0 3 4
     * 1 3 4
     * 2 3 4
     */
    // n<=5,m<=5,1<=k<=L<=100000
    n = 5; m = 5; k = 4;
    char items[] = {'A', 'T', 'C', 'G'};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 1e5; j++) {
            s[i] += items[rand() % 4];
        }
    }

    auto begin = clock();

    foo();

    long long sum = 0;
    for (auto it = maps.begin(); it != maps.end(); it++) {
        string str = (*it).first;
        auto v = (*it).second;
        int arr[m];
        long long j = 0;
        calc(v, arr, 0, j);
        sum += j;
        sum %= NUM;

        // show time
        cout << str << "\t";
        for (int i = 0; i < v.size(); i++)
            printf("[%d] %d; ", i, v[i]);
        cout << "\t" << j;
        cout << endl;
    }
    cout << sum << endl;
    cout << static_cast<double>(clock() - begin) / CLOCKS_PER_SEC << endl;
    return 0;
}

// 9520797530553583560
// 1844674407370955161