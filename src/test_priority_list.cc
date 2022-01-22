
#include "priority_list.h"
#include <queue>
#include <cassert>
#include <cstdio>

PriorityList<int> pl;
std::priority_queue<int> pq;

void checkFail() {
    printf("pl.top = %d, pq.top = %d\n", pl.top(), pq.top());
    exit(0);
}

void checkTop() {
    assert(pl.size() == pq.size());
    if (pl.size() && pl.top() != pq.top()) {
        checkFail();
    }
}
void insert(int x) {
    pl.insert(x);
    pq.push(x);
    checkTop();
}

void pop() {
    assert(pl.size() == pq.size());
    if (pl.size()) {
        pl.pop();
        pq.pop();
    }
    checkTop();
}




int main() {

    FILE* fp = fopen("record.txt", "w");


    for (int i = 0; i < 1000; i++) {
        unsigned v = rand() % 100;
        fprintf(fp, "insert(%d);\n", v);
        if (v % 3 == 0 || v % 3 == 2) {
            fprintf(fp, "insert(%d);\n", v);
            insert(v);
            checkTop();
        }
        if (v % 3 == 1) {
            fprintf(fp, "pop();\n");
            pop();
            checkTop();
        }

    }
    return 0;
}