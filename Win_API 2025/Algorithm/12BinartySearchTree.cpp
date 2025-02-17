#include <iostream>
#include<vector>
#include <stack>
#include <queue>
#include <map>
#include<unordered_map>
#include "12BinartySearchTree.h"
using namespace std;

//이진탐색트리 BST vs 해쉬테이블

//이진탐색트리를 쓰는이유(해쉬테이블 단점)
//1. 데이터를 많이쓴다 데이터 파편화가 되어있으면 해시테이블을 쓰기 힘들수있다.
//2. 해쉬함수의 성능이 떨어질경우 체이닝이 발생 -> 데이터베이스에서 엄청많은 데이터를 처리할때
//3. 체이닝 발생시 시간을 보장하지않는다

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
    //전위순회 : 부모 - 왼쪽 - 오른쪽
    cout << node->key << endl;
    PrintTree(node->leftChild);
    PrintTree(node->rightChild);
    //중위순회 : 왼쪽 - 부모 - 오른쪽 , map의 베이스
    PrintTree(node->leftChild);
    cout << node->key << endl;
    PrintTree(node->rightChild);
    //후위순회 : 왼쪽 - 오른쪽 - 부모
    PrintTree(node->leftChild);
    PrintTree(node->rightChild);
    cout << node->key << endl;
}
Node* BinarySearchTree::Search(Node* node, int key)//key값을 가지는 노드 반환
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
Node* BinarySearchTree::Min(Node* node) //node부터 시작하는 트리에서 가장 작은 값을 가지는 노드 반환
{
    Node* hereNode = node;
    Node* left = hereNode->leftChild;
    if (left == nullptr) {
        return hereNode;
    }
    return Min(left);
    
}
Node* BinarySearchTree::Max(Node* node) // node부터 시작하는 트리에서 가장 큰 값을 가지는 노드 반환
{
    Node* hereNode = node;
    Node* right = hereNode->rightChild;
    if (right == nullptr) {
        return hereNode;
    }
    return Max(right);
    
}
Node* BinarySearchTree::Previous(Node* node) // 매개변수 node보다 한칸 더 작은 노드
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
Node* BinarySearchTree::Next(Node* node) // 매개변수 node보다 한칸 더 큰 노드
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
        // 왼쪽, 오른쪽 자식이 다 있는 경우
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