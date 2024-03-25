// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};


struct Queue{
    struct Node *front;
    struct Node *rear;
};
void insertBeg(struct Node **node,int data) {
    struct Node *new =(struct Node *)malloc(sizeof(struct Node));
    new->data=data;
    new->next=(*node);
    (*node)->prev=new;
    (*node)=new;
}
void push(struct Queue **s,int data) {
    if((*s)->front == NULL||(*s)->rear==NULL) {
        struct Node *new = (struct Node*)malloc(sizeof(struct Node));
        new->data = data;
        (*s)->front = new;
        (*s)->rear = new;
        return;
    }
    insertBeg(&(*s)->front,data);
}

int pop(struct Queue **s) {
  struct Node *temp = (*s)->rear;
  int x = temp->data;
  if((*s)->rear != (*s)->front) {
      temp->prev->next = NULL;
      (*s)->rear = temp->prev;
      temp->prev = NULL;
  }
  

  free(temp);
  return x;
}


bool isEmpty(struct Queue *s) {
    return (s->rear==NULL||s->front== NULL);
}

int main() {
    struct Queue *s = (struct Queue*)malloc(sizeof(struct Queue));
    push(&s,2);
    push(&s,7);
    push(&s,4);
    push(&s,8);
    push(&s,3);
    push(&s,1);
    while(!isEmpty(s)) {
        printf("%d ",pop(&s));
    }

    return 0;
}