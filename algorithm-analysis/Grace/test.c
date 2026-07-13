#include <stdio.h>

int a = 10;

void hello()
{
    if (a > 5) {
        printf("Hello\n");
    }
}

int sum(int a,int b){
    return a+b;
}

/* comment
void fake(){
}
*/

int complex_function(int x)
{
    for(int i=0;i<x;i++)
    {
        if(i%2==0)
        {
            printf("%d\n",i);
        }
    }
    return x;
}

int main(){
    hello();
    printf("%d\n",sum(2,3));
    return 0;
}
