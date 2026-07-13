#include <stdio.h>
#include <string.h>

#define MAX 100

char STACK[MAX];
int TOP = -1;

void push(char c);
void pop();
int STACK_EMPTY();

int check_header(char*, char*);

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("[-]Usage: ./read <path>\n");
        return -1;
    }

    FILE *ptr;

    // opening the file.
    ptr = fopen(argv[1], "r");

    if (ptr == NULL) {
        printf("[-]Error %s opening in read mode\n", argv[1]);
        return -1;
    }

    printf("[+]%s opened in read mode.\n", argv[1]);

    char line[256];
    char next_line[256];

    int count = 0;
    int head = 0;

    while (fgets(line, sizeof(line), ptr) != NULL) {

        long pos = ftell(ptr);

        if (fgets(next_line, sizeof(next_line), ptr) == NULL) {
            next_line[0] = '\0';
        }

        fseek(ptr, pos, SEEK_SET);

        int if_head = check_header(line, next_line);

        if (if_head == 2) {
            head = 1;
            push('{');
        }

        else if (if_head == 1) {
            head = 1;
        }

        if (head && strchr(line, '{')) {

            // avoid double push
            if (if_head != 2) {
                push('{');
            }
        }

        if (head && strchr(line, '}')) {

            while (!STACK_EMPTY() && STACK[TOP] != '{') {
                pop();
            }

            if (!STACK_EMPTY()) {
                pop();
            }
        }

        // function completed
        if (head && STACK_EMPTY()) {
            count++;
            head = 0;
        }
    }

    printf("No of user-defined functions: %d\n", count);

    fclose(ptr);

    return 0;
}

int check_header(char *s, char *t) {

    // exclude control statements and declarations
    if (
        strstr(s, "if(") || strstr(s, "if (") ||
        strstr(s, "for(") || strstr(s, "for (") ||
        strstr(s, "while(") || strstr(s, "while (") ||
        strstr(s, "switch(") || strstr(s, "switch (") ||
        strchr(s, ';')
    ) {
        return 0;
    }

    // possible function header
    if (strchr(s, '(') && strchr(s, ')')) {

        if (strchr(s, '{')) {
            return 2;
        }

        else if (strchr(t, '{')) {
            return 1;
        }
    }

    return 0;
}

void push(char c) {

    if (TOP == MAX - 1) {
        return;
    }

    STACK[++TOP] = c;
}

void pop() {

    if (TOP == -1) {
        return;
    }

    TOP--;
}

int STACK_EMPTY() {

    if (TOP == -1) {
        return 1;
    }

    return 0;
}
