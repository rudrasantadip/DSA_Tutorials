#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node *next;
}Node;


typedef struct LinkedList
{
    Node *head;
}LinkedList;


Node* createNode(int data){
    Node  *newNode = (Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}


LinkedList* createList(int data){
   LinkedList*ll = (LinkedList*)malloc(sizeof(LinkedList));
   ll->head=createNode(data);
   return ll;
}


void insert(LinkedList *ll, int data){
    Node *temp = ll->head;
    while(temp->next!=NULL)
        temp = temp->next; //shift
    temp->next= createNode(data);
}

void insertAtHead(LinkedList *ll, int data){
    Node *newNode = createNode(data);
    newNode->next=ll->head;
    ll->head=newNode;
}

void insertAt(LinkedList *ll, int data, int position){
    Node *temp = ll->head;
    Node *newNode = createNode(data);
    for(int i=1;i<position-1;i++){
        temp=temp->next;
    }
    // insertion
    newNode->next=temp->next;
    temp->next=newNode;
}

void printList(LinkedList *ll){
    Node *temp = ll->head;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
}

//length of the linkedlist
int length(LinkedList *ll){
    Node *temp = ll->head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

int kThNodeFromLast(LinkedList *ll, int k){
    int kthNode = length(ll)- k + 1;
    Node *temp = ll->head;
    for(int i=1;i<kthNode;i++){
        temp=temp->next;
    }
    return temp->data;
}

int main()
{

    LinkedList *ll = createList(1);
    insert(ll,10);
    insert(ll,20);
    insert(ll,30);

    insertAtHead(ll,50);
    insertAt(ll,99,3);
    printList(ll);

    printf("\nLength of the linkedlist: %d",length(ll));
    printf("\n%d",kThNodeFromLast(ll,2));
    return 0;
}
