#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
 
typedef struct stack
{
    int n;
    stack *pNext;
}STACK, *P_STACK, **PP_STACK;
 typedef int ElementType;
void InitStack(PP_STACK top);
bool IsStackEmpty(P_STACK top);
bool Push(int n, PP_STACK top);
int Pop(PP_STACK top);
void DisplayStack(P_STACK top);
int main()
{
    P_STACK top;
    int sel = 0;
    int n,S;
    ElementType x;
    char isContinue;
    printf("\n****************Express stack by Single Link List**************");
    InitStack(&top);
    printf("\n1. Nap thong tin vao stack");
    printf("\n2. Lay thong tin tu stack");
    printf("\n3. Hien thi stack");
    printf("\n4. Tim kiem stack");
    printf("\n5. Exit");
    do
    {
        printf("\nMoi ban chon: ");
        scanf("%d", &sel);
        switch(sel)
        {
        case 1:
            printf("\n2. Nap thong tin vao stack: ");
            scanf("%d", &n);
            if(Push(n, &top))
                printf("\nNap thong tin thanh cong");
            break;
        case 2:
            printf("\n3. Lay thong tin tu stack: ");
            printf("\nn = %d",Pop(&top));
            break;
        case 4:
            printf("\n4. Hien thi stack: ");
            DisplayStack(top);
            break;
        default:
            printf("\nExit");
        }
        printf("\nBan muon thao tac tiep ko (Y/N)? ");
        fflush(stdin);
        isContinue = getchar();
    }
    while(isContinue == 'y' || isContinue == 'Y');
    getch();
}
void InitStack(PP_STACK top)
{
    *top = NULL;
}
bool IsStackEmpty(P_STACK top)
{
    if(top == NULL)
        return false;
    else
        return true;
}
bool Push(int n, PP_STACK top)
{
    P_STACK pstack, p;
    pstack = (P_STACK)malloc(sizeof(STACK));
    if(pstack == NULL)
    {
        return false;
    }
    else
    {
        pstack->n = n;
        pstack->pNext = NULL;
    }
    p = *top;
    if(*top == NULL)
    {
        *top = pstack;
    }
    else
    {
        *top = pstack;
        pstack->pNext = p;
    }
    return true;
}
 
int Pop(PP_STACK top)
{
    int a;
    P_STACK p;
    p = (*top);
    if(IsStackEmpty(*top))
    {
        a = (*top)->n;
        (*top) = (*top)->pNext;
        free(p);
        return a;
    }
}

void DisplayStack(P_STACK top)
{
    P_STACK p;
    p = top;
    if(IsStackEmpty(top))
    {
        while(p)
        {
            printf("%d\t", p->n);
            p = p->pNext;
        }
    }
    else
        printf("\n Stack is empty");
}
