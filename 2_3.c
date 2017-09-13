#include<stdio.h>

#define MAX 21


void push1(int a[], int *top1, int *top2);
int pop1(int a[], int *top1);
void display1(int a[], int *top1);
void push2(int a[], int *top2, int *top1);
int pop2(int a[], int *top2);
void display2(int a[], int *top2);

int main(void)
{
    int a[MAX];
    int top1 = -1, top2 = MAX;
    int ch;

    while(1)
    {
        printf("\nChoose option 1. push1 2. pop1 3. display1 4. push2 5. pop2 6. display2 7. Exit\n");
        int put;
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                push1(a,&top1,&top2);
                break;

            case 2:
                put = pop1(a,&top1);
                if(put == -9111)
                    break;
                else
                {
                    printf("\nPopped value is %d\n",put);
                    break;
                }

            case 3:
                display1(a,&top1);
                break;

            case 4:
                push2(a,&top2,&top1);
                break;

            case 5:
                put = pop2(a,&top2);
                if(put == -9111)
                    break;
                else
                {
                    printf("\nPopped value is %d\n",put);
                    break;
                }

            case 6:
                display2(a,&top2);
                break;
       }
       if(ch == 7)
            break;
    }
}


    void push1 (int a[], int *top1, int *top2)
    {   

        if(*top1 < *top2+1)
        {
            int val;
            printf("Enter Value\n");
            scanf("%d",&val);
            a[++(*top1)] = val;
        }
        else
            printf("\nStack Overflow\n");
    }


    int pop1(int a[], int *top1)
    {
        if(*top1 < 0)
        {
            printf("\nStack Underflow\n" );
            return -9111;
        }

        else
            return a[(*top1)--];
    }


    void display1(int a[], int *top1)
    {
        int i;
        if(*top1 < 0)
            printf("\nStack Empty\n");

        else
        {
            printf("\n");

            for(i=0 ; i<=*top1 ; i++)
                printf("%d ",a[i]);

            printf("\n");
        }
    }


        void push2(int a[], int *top2, int *top1)
        {   

            if(*top2 > *top1+1)
            {
                int val;
                printf("Enter Value\n");
                scanf("%d",&val);
                a[--(*top2)] = val;
            }
            else
                printf("\nStack Overflow\n");
        }


        int pop2(int a[], int *top2)
        {
            if(*top2 > MAX-1)
            {
                printf("\nStack Underflow\n" );
                return -9111;
            }

            else
                return a[(*top2)++];
        }


        void display2(int a[], int *top2)
        {
            int i;
            if(*top2 > MAX-1)
                printf("\nStack Empty\n");

            else
            {
                printf("\n");

                for(i= MAX-1 ; i>=*top2 ; i--)
                    printf("%d ",a[i]);

                printf("\n");
            } 
        }
