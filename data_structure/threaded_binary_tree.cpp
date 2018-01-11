#include <iostream>

struct node {
    char data;
    int leftFlag;
    int rightFlag;
    node * leftChild = nullptr;
    node * rightChild = nullptr;
};

void thread(node * n, node* & pre) {
    if (n == nullptr)
        return;
    // 0 mean child, 1 mean thread
    n->leftFlag = (n->leftChild == nullptr) ? 1 : 0;
    n->rightFlag = (n->rightChild == nullptr) ? 1 : 0;
    thread(n->leftChild, pre);
    // std::cout << n->data;
    if (n->leftFlag == 1) {
        n->leftChild = pre;
        std::string s = "nullptr";
        if (pre != nullptr)
            s = pre->data;
        std::cout << n->data << " left child <- " << s << std::endl;
    }
    if (pre != nullptr && pre->rightFlag == 1) {
        pre->rightChild = n;
        std::cout << pre->data << " right child <- " << n->data << std::endl;
    }
    pre = n;
    thread(n->rightChild, pre);
}

node * find(node * n) {
    if (n->leftFlag == 1)
        return n;
    find(n->leftChild);
}

void traverseThread(node * n) {
    node * p = find(n);
    if (p == nullptr) return;
    while (p->rightFlag == 1) {
        std::cout << p->data;
        p = p->rightChild;
        if (p == nullptr) return;
    }
    std::cout << p->data;
    p = p->rightChild;
    traverseThread(p);
}

int main() {
    /**
     * in order
     * ABCDEFGHI
     *      F
     *     / \
     *    B   G
     *   / \   \
     *  A  D    I
     *    / \  /
     *   C  E H
     */
    node a, b, c, d, e, f, g, h, i;
    a.data = 'A';
    b.data = 'B';
    c.data = 'C';
    d.data = 'D';
    e.data = 'E';
    f.data = 'F';
    g.data = 'G';
    h.data = 'H';
    i.data = 'I';

    f.leftChild = &b;
    f.rightChild = &g;
    b.leftChild = &a;
    b.rightChild = &d;
    d.leftChild = &c;
    d.rightChild = &e;
    g.rightChild = &i;
    i.leftChild = &h;

    node * np = nullptr;
    thread(&f, np);
    traverseThread(&f);
    return 0;
}