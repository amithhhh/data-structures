#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void generate(char *a, int pos) {
    if (pos == 3) {
        printf("%s\n", a);
        return;
    }
    for (int i = 0; a[i] != '\0'; i++) {
            swap(&a[i], &a[pos]);
            generate(a, pos + 1);
            swap(&a[pos], &a[i]);
    }

}

int main() {
    char a[100];
    printf("Enter the value: ");
    fgets(a, 100, stdin);

    a[strlen(a) + 1] = '\0';

    generate(a, 0);
    return 0;
}