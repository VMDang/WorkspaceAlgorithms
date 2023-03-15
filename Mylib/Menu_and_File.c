#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int line=0;
typedef struct 
{
    char name[30];
    char phone[30];
    char email[30];
}ElementType;

void printData(ElementType *dataList)
{
    for (int i = 0; i < line; i++)
    {
        printf("%s %s %s\n",dataList[i].name,dataList[i].phone,dataList[i].email);
    }
    printf("\n");
}

ElementType* inputData(char nameFile[])
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
    }
    free(dataList);
    fclose(fi);
    return dataList;
}

int main()
{
    ElementType* dataList;
    char nameFile[30];
    int choice;
    do
    {
        printf("\n===== Menu Program =====\n");
        printf("1. \n");
        printf("2. \n");
        printf("3. \n");
        printf("4. \n");
        printf("5. \n");
        do
        {
            printf("Choose a option >> ");
            scanf("%d",&choice);
        } while (choice < 1 || choice >5);
        switch (choice)
        {
        case 1:
            printf("Nhap ten file >> ");
            fflush(stdin);
            scanf("%s",nameFile);
            dataList = inputData(nameFile);
            break;

        case 2:
            printf("----Done 2----");
            break;

        case 3:
            printData(dataList);
            printf("----Done 3----");
            break;
                
        case 4:
            printf("----Done 4----");
            break;

        case 5:
            printf("----Done 5----");
            exit(1);
            break;
                                    
        default:
            
            break;
        }
    } while (choice>=1 && choice<=5);
    
    return 0;
}