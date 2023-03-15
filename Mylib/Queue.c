#include <stdio.h>
#include <stdlib.h>
int line = 0;
typedef struct 
{
    char name[30];
    char phone[30];
    char email[30];
}ElementType;

struct node {
    ElementType key;
    struct node* next;
};
typedef struct node *Node;
typedef struct node *topStack;

struct Queue {
    Node front, rear;
};
 
Node newNode(ElementType k)
{
    Node temp = ( Node)malloc(sizeof(struct node));
    temp->key = k;
    temp->next = NULL;
    return temp;
}
 
struct Queue* createQueue()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
 
void enQueue(struct Queue* q, ElementType k)
{
    Node temp = newNode(k);
 
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
 
    q->rear->next = temp;
    q->rear = temp;
}
 
void deQueue(struct Queue* q)
{

    if (q->front == NULL)
        return;
    Node temp = q->front;
 
    q->front = q->front->next;
 
    if (q->front == NULL)
        q->rear = NULL;
 
    free(temp);
}

ElementType* inputData(struct Queue* q)
{
    char str[100];
    int k = 0;
    ElementType* dataList;
    FILE *fi;
    fi = fopen("input.txt","r");
    while (fgets(str,100,fi) != NULL)
    {
        line++;
        k++;
    }
    rewind(fi);
    dataList = (ElementType *)malloc(sizeof(ElementType)*line);
    for (int i = 0; i < line; i++)
    {
        fscanf(fi,"%s %s %s",dataList[i].name,dataList[i].phone,dataList[i].email);
        enQueue(q,dataList[i]);
    }
    free(dataList);
    fclose(fi);
    return dataList;
}
int main()
{
    struct Queue* q = createQueue();
    ElementType* dataList = inputData(q);
    deQueue(q);
    deQueue(q);
    printf("%s %s %s\n",q->front->key.name,q->front->key.phone,q->front->key.email);
    printf("%s %s %s\n",q->rear->key.name,q->rear->key.phone,q->rear->key.email);
    return 0;
}