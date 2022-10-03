#include <stdio.h>

//Represent a node of a binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}typedef Node;

//This starts the root of the binary tree
struct BinarySearchTree {
    Node root;
}typedef BinarySearchTree;

//This should create a new node with the data inputted
Node construct(int input) {
Node attempt;
attempt.data = input;
return attempt;
}

//This should calculate the factorial of the input number
int factorial(int num) {
    int fact = 1;
    if (num == 0) {
        return 1;
    }
    else {
        while(num > 1) {
            fact = fact * num;
            num--; 
        }
        return fact;
    }
}

//This caclulates the number of possible BST's by determining the catalan number for key
int numOfBST(int key) {    
    int catalanNumber = factorial(2 * key)/(factorial(key + 1) * factorial(key));    
    return catalanNumber;    
}    



//This is the main 
int main () {
    //Display total number of possible binary search trees with key 5
    printf("Total number of possible Binary Search Trees with given key: %i \n", numOfBST(5));
    return 0;
}