#include <iostream>
#include<vector>
#include <stack>
#include <queue>
using namespace std;

int Partition(vector<int>& v, int left, int right) { //lowIndex ->나보다 큰거 보면 멈춤 hightIndex->나보다 작은거 보면 멈춤

    int pivot = v[left];
    int lowIndex = left + 1;
    int hightIndex = right;

    while (true) {
        if (lowIndex > hightIndex) {
            break;
        }
        if (lowIndex <= right && pivot > v[lowIndex]) {
            lowIndex++;
        }
        if (hightIndex >= left && pivot < v[hightIndex]) {
            hightIndex--;
        }
        if (lowIndex < hightIndex) {
            std::swap(v[lowIndex], v[hightIndex]);
        }
    }
    std::swap(v[hightIndex], v[left]);
    return hightIndex;
}

void QuickSort(vector<int>& v, int left, int right) {
    if (left > right) {
        return;
    }
    int pivotIndex = Partition(v, left, right);
    cout << left << "~ " << pivotIndex - 1 << endl;

    QuickSort(v, left, pivotIndex - 1);
    QuickSort(v, pivotIndex + 1, right);
}
void MergeResult(vector<int>& v, int left, int mid, int right) {
    //잘게 쪼개진 상태에서 시작
    //임시배열 만들어서 좌우비교 한후 combine
    int leftIndex = left;
    int rightIndex = mid + 1;

    vector<int> temp;

    while (true) {

        if (leftIndex > mid || rightIndex > right) {
            break;
        }
        if (v[leftIndex] <= v[rightIndex]) {
            temp.push_back(v[leftIndex]);
            leftIndex++;
        }
        else {
            temp.push_back(v[rightIndex]);
            rightIndex++;
        }
    }
    if (leftIndex > mid) {
        while (rightIndex <= right) {
            temp.push_back(v[rightIndex]);
            rightIndex++;
        }
    }
    else {

        while (leftIndex <= mid) {
            temp.push_back(v[leftIndex]);
            leftIndex++;
        }
    }

    for (int i = 0; i < temp.size(); i++) {
        v[left + i] = temp[i];
    }
}
void MergeSort(vector<int>& v, int left, int right) {

    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;

    //divide 
    MergeSort(v, left, mid);
    MergeSort(v, mid + 1, right);
    //conquer and combine
    MergeResult(v, left, mid, right);
}
int main() {

    vector<int> v1 = { 55,30,15,100,1,5,70 };
    vector<int> v2 = { 55,30,15,100,1,5,30 };
   
    QuickSort(v1, 0, v1.size() - 1); //std::sort
    MergeSort(v2, 0, v2.size() - 1); //std::stable_sort

    return 0;
}