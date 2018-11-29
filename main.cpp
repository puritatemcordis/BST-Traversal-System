#include <iostream>
#include <cstdlib>
#include <string>
#include "bst.h"

//FUNCTION PROTOTYPES
void ClearScreen();
char Greeting();
void DisplayMenu(int& choice);
void Exit(int& next);

int main(){
  ClearScreen();
  char answer = Greeting();

  while(answer == 'Y'){
    ClearScreen();
    int choice, value, next = 1;
    BST node;

    while(next){

      DisplayMenu(choice);
      switch(choice){
        case 1:
          while (true){
            printf("To exit, enter -999.\n");
            printf("Enter value to insert node: ");
            std::cin >> value;
            if(value == -999) break;
            node.insert(value);
          }
          break;
        case 2:
          node.printPostOrder();
          printf("Enter node to remove from BST: ");
          std::cin >> value;
          node.remove(value);
          break;
        case 3:
          printf("Destroying BST...\n");
          node.Destroy();
          break;
        case 4:
          node.printPostOrder();
          break;
        case 5:
          node.printInOrder();
          break;
        case 6:
          node.printPreOrder();
          break;
        case 7:
          Exit(next);
          break;
        default:
          printf("Error! None of the options selected.\n");
          Exit(next);
          break;
      }
      std::cout << std::endl;
    }

    printf("Do you want to restart the Binary Search Tree Traversal System? (Y/N): ");
    std::cin >> answer;
    answer = toupper(answer); //capitalizes the char inputted by user
  }
  std::cout << "Good bye!" << std::endl;

  return 0;
}

//FUNCTION DEFINITIONS

//Sends 100 newlines to the console, which is equivalent to UNIX command "clear"
//Used to show changes in matrix without stacking each display on top of one another
void ClearScreen(){
  for(int n = 0; n < 10; n++){
    std::cout << "\n\n\n\n\n\n\n\n\n\n";
  }
}

//Returns char to determine whether the user wants to play game
//Greets player and explains rules of the game
char Greeting(){
  //declaration and initialization of answer to ' '
  char answer = ' ';

  //explains the rules of Conway's Game of Life
  std::cout << "\t\t\t\t\t\t\t\t \"Welcome to the Binary Search Tree Traversal System\"" << std::endl;
  std::cout << std::endl;

  std::cout << "A binary search tree is an ordered data structure that stores different data types in memory. They" << std::endl;
  std::cout << "permit quick searches, insertions, and deletions due to the binary search algorithm. Therefore, the time" << std::endl;
  std::cout << "complexity is O(log N). In this program, the data type of the binary tree is integer, and the user is" << std::endl;
  std::cout << "permitted to either enter, delete, or traverse the tree in three different methods." << std::endl;
  std::cout << std::endl;

  std::cout << "The three different methods to traverse a binary tree is inorder, preorder, and postorder. Inorder" << std::endl;
  std::cout << "traversal means that the nodes of the binary tree will be declared from left-most node to the root node" << std::endl;
  std::cout << "to the right-most node. Preorder traversal means that the nodes of the binary tree will be declared from" << std::endl;
  std::cout << "root node to left-most node to right-most node. Postorder traversal means that the nodes of the binary" << std::endl;
  std::cout << "tree will be declared from left-most node to right-most node to root node." << std::endl;
  std::cout << std::endl;

  //while loop to ensure player either selects Y or N, which determines whether they play or not
  while (answer != 'Y' && answer != 'N'){
    std::cout << "Would you like to continue? (Y/N): ";
    std::cin >> answer;
    answer = toupper(answer); //capitalizes the char inputted by user
  }

  return answer;
}

//Displays the menu of different selections of queues
//@param choice: integer, which is pass-by-reference, which the user will input to advance the menu
void DisplayMenu(int& choice){
  printf("Please select one of the following of the menu:\n");
  printf("1) Add Node\n");
  printf("2) Remove Node\n");
  printf("3) Destroy Tree\n");
  printf("4) PostOrder Traversal\n");
  printf("5) InOrder Traversal\n");
  printf("6) PreOrder Traversal\n");
  printf("7) Exit\n");
  printf("Your choice: ");
  std::cin >> choice;
  std::cout << std::endl;
}

//Displays an exit message and assigns 0 to next, which will end the while loop
//@param next: integer, which is pass-by-reference, that will be assigned 0, which will break the while loop
void Exit(int& next){
  printf("\nExiting program...");
  next = 0;
}
