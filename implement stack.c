#include <stdio.h>
#include <stdlib.h>
#define Size 5
struct Stack
{
    int top;
    int data[Size];
};
typedef struct Stack STACK;
void push(STACK *s,int item)
{
    if(s->top == Size-1)
        printf("\n Stack overflow");
    else{
    s->top=s->top+1;
    s->data[s->top]=item;
    }
}
void pop(STACK*s)
{
    if(s->top=-1)
        printf("\n Stack  underflow");
    else
        printf("\n Element poped is  :%d",s->data[s->top]);
        s->top=s->top-1;
}
void display(STACK s)
{
    int i;
    if(s.top==-1)
        printf("\an stack is empty");
    else
    {
        printf("\n stack content are:");
        for(i=s.top;i>=0;i--)
            printf("%d \n",s.data[i]);
    }
}
int main()
{
    int item,ch;
    STACK s;
    s.top=-1;
    for(;;)
    {
        printf("\n 1.push");
        printf("\n 2.pop");
        printf("\n 3.display");
        printf("\n 4.exit");
        printf("\n read a choice");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:printf("\n read element to be pushed");
            scanf("%d",&item);
            push(&s,item);
            break;
            case 2:pop(&s);
            break;
            case 3:display(s);
            break;
            default:exit(0);
        }
    }
    return 0;
}
