#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Compare {
    bool operator()(int a, int b) {
        return a < b;
    }
};

int main() {

    priority_queue<int, vector<int>, Compare> pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(1);

    cout << "Priority Queue elements: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}
