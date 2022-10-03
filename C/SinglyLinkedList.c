#include <stdio.h>


//Made to represent node of a singly linked list
struct Node{
    int data;
    struct Node* next;
}typedef Node;


//Represents begining and end of the linked list
struct SinglyLinkedList {
    Node* head;
    
    Node* tail;
    
}typedef SinglyLinkedList;


SinglyLinkedList addNode(SinglyLinkedList list, int data) {
   
    Node newNode;

    newNode.data = data;

    if (list.head == NULL) {
        list.head = &newNode;
        list.tail = &newNode;
        printf("If %d",newNode.data);
        
    }

    else {printf("Else %d",newNode.data);
        list.tail->next = &newNode;
        list.tail = &newNode;
    }
}


void display(SinglyLinkedList list) {

    Node current = *list.head;

    if (list.head == NULL) {
        printf("List is empty");
        return;
    }

    printf("Nodes of singly linked list: ");
    while(&current !=  NULL) {
        //Prints each node by incrementing pointer
        printf("%d ", current.data);
        current = *current.next;
    }
    printf("\n");


}


int main() {

    SinglyLinkedList sList;

    printf("%p \n", &sList.head);
 
    addNode(sList, 1);
    printf("&d \n", sList.head->data);
   
    addNode(sList, 2);
    addNode(sList, 3);
    addNode(sList, 4);

    

    display(sList);

    return 0;
}