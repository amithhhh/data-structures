#include <stdio.h>

void prototype1();
int prototype2(int a);

struct Test {
    int x;
    int y;
};

void simple()
{
    printf("Simple\n");
}

int math(int a, int b)
{
    if (a > b) {
        return a - b;
    }

    return a + b;
}

void loops()
{
    for (int i = 0; i < 5; i++) {

        while (i < 2) {
            break;
        }
    }
}

int switch_test(int n)
{
    switch(n) {

        case 1:
            return 10;

        default:
            return 0;
    }
}

void multiline_header
(
    int a,
    int b
)
{
    printf("%d %d\n", a, b);
}

void nested_blocks()
{
    {
        {
            printf("Nested\n");
        }
    }
}

int main()
{
    simple();

    int x = math(10, 20);

    printf("%d\n", x);

    loops();

    switch_test(1);

    multiline_header(1, 2);

    nested_blocks();

    return 0;
}
