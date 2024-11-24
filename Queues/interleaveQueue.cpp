#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void interleaveQueue(queue<int>& q) {
    if (q.size() % 2 != 0) {
        cout << "Queue size must be even to interleave!" << endl;
        return;
    }

    //Queue: 4 7 11 20 5 9

    int halfSize = q.size() / 2;
    stack<int> s;

    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    } // Stack: 4 7 11  Queue: 20 5 9

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }// Queue: 20 5 9 4 7 11

    for (int i = 0; i < halfSize; i++) {
        q.push(q.front());
        q.pop();
    }// Queue: 4 7 11 20 5 9

    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    } // Stack: 4 7 11  Queue: 20 5 9

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }// Queue: 4 20 7 5 11 9
}

void displayQueue(queue<int>& q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;

    cout << "Enter the elements of the queue (space-separated, end with -1): ";
    int val;
    while (cin >> val && val != -1) {
        q.push(val);
    }

    cout << "Original Queue: ";
    displayQueue(q);

    q = queue<int>({4, 7, 11, 20, 5, 9});

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    displayQueue(q);

    return 0;
}
