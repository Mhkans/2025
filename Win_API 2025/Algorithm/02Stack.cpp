#include <iostream>
#include <stack>
#include <queue>

using namespace std;

template<typename T>

class Stack {
public:
    void push(T data) {
        v.push_back(data);
    }
    bool empty() {

        return v.empty();
    }
    T top() {

        return v.back();
    }
    void pop() {

        v.pop_back();
    }
private:
    vector<T> v;
};

int main()
{

    Stack<int> s;

    s.push(10);
    s.push(1);
    s.push(15);
    s.push(6);
    s.push(100);

    while (true) {
        if (s.empty()) {
            break;
        }
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}
