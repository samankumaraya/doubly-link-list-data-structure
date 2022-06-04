# include <stdio.h>

typedef enum {FALSE, TRUE} Boolean;

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}Node;

typedef struct dlist{
    int count;
    Node *head;
    Node *tail;

}DList;


void createList(DList *dl){
    dl->count = 0;
    dl->head  = NULL;
    dl->tail=NULL;
}

void insertfront (DList *l, int x){

    Node *temp;
    temp=(Node *)malloc(sizeof(Node));

    temp->data = x;
    if (dl->count==0)
        temp->next = NULL;
        temp->prev = NULL;
    else
        temp->next = dl->head;
        temp->prev = NULL;

    dl->head = temp;
    dl->count++;
}

void insertrear(DList *dl, int x){

    Node *temp, *p;
    temp=(Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;

    if (dl->count==0)
        dl->head = temp;
        dl->tail =temp;
    else{
      temp->prev=dl->tail;
      dl->tail->next=temp;

    }
    l->count++;
}
/*
void insertAt(List *l, int x, int n){//n is the position that we need to insert the value x

    Node *temp, *p;
    int j=1;//finding the position
    temp=(Node *)malloc(sizeof(Node));
    temp->data = x;

    if (l->count<n){
        printf("Position is out of the list");
        exit();
    }
    else{
        p = l->head;
        while(j<n){
            p = p->next;
            j++;
        }
        temp->next = p->next;
        p->next = temp;

    }
    l->count++;
} */

void printlistfromhead(DList *dl){

    Node *temp;

    temp = dl->head;

    while(temp != NULL){
        printf ("%d -- >",temp->data);
        temp = temp->next;
    }
}

void printlistfromtail(DList *dl){

    Node *temp;

    temp = dl->tail;

    while(temp != NULL){
        printf ("%d -- >",temp->data);
        temp = temp->prev;
    }
}

int deletefront(DList *dl){

    int result;

    Node *temp;
    if(dl->count==0){
        printf ("Trying to delete from empty list");
        exit();
    }
    temp = dl->head;
    result = temp->data;

    temp->next->prev=NULL;
    dl->head = temp->next;
    free(temp);
    dl->count--;
    return result;

}
int deleterear(DList *dl){

    int result;

    Node *temp;
    if(dl->count==0){
        printf ("Trying to delete from empty list");
        exit();
    }
  temp=dl->tail;
  temp->prev->next=NULL;
  dl->tail=temp->prev


    free(temp);


    dl->count--;
    return result;

}
/*
void deleteAt(List *l, int n){

     int result;
        int j=1;
    Node *temp;
    if(l->count==0){
        printf ("Trying to delete from empty list");
        exit();
    }
    if (n<0 || n>l->count){
        printf ("Trying to delete a position out side the list");
        exit();
    }
    temp=l->head;
    while (j<n-1){
        temp = temp->next;
        j++;
    }

    result = temp->next->data;

    temp->next = temp->next->next;

    l->count--;
    return result;

}*/

