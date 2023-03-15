#include <stdio.h>
#include <stdlib.h>

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

Node top;
int line = 0;

Node newNode(ElementType k)
{
    Node temp = ( Node)malloc(sizeof(struct node));
    temp->key = k;
    temp->next = NULL;
    return temp;
}

void push(ElementType k)
{

    Node temp = newNode(k);

    if (!temp)
    {
        printf("Stack Overflow");
        return ;
    }
 
 
    temp->next = top;
 
    top = temp;
}

ElementType peek()
{ 
    if (top != NULL)
        return top->key;
    else printf("Stack underflow");
}

void pop()
{
    Node temp;

    if (top == NULL)
    {
        printf("Stack Underflow");
        return;
    }
    else
    {
        temp = top;
        top = top->next;
        free(temp);
    }
}

ElementType* inputData()
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
        push(dataList[i]);
    }
    free(dataList);
    fclose(fi);
    return dataList;
}

int main()
{
    ElementType* dataList = inputData();
    for (Node i = top; i != NULL; i=i->next)
    {
        printf("%s ",i->key.name);
    }
    pop();
    pop();
    ElementType tmp = peek();
    printf("\n%s %s %s ",tmp.name,tmp.email,tmp.phone);
}