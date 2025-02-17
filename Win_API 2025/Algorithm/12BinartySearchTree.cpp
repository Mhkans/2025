#include <iostream>
#include<vector>
#include <stack>
#include <queue>
#include <map>
#include<unordered_map>
#include "12BinartySearchTree.h"
using namespace std;

//����Ž��Ʈ�� BST vs �ؽ����̺�

//����Ž��Ʈ���� ��������(�ؽ����̺� ����)
//1. �����͸� ���̾��� ������ ����ȭ�� �Ǿ������� �ؽ����̺��� ���� ������ִ�.
//2. �ؽ��Լ��� ������ ��������� ü�̴��� �߻� -> �����ͺ��̽����� ��û���� �����͸� ó���Ҷ�
//3. ü�̴� �߻��� �ð��� ���������ʴ´�

BinarySearchTree::BinarySearchTree()
{
 
}

BinarySearchTree::~BinarySearchTree()
{

}

void BinarySearchTree::Insert(int key)
{
    Node* newNode = new Node(key);

    if (root == nullptr) {
        root = newNode;
        return;
    }
    Node* node = root;
    Node* parent = nullptr;

    while (true) {
        if (node == nullptr) {
            break;
        }
        parent = node;
        if (key < node->key) {
            node = node->leftChild;
        }
        else {
            node = node->rightChild;
        }

    }
    newNode->parent = parent;
    if (key < parent->key) {
        parent->leftChild = newNode;

    }
    else {
        parent->rightChild = newNode;

    }
}

void BinarySearchTree::PrintTree(Node* node)
{
    if (node == nullptr) {
        return;
    }
    //������ȸ : �θ� - ���� - ������
    cout << node->key << endl;
    PrintTree(node->leftChild);
    PrintTree(node->rightChild);
    //������ȸ : ���� - �θ� - ������ , map�� ���̽�
    PrintTree(node->leftChild);
    cout << node->key << endl;
    PrintTree(node->rightChild);
    //������ȸ : ���� - ������ - �θ�
    PrintTree(node->leftChild);
    PrintTree(node->rightChild);
    cout << node->key << endl;
}
Node* BinarySearchTree::Search(Node* node, int key)//key���� ������ ��� ��ȯ
{
    if (node == nullptr) {
        return nullptr;
    }
    if (node->key == key) {
        return node;
    }
    if (key > node->key) {
        return Search(node->rightChild, key);
    }
    else {
        return Search(node->leftChild, key);
    }
    
}
Node* BinarySearchTree::Min(Node* node) //node���� �����ϴ� Ʈ������ ���� ���� ���� ������ ��� ��ȯ
{
    Node* hereNode = node;
    Node* left = hereNode->leftChild;
    if (left == nullptr) {
        return hereNode;
    }
    return Min(left);
    
}
Node* BinarySearchTree::Max(Node* node) // node���� �����ϴ� Ʈ������ ���� ū ���� ������ ��� ��ȯ
{
    Node* hereNode = node;
    Node* right = hereNode->rightChild;
    if (right == nullptr) {
        return hereNode;
    }
    return Max(right);
    
}
Node* BinarySearchTree::Previous(Node* node) // �Ű����� node���� ��ĭ �� ���� ���
{
    if (node->leftChild == nullptr) {
        Node* parent = node->parent;
        while (true) {

            if (parent == nullptr) {
                return parent;
            }
            if (parent->rightChild == node) {
                return parent;
            }
            node = parent;
            parent = parent->parent;

        }
    }
    else {
        return Max(node->leftChild);
    }
}
Node* BinarySearchTree::Next(Node* node) // �Ű����� node���� ��ĭ �� ū ���
{
    if (node->rightChild == nullptr) {


        Node* parent = node->parent;

        while (true) {
            if (parent == nullptr) {
                return parent; 
            }

            if (parent->leftChild == node) {
                return parent; 
            }

            node = parent;
            parent = parent->parent;
        }
    }
    else {
        return Min(node->rightChild);
    }
    
}

void BinarySearchTree::Replace(Node* node1, Node* node2)
{
    if (node1->parent == nullptr)
        root = node2;

    else if (node1 == node1->parent->leftChild)
    {
        node1->parent->leftChild = node2;
    }
    else
    {
        node1->parent->rightChild = node2;
    }

    if (node2 != nullptr)
        node2->parent = node1->parent;

    delete node1;
}

void BinarySearchTree::Delete(Node* node)
{
    if (node == nullptr)
        return;

    if (node->leftChild == nullptr)
    {
        Replace(node, node->rightChild);
    }
    else if (node->rightChild == nullptr)
    {
        Replace(node, node->leftChild);
    }
    else
    {
        // ����, ������ �ڽ��� �� �ִ� ���
        Node* prev = Previous(node);
        node->data = prev->data;
        node->key = prev->key;

        Delete(prev);
    }
}
int main() {

    BinarySearchTree tree;
    tree.Insert(100);
    tree.Insert(50);
    tree.Insert(25);
    tree.Insert(75);
    tree.Insert(150);
    tree.Insert(110);
    tree.Insert(200);
    tree.Insert(99);
    tree.Insert(125);
    //tree.PrintTree(tree.root);
    //cout << tree.Next(tree.root->leftChild->rightChild->rightChild)->key << endl;

    map<string, int> m;
    m["abc"] = 1;
    m.insert(make_pair<string, int>("abcd", 2));

    for (auto p : m) {
        cout << p.first << "   " << p.second << endl;
    }

    return 0;
}