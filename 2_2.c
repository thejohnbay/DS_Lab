#include<stdio.h>

#define MAX 20


void push(int a[], int *top);
int pop(int a[], int *top);
void display(int a[], int *top);
int empty(int *top);

int main(void)
{
    int a[MAX];
    int top = -1;
    int ch;

    while(1)
    {
        printf("\nChoose option 1. Push 2. Pop 3. Display 4. Empty 5. Exit\n");
        int put; int check; 
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                push(a,&top);
                break;

            case 2:
                put = pop(a,&top);
                if(put == -9111)
                    break;
                else
                {
                    printf("\nPopped value is %d\n",put);
                    break;
                }

            case 3:

                display(a,&top);
                break;

            case 4:
                check = empty(&top);
                (check==1)?(printf("Stack not empty\n")):(printf("Stack empty\n"));
                break;
       }
       if(ch == 5)
            break;
    }
}

    void push(int a[], int *top)
    {   

        if(*top < MAX)
        {
            int val;
            printf("Enter Value\n");
            scanf("%d",&val);
            a[++(*top)] = val;
        }
        else
            printf("\nStack Overflow\n");
    }


        int pop(int a[], int *top)
        {
            if(*top < 0)
            {
                printf("\nStack Underflow\n" );
                return -9111;
            }

            else
                return a[(*top)--];
        }


            void display(int a[], int *top)
            {
                int i;
                if(*top < 0)
                    printf("\nStack Empty\n");

                else
                {
                    printf("\n");

                    for(i=0 ; i<=*top ; i++)
                        printf("%d ",a[i]);

                    printf("\n");
                }    
                
            }

        int empty(int *top)
        {
            return (*top >= 0)? 1 : 0;
        }
