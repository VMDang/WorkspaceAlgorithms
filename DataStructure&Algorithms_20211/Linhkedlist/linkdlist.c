// Vu Minnh Dang 20205063 LinkedList
#include<stdio.h>
#include<stdlib.h>

// Khai báo cấu trúc node
struct node 
{
    int data;
    struct node * pNext;
};
typedef struct node *NODE;
NODE Head()
{
    NODE head;
    head = NULL;
    return head;
}
NODE Khoitao(int getdata)
{
    NODE newnode;
    newnode = (NODE )malloc(sizeof(struct node));
    newnode -> data = getdata;
    newnode ->pNext = NULL; 
    return newnode;
       
}
NODE AddHead(NODE head,int getdata)
{
    NODE tmp = Khoitao(getdata);
    if (head == NULL)
    {
        head = tmp;
    }else
    {
        tmp ->pNext = head;
        head = tmp;
    }
    return head;
    
}
NODE AddTail(NODE head, int getdata)
{
    NODE tmp,p;
    tmp = Khoitao(getdata);
    if (head==NULL)
    {
        head = tmp;
    }
    else
    {
        p = head;
        while (p->pNext != NULL)
        {
            p = p->pNext;
        }
        p ->pNext = tmp;
    }
    return head;
}
void print(NODE head)
{
    if (head == NULL)
    {
        printf("ERROR LIST.");
    }
    for (NODE k = head; k != NULL ;k=k->pNext)
    {
        printf("%d ",k->data);
    }
    printf("\n");
}

NODE Input()
{
    NODE head = Head();
    int n;
    printf("Length list:");
    scanf("%d",&n);
    
    printf("Number:\n");
    fflush(stdin);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d",&x);
        head = AddTail(head,x);
    }
    return head;
}
NODE DeleteAt(NODE head, int del_num)
{
    int i=1;
    NODE p = head;
    while (p->pNext->pNext != NULL && i!= del_num)
    {
        p = p ->pNext;
       ++i;
    }
    if (i == del_num)
    {
        p->pNext = p->pNext->pNext;
    }

    return head;
    
}
NODE AddAt(NODE head,int num_add, int getdata)
{
    if (num_add ==0 || head==NULL)
    {
        head = AddHead(head,getdata);
    }else
    {
        int i=1;
        NODE p = head ;
        while (p!= NULL && i!= num_add)
        {
            p = p ->pNext;
            ++i;
        }
        if (i != num_add)
        {
            head = AddTail(head,getdata);
        }else
        {
            NODE tmp = Khoitao(getdata);
            tmp->pNext = p->pNext;
            p->pNext = tmp;
        }
    }
    return head;  
}

NODE DeleteAll(NODE head)
{
    NODE p = head;
    while (p != NULL)
    {
        head = head->pNext;
        free(p);
        p = head;
    }
    return head;
}
int main()
{
    NODE head = Input();
    printf("------------Xoa vi tri so 1-----------------")
    head = DeleteAt(head,1);
    print(head);
    printf("----------Them vao vi tri so 2 ----------\n");
    fflush(stdin);
    int data_temp;
    scanf("%d",&data_temp);
    head = AddAt(head,2,data_temp);
    print(head);
    printf("-----------Xoa vi tri so 3 ---------\n");
    head = DeleteAt(head,3);
    print(head);
}