#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 20

struct stack
{
    int top;
    float data[SIZE];
};

typedef struct stack STACK;

void push(STACK *s, float item)
{
    s->data[++s->top] = item;
}

float pop(STACK *s)
{
    return s->data[(s->top)--];
}

float compute(float oper1, char symbol, float oper2)
{
    switch(symbol)
    {
        case '+': return oper1 + oper2;
        case '-': return oper1 - oper2;
        case '*': return oper1 * oper2;
        case '/': return oper1 / oper2;
        case '^': return pow(oper1, oper2);
    }

    return 0;
}

float Eval_postfix(STACK *s, char postfix[15])
{
    char symbol;
    int i;
    float oper1, oper2, res;

    for(i = 0; postfix[i] != '\0'; i++)
    {
        symbol = postfix[i];

        if(isdigit(symbol))
        {
            push(s, symbol - '0');
        }
        else
        {
            oper2 = pop(s);
            oper1 = pop(s);

            res = compute(oper1, symbol, oper2);

            // Push the result back onto the stack
            push(s, res);
        }
    }

    return pop(s);
}

int main()
{
    STACK s;
    s.top = -1;

    char postfix[20];
    float result;

    printf("\nRead postfix expression: ");
    scanf("%s", postfix);

    result = Eval_postfix(&s, postfix);

    printf("\nThe final answer is %f\n", result);

    return 0;
}

