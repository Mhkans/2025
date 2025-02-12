#include <iostream>
#include <list>
#include <queue>

using namespace std;

template<typename T , typename Container = list<T>>

class Queue {
public:
    void push(T data) {
        l.push_back(data);
    }
    bool empty() {

        return l.empty();
    }
    T front() {

        return l.front();
    }
    void pop() {

        l.pop_front();
    }
private:
    Container l;
};

int main()
{

    Queue<int> q;

    q.push(10);
    q.push(7);
    q.push(15);
    q.push(1);
    q.push(3);

    while (true) {
        if (q.empty()) {
            break;
        }
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}
