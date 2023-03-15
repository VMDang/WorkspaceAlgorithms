#include<stdio.h>
#include<stdlib.h>
struct binarynode
{
    int id;
    struct binarynode *left;
    struct binarynode *right;
};
typedef struct binarynode *BNode;
BNode makeBNode(int x)
{
    BNode new= NULL;
    new = (BNode )malloc(sizeof(struct binarynode));
    if (new == NULL)
    {
        printf("Tao nut that bai.\n");
        exit(1);
    }
    else
    {
        new->left == NULL;
        new->right==NULL;
        new->id == x;
    }
    return new;
}

int countNode(BNode r)
{
    if(r == NULL) return 0;
    else return countNode(r->left) + countNode(r->right) +1;    
}

int depth(BNode r)
{
    if(r==NULL) return 0;
    else
    {
        int ld = depth(r->left);
        int rd = depth(r->right);
        if (ld > rd)
        {
            return 1 + ld;
        }else return 1 + rd;
    }
    
}
int main()
{

}