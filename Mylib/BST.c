#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int line=0;
typedef struct 
{
    char name[30];
    char phone[30];
    char email[30];
}ElementType;

struct node {
    ElementType key;
    struct node *left, *right;
};
typedef struct node *Node;

Node newNode(ElementType k)
{
    Node temp = (Node )malloc(sizeof(struct node));
    temp->key = k;
    temp->left = NULL ;
    temp->right = NULL;
    return temp;
}

Node insertTree(Node root, ElementType k)
{
    if (root == NULL)
        return newNode(k);
    else if (strcmp(root->key.name,k.name)>0)
    {
        root->left = insertTree(root->left,k);
    } else root->right = insertTree(root->right,k);
    return root;
}

Node searchTree(Node root, char key[])
{
    if(root == NULL || strcmp(root->key.name,key)==0 ) return root;
    else if (strcmp(root->key.name,key)>0)
    {
        return searchTree(root->left,key);
    }else return searchTree(root->right,key);
}

void inOrder(Node root)
{
    if(root == NULL) return;
    else
    {
        inOrder(root->left);
        printf("%s %s %s\n",root->key.name,root->key.phone,root->key.email);
        inOrder(root->right);
    }
}

Node minValueNode(Node root)
{
    Node cur = root;
    while (cur && cur->left != NULL)
    {
        cur = cur->left;
    }
    return cur;
}

Node deleteNode(Node root, char key[])
{
    if(root == NULL) return root;
    if (strcmp(root->key.name,key)>0)
    {
        root->left = deleteNode(root->left,key);
    }else if (strcmp(root->key.name,key)<0)
    {
        root->right = deleteNode(root->left,key);
    }else
    {
        if (root->left == NULL)
        {
            Node temp = root->right;
            free(root);
            return temp;
        }else if (root->right == NULL)
        {
            Node temp = root->left;
            free(root);
            return temp;
        }
        Node temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right,temp->key.name);
    }
    return root;
}

Node inputData(char nameFile[],Node root)
{
    char str[100];
    int k = 0;
    ElementType* dataList;
    FILE *fi;
    fi = fopen(nameFile,"r");
    if (fi == NULL)
    {
        printf("File khong ton tai.");
        return NULL;
    }
    
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
        root = insertTree(root,dataList[i]);
    }
    free(dataList);
    fclose(fi);
    return root;
}

void deleteTree(Node root)
{
    if(root == NULL) return ;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

int main()
{
    Node root = NULL;
    ElementType* dataList;
    char nameFile[30];
    ElementType tmp = {"Khuyen","9516","khuyen.vd@gmail.com"};
    Node tmpsearch;
    int choice;
    do
    {
        printf("\n===== Menu Program =====\n");
        printf("1. Create\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Find \n");
        printf("5. Exit\n");
        do
        {
            printf("Choose a option >> ");
            scanf("%d",&choice);
        } while (choice < 1 || choice >6);
        switch (choice)
        {
        case 1:
            printf("Nhap ten file >> ");
            fflush(stdin);
            scanf("%s",nameFile);
            root = inputData(nameFile,root);
            break;

        case 2:
            
            insertTree(root,tmp);
            break;

        case 3:
            deleteNode(root,"An");
            break;
                
        case 4:
            tmpsearch = searchTree(root,"Khoa");
            printf("%s %s %s\n",tmpsearch->key.name,tmpsearch->key.phone,tmpsearch->key.email);
            break;

        case 5:
            printf("----Done 5----");
            inOrder(root);
            break;
        case 6:
            deleteTree(root);  
            break;                   
        default:
            
            break;
        }
    } while (choice>=1 && choice<=6);
    
    return 0;
}