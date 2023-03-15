#include<stdio.h>
#include<stdlib.h>
#include<list>
struct lien_ket_doi
{
   int val;
   lien_ket_doi* prev;
   lien_ket_doi* next;
};
typedef struct lien_ket_doi *DNode;

DNode first;
DNode last;

DNode makenode(int v)
{
    DNode p ;
    p = (DNode)malloc(sizeof(struct lien_ket_doi));
    p->val = x;
    p->next = NULL;
    p->prev = NULL;
    return p;
}
void remove(DNode p)
{
    if (p ==NULL)
    {
        return 0;
    }
    if (first == last && p==first)
    {
        first = NULL;
        last = NULL;
        free(p);
    }
    if (p==first)
    {
        first = p->next;
        first ->prev =NULL;
        free(p);
        return ;
    }
    if (p==last)
    {
        last= p->prev;
        last->next=NULL;
        free(p);
        return;
    }
    p->prev->next = p->next;
    p->next->prev= p->prev;
    free(p);
}

void insertLast(int x)
{
    DNode q = makenode(x);
    if (first == NULL && last == NULL)
    {
        first = q;
        last = q;
        return;
    }
    last->next=q;
    q->prev= last;
    last = q;
}
void insertFirst(int x)
{
    DNode p=makenode(x);
    if(first==NULL && last == NULL){
        first = p;
        last = p;
        return;
    }
    first->prev= p;
    p->next=first;
    first=p;
}
void pop_front()
{
    DNode tmp=first;
    while (tmp != NULL)
    {
        printf("%d ",tmp->val);
        tmp = tmp->next
    }
    printf("\n");
}
void pop_back()
{
    DNode tmp=last;
    if (tmp ==NULL) return;
    
    while (tmp != NULL)
    {
        printf("%d ",tmp->val);
        tmp = tmp->next
    }
    printf("\n");
}

int size()
{
    DNode tmp=first;
    int count=0;
    if (tmp ==NULL) return 0;
    while (tmp !=NULL)
    {
        count++;
    }
    return count;
}

void clear()
{
    DNode tmp = first;
    if(tmp == NULL) return;
    while (tmp != NULL)
    {
        first = first->next;
        free(tmp);
        tmp = first;
    }
}
int main()
{

}