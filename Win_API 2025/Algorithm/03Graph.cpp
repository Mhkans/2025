#include <iostream>
#include<vector>

using namespace std;

//�׷���
//vertex �� edge�� �̷���� �ڷᱸ��
//�׷��� ��ȸ ��� -> dfs bfs


//��������Ʈ
vector<vector<int>> adjacent_LIST; //�ð����⵵�� ���Ƶ� ������ ���� �Դ´�

void CreateGraph_LIST() {

    adjacent_LIST.resize(7);
    adjacent_LIST[0] = { 0,1,2,3 };
    adjacent_LIST[1] = { 0,1,4 };
    adjacent_LIST[2] = { 0,2,5 ,6 };
    adjacent_LIST[3] = { 0,3 };
    adjacent_LIST[4] = { 1,4 };
    adjacent_LIST[5] = { 2,5 };
    adjacent_LIST[6] = { 2,6 };
}

vector<vector<bool>> adjacent; //������ ���� �Դ��� ����� �ð��� �ɸ���

void CreateGraph() {

    adjacent = vector<vector<bool>>(7, vector<bool>(7, false)); //7 X 7 ���
    // ������� �׷��� A�� A�� ��ġ���(A)�� ���� ����.

    //   0  1  2  3  4  5  6
    // 0 1  1  1  1  0  0  0
    // 1 1  1  0  0  1  0  0
    // 2 1  0  1  0  0  1  1
    // 3 1  0  0  1  0  0  0
    // 4 0  1  0  0  1  0  0
    // 5 0  0  1  0  0  1  0
    // 6 0  0  1  0  0  0  1

    adjacent[0][0] = true;
    adjacent[0][1] = true;
    adjacent[0][2] = true;
    adjacent[0][3] = true;

    adjacent[1][0] = true;
    adjacent[1][1] = true;
    adjacent[1][4] = true;

    adjacent[2][0] = true;
    adjacent[2][2] = true;
    adjacent[2][5] = true;
    adjacent[2][6] = true;

    adjacent[3][0] = true;
    adjacent[3][3] = true;

    adjacent[4][1] = true;
    adjacent[4][4] = true;

    adjacent[5][2] = true;
    adjacent[5][5] = true;

    adjacent[6][2] = true;
    adjacent[6][6] = true;
    

}
int main()
{
    CreateGraph_LIST();
    auto Iter = std::find(adjacent_LIST[0].begin(), adjacent_LIST[0].end(), 2);
    if (Iter != adjacent_LIST[0].end()) {
        cout << "true" << endl;
    }
  
    CreateGraph();
    if (adjacent[0][2]) {
        cout << "true" << endl;
    }
    return 0;
}