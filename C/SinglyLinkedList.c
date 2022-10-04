#include <stdio.h>
#include <stdlib.h>


//Made to represent node of a singly linked list
struct Node{
    int data;
    struct Node* next;
}typedef Node;


//Represents begining and end of the linked list
    Node* head;
    Node* tail;
    

//addNode() should add a new node to the list
void addNode(int data) {
    
    //makes a new node
    Node* newNode = malloc(sizeof(Node));
    
    newNode->data = data;
    newNode->next = NULL;
    

    //checks if the list is empty
    if (head == NULL) {

        //head and tail point to new node if its empty
        head = newNode;

    }

    else {
        //new node gets pointed to by tail.next
        tail->next = newNode;
        //new node becomes new tail
    }
    
    tail =  newNode;

}

//display() should show all the nodes present in the list
void display() {

    //current is pointer to head
    Node* current = head;
  

    if (current == NULL) {
        printf("List is empty");
        return;
    }

    printf("Nodes of singly linked list:\n");
    
    while(current !=  NULL) {

        printf("%d \n",current->data);
        //Prints the value of each node by incrementing pointer
    current = current->next;
    }



}


int main() {

    
    
    //Adds nodes to the list
    addNode(1);
    addNode(2);
    addNode(3);
    addNode(4);

    //Displays the nodes present in the list
    display();

    return 0;
}