#include <iostream>
#include<vector>
#include <stack>
using namespace std;
/*
1.�θ�� �ڽ� ���踦 ǥ���Ѵ� (������ ������ ��Ÿ���� �ڷᱸ��)
2.Ʈ���� �߶� Ʈ���� (����� Ư�� , ����Ʈ���� �����Ѵ�)
*/
struct Node {
    string data;
    vector<Node*> children;
};

Node* CreateTree() {
    Node* root = new Node();
    root->data = "������";
    
    Node* programming = new Node();
    programming->data = "���α׷�����";
    root->children.push_back(programming);
    {
        Node* node1 = new Node();
        node1->data = "Ŭ���̾�Ʈ";
        programming->children.push_back(node1);
        
        Node* node2 = new Node();
        node1->data = "����";
        programming->children.push_back(node2);

        Node* node3 = new Node();
        node1->data = "����";
        programming->children.push_back(node3);
    }

    Node* planning = new Node();
    planning->data = "��ȹ��";
    root->children.push_back(planning);
    {
        Node* node1 = new Node();
        node1->data = "���丮";
        planning->children.push_back(node1);

        Node* node2 = new Node();
        node1->data = "������";
        planning->children.push_back(node2);

        Node* node3 = new Node();
        node1->data = "����������";
        planning->children.push_back(node3);
    }

    Node* art = new Node();
    art->data = "��Ʈ��";
    root->children.push_back(art);
    {
        Node* node1 = new Node();
        node1->data = "��ȭ";
        art->children.push_back(node1);

        Node* node2 = new Node();
        node1->data = "���";
        art->children.push_back(node2);

        Node* node3 = new Node();
        node1->data = "�𵨸�";
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