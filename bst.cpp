#include <iostream>
#include <cstdlib>
#include "bst.h"

BST::BST(){
  node = NULL;
  std::cout << "Node created..." << std::endl;
}

BST::~BST(){
  std::cout << "Deleting Nodes..." << std::endl;
  makeEmpty(node);
}

bool BST::isEmpty(Node* node){return (node == NULL);}

void BST::Destroy(){
  makeEmpty(node);
  node = NULL;
}

void BST::makeEmpty(Node* node){
  if(isEmpty(node)) ;
  else {
    makeEmpty(node->left);
    makeEmpty(node->right);
    delete node;
    if(node->left != NULL) node->left = NULL;
    if(node->right != NULL) node->right = NULL;
    node = NULL;
  }
}

void BST::insert(int value){node = addNode(node, value);}

void BST::remove(int value){
  if (isEmpty(node)) std::cout << "BST is empty!" << std::endl;
  else node = removeNode(node, value);
}

void BST::printPostOrder(){
  if (isEmpty(node)) std::cout << "BST is empty!" << std::endl;
  else{
    std::cout << "Printing BST in Post Order(Left,Right,Root):" << std::endl;
    postOrder(node);
    std::cout << std::endl;
  }
}
void BST::printInOrder(){
  if (isEmpty(node)) std::cout << "BST is empty!" << std::endl;
  else {
    std::cout << "Printing BST in In Order(Left,Root,Right):" << std::endl;
    inOrder(node);
    std::cout << std::endl;
  }
}

void BST::printPreOrder(){
  if (isEmpty(node)) std::cout << "BST is empty!" << std::endl;
  else{
    std::cout << "Printing BST in Pre Order(Root,Left,Right):" << std::endl;
    preOrder(node);
    std::cout << std::endl;
  }
}

Node* BST::addNode(Node* node, int value){
  if (node == NULL){
    node = new Node();
    node->info = value;
    node->left = node->right = NULL;
  } else if (node->info > value){
    node->left = addNode(node->left, value);
  } else if (node->info < value){
    node->right = addNode(node->right, value);
  }

  return node;
}

Node* BST::removeNode(Node* node, int value){
  Node* tempPtr;

  if (isEmpty(node)){
    return NULL;
  } else if (node->info > value) {
    node->left = removeNode(node->left, value);
  } else if (node->info < value) {
    node->right = removeNode(node->right, value);
  } else if (node->left && node->right){
    tempPtr = findMin(node->right);
    node->info = tempPtr->info;
    node->right = removeNode(node->right,node->info);
  } else {
    tempPtr = node;
    if (node->left == NULL) node = node->right;
    else if (node->right == NULL) node = node->left;
    delete tempPtr;
  }

  return node;
}

Node* BST::findMin(Node* node){
  if (isEmpty(node)){
    std::cout << "Binary Search Tree is Empty" << std::endl;
    return NULL;
  }
  else if (node->left == NULL) return node;
  else return findMin(node->left);
}

void BST::postOrder(Node* node){
  if (isEmpty(node)) ;
  else {
    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->info << " ";
  }
}

void BST::inOrder(Node* node){
  if (isEmpty(node)) ;
  else {
    inOrder(node->left);
    std::cout << node->info << " ";
    inOrder(node->right);
  }
}

void BST::preOrder(Node* node){
  if (isEmpty(node)) ;
  else {
    std::cout << node->info << " ";
    preOrder(node->left);
    preOrder(node->right);
  }
}
