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

//makeList() will initialize a SinglyLinkedList 
SinglyLinkedList makeList() {
    SinglyLinkedList list;

    list.tail = malloc(sizeof(Node));
    list.tail->next = NULL;
    list.head = list.tail;

    return list;
}

//addNode() should add a new node to the list
SinglyLinkedList addNode(SinglyLinkedList list, int data) {
    
    //makes a new node
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    

    //checks if the list is empty
    if (list.head == NULL) {

        //head and tail point to new node if its empty
        list.head = newNode;
        list.tail = newNode;

        printf("If %d \n\n",newNode->data);
        
    }

    else {
        printf("Else %d \n\n", newNode->data);
        //new node gets pointed to by tail.next
        list.tail->next = newNode;
        //new node becomes new tail
        list.tail = newNode;
    }

    return list;
}

//display() should show all the nodes present in the list
void display() {

    //current is pointer to head
    Node* current = head;
  

    if (current == NULL) {
        printf("List is empty");
        return;
    }

    printf("Nodes of singly linked list: ");
    int i = 0;
    while(current !=  NULL) {
        //Prints each node by incrementing pointer
        i++;
        list.head = list.head->next;
    }
    printf("%d \n", i);


}


int main() {

    SinglyLinkedList sList = makeList();

    printf("%d \n", sList.head->data);
 
    
   
    //printf("%d \n", sList.head->data);
    //Adds nodes to the list
    sList = addNode(sList, 1);
    sList = addNode(sList, 2);
    sList = addNode(sList, 3);
    sList = addNode(sList, 4);

    //Displays the nodes present in the list
    //display(sList);

    return 0;
}