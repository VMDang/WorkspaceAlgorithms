/*
Lưu trữ cây sử dụng con trái và em kế cận phải
Giả định mỗi Node ở đây là số nguyên NodeT = int
chưa xác định được cách đưa cây vào
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int id;
    struct node *leftMostChild;
    struct node *rightSibling;
};
typedef struct node *NODE;
NODE CreatNode(int v)
{
    NODE new;
    new = (NODE)malloc(sizeof(struct node));
    new->id = v;
    new->leftMostChild = NULL;
    new->rightSibling = NULL;
    return new;
}
NODE find(NODE r,int v)
{
    if (r==NULL) 
    {
       return NULL;
    }
    if (r->id==v)
    {
        return r;
    }
    NODE p =r ->leftMostChild;
    while (p!=NULL)
    {
        NODE h = find(p,v);
        if (h!=NULL)
        {
            return h;
        }
        p = p->rightSibling;
    }
    return NULL;
}
void preOrder(NODE r)
{
    if (r==NULL)
    {
        return;
    }
    printf("%d ",r->id);
    NODE p=r->leftMostChild;
    while (p!=NULL)
    {
        preOrder(p);
        p = p->rightSibling;
    }
    
}

void inOrder(NODE r)
{
    if(r==NULL) return;
    NODE p=r->leftMostChild;
    inOrder(p);
    printf("%d ",r->id);
    if (p!=NULL)
    {
        p = p->rightSibling;
    }
    while (p!=NULL)
    {
        inOrder(p);
        p = p->rightSibling;
    }
    
}
void postOrder(NODE r)
{
    if(r==NULL) return;
    NODE p=r->leftMostChild;
    while (p!=NULL)
    {
        postOrder(p);
        p = p->rightSibling;
    }
    printf("%d ",r->id);
}
int count(NODE r)
{
    if(r==NULL) return 0;
    int s=1;
    NODE p=r->leftMostChild;
    while (p!=NULL)
    {
        s += count(p);
        p = p->rightSibling;
    }
    return s;
}
int countLeaves(NODE r)
{
    if(r==NULL) return 0;
    int s=0;
    NODE p= r->leftMostChild;
    if(p==NULL) s=1;
    while (p!=NULL)
    {
       s += countLeaves(p);
       p = p->rightSibling;
    }
    return s;
}
int height(NODE p)
{
    if(p== NULL) return 0;
    int maxh = 0;
    NODE q = p->leftMostChild;
    while (q!= NULL)
    {
        int h = height(q);
        if(h> maxh) maxh =h;
        q = q->rightSibling;
    }
    return maxh+1;
}
int depth(NODE r,int v,int d)
{
    // d la do sau cua nut
    if(r==NULL) return -1;
    if(r->id == v) return d;
    NODE p = r->leftMostChild;
    while (p!=NULL)
    {
        if(p->id == v) return d+1;
        int dv = depth(p,v,d+1);
        if(dv>0) return dv;
    }
}
NODE parent(NODE p,NODE r)
{
    if(r == NULL) return NULL;
    NODE q= r->leftMostChild;
    while (q != NULL)
    {
        if(p == q) return r;
        NODE pp = parent(p,q);
        if (pp != NULL) 
        {
            return pp;
        }
        q =q ->rightSibling;
    }
    return NULL;
}
NODE AddNode(NODE r, NODE new)
{
    if (r == NULL)
    {
        return new;
    }
    NODE p = r->leftMostChild;
    while (p != NULL)
    {
        p =  AddNode(p,new);
        p = p->rightSibling;
    }
}
void Input(NODE r)
{
    int input;
    NODE new;
    do
    {
        scanf("%d",&input);
        if (input == 0)
        {
            new = NULL;
        }else new = CreatNode(input);
        AddNode(r,new);
    } while (input != -1);
}
int main()
{
    NODE root=NULL;
    NODE new = CreatNode(9);
    int v;
    // Input(root);
    root = AddNode(root,new);
    NODE node2 = root->leftMostChild = CreatNode(8);
    NODE node3 = node2->rightSibling = CreatNode(6);
    NODE node4 = node3->rightSibling = CreatNode(3);
    NODE node5 = node2->leftMostChild = CreatNode(1);
    NODE node6 = node5->rightSibling = CreatNode(2);
    NODE node7 = node3->leftMostChild = CreatNode(10);
    NODE node8 = node7->rightSibling = CreatNode(13);
    NODE node9 = node4->leftMostChild = CreatNode(20);
    NODE node10 = node9->rightSibling =  CreatNode(25);
    NODE node11 = node6->leftMostChild =  CreatNode(4);
    NODE node12 = node11->rightSibling = CreatNode(7);
    NODE node13 = node7->leftMostChild =  CreatNode(11);
    
    printf("\n-------------Preoder----------------\n");
    preOrder(root);
    printf("\n-------------Postorder----------------\n");
    postOrder(root);
    printf("\n-------------Inorder----------------\n");
    inOrder(root);
}