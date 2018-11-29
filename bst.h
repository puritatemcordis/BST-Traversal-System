#ifndef BST_H
#define BST_H

struct Node{
  int info;
  Node* right;
  Node* left;
};

class BST{
public:
  BST();
  ~BST();
  bool isEmpty(Node* node);
  void Destroy();
  void insert(int value);
  void remove(int value);
  void printPostOrder();
  void printInOrder();
  void printPreOrder();


private:
  Node* node;
  Node* addNode(Node* node, int value);
  Node* removeNode(Node* node, int value);
  Node* findMin(Node* node); //helper function to remove removeNode function
  void makeEmpty(Node* node);
  void postOrder(Node* node);
  void inOrder(Node* node);
  void preOrder(Node* node);
};

#endif
