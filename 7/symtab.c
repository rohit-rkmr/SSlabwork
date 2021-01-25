#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 7

struct hashTable
{
    char label[10];
    int addr;
} ht[LENGTH];

void Add()
{
    int addr;
    char label[10];
    printf("Enter label name :\n");
    scanf("%s", label);
    printf("Enter label address :\n");
    scanf("%d", &addr);
    int loc = addr % LENGTH;
    if (ht[loc].addr == -1)
    {
        ht[loc].addr = addr;
        strcpy(ht[loc].label, label);
    }
    else
        printf("Hashtable slot occupied\n");
}

void Disp()
{
    for (int i = 0; i < LENGTH; i++)
        if (ht[i].addr != -1)
            printf("%d %s\n", ht[i].addr, ht[i].label);
        else
            printf("0 0\n");
}

void main()
{
    for (int i = 0; i < LENGTH; i++)
    {
        ht[i].addr = -1;
        strcpy(ht[i].label, "");
    }
    int c = 0;
    while (c < 3)
    {
        printf("::::1 to add label\n2 to view hashtable:::\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            Add();
            break;
        case 2:
            Disp();
        }
    }
}
