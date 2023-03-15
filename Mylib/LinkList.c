#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int line = 0;
int count=0;
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

Node newNode(ElementType k)
{
    Node temp = ( Node)malloc(sizeof(struct node));
    temp->key = k;
    temp->next = NULL;
    return temp;
}

void printLinkedList(Node h)
{
    for ( Node i = h; i != NULL; i = i->next )
    {
        printf("%s %s %s\n",i->key.name,i->key.phone,i->key.email);
    }
    printf("\n");
}

Node AddHead(Node h,ElementType k)          //Phần tử mới được thêm vào đầu sanh sách
{
    if(h==NULL) return newNode(k);
    else
    {
        Node tmp = newNode(k);
        tmp->next = h;
        h = tmp;
        return h;
    }
}

Node AddTail(Node h,ElementType k)          //Phần tử mới được thêm vào đầu sanh sách
{
    if(h==NULL) return newNode(k);
    else
    {
        Node tmp = newNode(k);
        Node cur = h;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = tmp;
        return h;
    }
    return h;
}

Node AddAfter(Node pre, ElementType k)      //Thêm sau node pre
{
    if(pre == NULL) return newNode(k);
    else
    {
        Node tmp = newNode(k);
        tmp->next = pre->next;
        pre->next = tmp;
        return pre;
    }
    
}

Node AddLLSorted(Node h,ElementType k)      // Sắp xếp danh sách từ đầu vào
{
    if(h == NULL) return newNode(k);
    Node tmp = newNode(k);
    Node pre;
    if(strcmp(h->key.name,tmp->key.name) > 0)
    {    
        tmp->next = h;
        return tmp;
    }
    else
    {
        Node cur = h;
        while (cur != NULL && strcmp(cur->key.name,tmp->key.name) < 0)
        {
            pre = cur;
            cur = cur->next;
        }
        AddAfter(pre,k);
        return h;
    }
    
}

Node inputData(Node h)
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
        h = AddTail(h,dataList[i]);
        //h = AddHead(h,dataList[i]);
        //h = AddLLSorted(h,dataList[i]);
    }
    free(dataList);
    fclose(fi);
    return h;
}

Node DeleteNode(Node h,char key[])          // Xóa Node có key (Đệ quy xóa toàn bộ)
{
    Node tmp = h;
    if (h == NULL)
    {
        return NULL;
    }
    
    if (tmp != NULL && strcmp(tmp->key.name,key)==0)
    {
        h = tmp->next;
        free(tmp);
    }
    h->next = DeleteNode(h->next,key); //Xóa tất cả người tên key
    return h;
}

Node DeleteAll(Node h)
{
    if(h == NULL) return NULL;
    else
    {
        Node tmp = h;
        h = tmp->next;
        free(tmp);
        h->next = DeleteAll(h->next);
    }
}

void FindNode(Node h,char key[])          // Tìm Node có key (Đệ quy xóa toàn bộ)
{
    if (h == NULL) 
    {
        return ;
    }
    if (h != NULL && strcmp(h->key.name,key)==0)
    {
        printf("%s %s %s\n",h->key.name,h->key.phone,h->key.email);
        count++;
    }
    FindNode(h->next,key);
}

void selectionSort(Node head)
{
    Node temp = head;
 
    while (temp) {
        Node min = temp;
        Node r = temp->next;
        while (r) {
            if (strcmp(min->key.name,r->key.name) > 0)
                min = r;
            r = r->next;
        }
        ElementType x = temp->key;
        temp->key = min->key;
        min->key= x;
        temp = temp->next;
    }
}

int main()
{
    Node h = NULL;
    int choice;
    do
    {
        printf("\n===== Menu Program =====\n");
        printf("1. Delete Dung\n");
        printf("2. Add \n");
        printf("3. Print\n");
        printf("4. Find and print\n");
        printf("5. \n");
        do
        {
            printf("Choose a option >> ");
            scanf("%d",&choice);
        } while (choice < 1 || choice >5);
        switch (choice)
        {
        case 1:
            h = DeleteNode(h,"Dung");
            break;

        case 2:
            h = inputData(h);
            //selectionSort(h);
            break;

        case 3:
            printLinkedList(h);
            break;
                
        case 4:
            count = 0;
            FindNode(h,"Dung");
            if (count == 0)
            {
                printf("Khong tim thay");
            }
            break;

        case 5:
            printf("----Done 5----");
            h = DeleteAll(h);
            exit(1);
            break;
                                    
        default:
            
            break;
        }
    } while (choice>=1 && choice<=5);
}