#include <iostream>
#include<vector>
#include <stack>
using namespace std;
/*
1.부모와 자식 관계를 표현한다 (계층적 구조를 나타내는 자료구조)
2.트리는 잘라도 트리다 (재귀적 특성 , 서브트리가 존재한다)
*/
struct Node {
    string data;
    vector<Node*> children;
};

Node* CreateTree() {
    Node* root = new Node();
    root->data = "개발팀";
    
    Node* programming = new Node();
    programming->data = "프로그래밍팀";
    root->children.push_back(programming);
    {
        Node* node1 = new Node();
        node1->data = "클라이언트";
        programming->children.push_back(node1);
        
        Node* node2 = new Node();
        node1->data = "서버";
        programming->children.push_back(node2);

        Node* node3 = new Node();
        node1->data = "엔진";
        programming->children.push_back(node3);
    }

    Node* planning = new Node();
    planning->data = "기획팀";
    root->children.push_back(planning);
    {
        Node* node1 = new Node();
        node1->data = "스토리";
        planning->children.push_back(node1);

        Node* node2 = new Node();
        node1->data = "컨텐츠";
        planning->children.push_back(node2);

        Node* node3 = new Node();
        node1->data = "레벨디자인";
        planning->children.push_back(node3);
    }

    Node* art = new Node();
    art->data = "아트팀";
    root->children.push_back(art);
    {
        Node* node1 = new Node();
        node1->data = "원화";
        art->children.push_back(node1);

        Node* node2 = new Node();
        node1->data = "배경";
        art->children.push_back(node2);

        Node* node3 = new Node();
        node1->data = "모델링";
        art->children.push_back(node3);
    }
    return root;
}

void PrintTree(Node* node, int depth = 0) {
    for (int i = 0; i < depth; i++) {
        cout << " - ";
    }

    cout << node->data << endl;
    for (auto child : node->children) {
        PrintTree(child, depth + 1);
    }
}

int main()
{
    Node* root = CreateTree();

    PrintTree(root);

    return 0;
}