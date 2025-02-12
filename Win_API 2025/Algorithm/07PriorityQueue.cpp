#include <iostream>
#include<vector>
#include <stack>
#include <queue>
using namespace std;
/*
���� ���� Ʈ��
�ð����⵵ 
���� ���� :lonN
������ : N���� ���Ҹ� ���� ���� -> ���� , N logN
*/
template <typename T, typename Container = vector<T>, typename Pred = less<int>>

class PriorityQueue {

public:
    void push(T data) {
        v.push_back(data);
        int hereIndex = v.size() - 1;
        int parentIndex = (hereIndex - 1) / 2;


        while (true) {
            if (hereIndex <= 0) {
                break;
            }
            if (v[parentIndex] > v[hereIndex]) {
                break;
            }
            else {
                std::swap(v[parentIndex], v[hereIndex]);
                hereIndex = parentIndex;
                parentIndex = (hereIndex - 1) / 2;

            }
        }
    }
    void pop() {//�ڽĳ��(�������� ������ ���� ����üũ ���ʵ� ������ break;
        std::swap(v[0], v[v.size() - 1]);
        v.pop_back();
        int hereIndex = 0;
        int childIndexL = 2 * hereIndex + 1;
        int childIndexR = 2 * hereIndex + 2;

        while (true) {
            
            if (childIndexL >= v.size()) { //�ڽľ���
                break;
            }
            if (childIndexR >= v.size()) { //�������� �ڽ�����
                if (v[childIndexL] > v[hereIndex]) {
                    std::swap(v[childIndexL], v[hereIndex]);
                    hereIndex = childIndexL;
                    childIndexL = 2 * hereIndex + 1;
                    childIndexR = 2 * hereIndex + 2;
                    continue;
                }
                else {
                    break;
                }
            }
            
            int maxNum = std::max(v[childIndexL], v[childIndexR]);
            if (v[childIndexL] == maxNum) {
                if (v[hereIndex] < v[childIndexL]) {
                    std::swap(v[hereIndex], v[childIndexL]);
                    hereIndex = childIndexL;
                    childIndexL = 2 * hereIndex + 1;
                    childIndexR = 2 * hereIndex + 2;
                }
                else {
                    break;
                }

            }
            else {
                if (v[hereIndex] < v[childIndexR]) {
                    std::swap(v[hereIndex], v[childIndexR]);
                    hereIndex = childIndexR;
                    childIndexL = 2 * hereIndex + 1;
                    childIndexR = 2 * hereIndex + 2;
                }
                else {
                    break;
                }
            }
            //100 75 80 50 70
            //70 75 80 50 
            //80 75 70 50
            //50 75 70 
            //75 50 70
        }
    }

    bool empty() {
        return v.empty();
    }
    T top() {
        return v.front();
    }

private:
    Container v;
    Pred pred;
};


template<typename T>
struct Less
{
    bool operator()(T a, T b)
    {
        return a < b;
    }
};
int main()
{
    //priority_queue<int> pq;
    PriorityQueue<int, vector<int>, Less<int>> pq;
    pq.push(70);
    pq.push(80);
    pq.push(100);
    pq.push(50);
    pq.push(75);

    while (true) {
        if (pq.empty()) {
            break;
        }
        int top = pq.top();
        cout << pq.top() << endl;
        pq.pop();
    }

    return 0;
}