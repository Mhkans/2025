#pragma once

#include<iostream>
using namespace std;

struct Node {

	Node() = default;
	Node(int key) { this->key = key; }
	~Node() = default;

	int data = 0;
	int key = -1;
	Node* leftChild = nullptr;
	Node* rightChild = nullptr;
	Node* parent = nullptr;
};

class BinarySearchTree {

public:
	BinarySearchTree();
	~BinarySearchTree();

	void Insert(int key);
	void PrintTree(Node* node);

	Node* Search(Node* node, int key);
	Node* Min(Node* node);
	Node* Max(Node* node);
private:
	Node* Previous(Node* node);
	Node* Next(Node* node);

	void Replace(Node* node1, Node* node2);
	void Delete(Node* node);
public:
	Node* root = nullptr;

};