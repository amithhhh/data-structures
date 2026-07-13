#include <stdio.h>

/* This is a comment block
int fake_function() {
    return 0;
}
*/

int add(int a, int b){
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

void display()
{
    printf("Hello\n");
}

int multiply(int a, int b) {
    return a * b;
}

// Not a function
if (1) {
    printf("Not a function\n");
}

int main(){
    int x = add(2,3);
    int y = sub(5,2);

    if (x > y) {
        printf("x is bigger\n");
    }

    return 0;
}
