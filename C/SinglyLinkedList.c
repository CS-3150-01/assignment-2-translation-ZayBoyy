#include <stdio.h>
#include <stdlib.h>


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


SinglyLinkedList makeList() {
    SinglyLinkedList list;

    list.tail = malloc(sizeof(Node));
    list.tail->next = NULL;
    list.head = list.tail;

    return list;
}

SinglyLinkedList addNode(SinglyLinkedList list, int data) {
    
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    

    if (list.head == NULL) {

        list.head = newNode;
        list.tail = newNode;

        printf("If %d \n\n",newNode->data);
        
    }

    else {
        printf("Else %d", newNode->data);
        list.tail->next = newNode;
        list.tail = newNode;
    }

    return list;
}


void display(SinglyLinkedList list) {


    if (list.head == NULL) {
        printf("List is empty");
        return;
    }

    printf("Nodes of singly linked list: ");
    int i = 0;
    while(list.head !=  NULL) {
        //Prints each node by incrementing pointer
        i++;
        list.head = list.head->next;
    }
    printf("%d \n", i);


}


int main() {

    SinglyLinkedList sList = makeList();

    printf("%d \n", sList.head->data);
 
    sList = addNode(sList, 1);
    //display(sList);
    printf("%d \n", sList.head->data);

    sList = addNode(sList, 2);
    sList = addNode(sList, 3);
    sList = addNode(sList, 4);

    //display(sList);

    

    

    return 0;
}