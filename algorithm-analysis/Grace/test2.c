#include <stdio.h>

#define SQUARE(x) ((x)*(x))

// Prototype (should NOT be counted)
int prototype_function(int a, int b);

/* Fake function inside comment
int fake() {
    return 0;
}
*/

static int helper(int a)
{
    return a * 2;
}

int add(int a,int b)
{
    return a+b;
}

void tricky()
{
    if (1)
    {
        printf("Inside if\n");
    }

    for(int i=0;i<5;i++)
    {
        printf("%d\n",i);
    }
}

// Function with brace on next line
float divide(float a,float b)
{
    if(b==0){
        return 0;
    }
    return a/b;
}

// Another tricky formatting
int weird_format(int a, int b)
{
    return a-b;
}

int main()
{
    int x = add(5,3);
    printf("%d\n",x);
    return 0;
}
