//Circular Linked List


#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

void printList(Node *head)
{
    Node *temp=head;
    while (temp->next!=head)
    {
        printf(" %d ",temp->data);
        temp=temp->next;
    }
    printf(" %d ",temp->data);
    
}

Node *createNode(int data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

Node *insertAtBeginning(Node *head, int data)
{
    Node *newNode =createNode(data);
    if(head==NULL)
    {
        newNode->next=newNode;
        return newNode;
    }
    else
    {
        Node *temp=head;
        while (temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=head;
        head=newNode;
        return head;
    }
}

Node *insertAtEnd(Node *head, int data)
{
    Node *newNode = createNode(data);
    if(head==NULL)
    {
        newNode->next=newNode;
        return newNode;
    }
    else
    {
       Node *newNode=createNode(data); 
       Node *temp =head;
       while (temp!=temp->next)
       {
        temp=temp->next;
       }
       temp->next=newNode;  
       newNode->next=head;
       return head;
    }
}

int main()
{
    Node *head =NULL;
    head = insertAtEnd(head,10);
    head=insertAtEnd(head,20);
    head=insertAtBeginning(head,30);   
    printList(head);
    return 0;
}