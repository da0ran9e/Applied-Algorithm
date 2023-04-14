#include <stdio.h>
#include <ctype.h>

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            putchar(toupper(c));
        } else {
            putchar(c);
        }
    }

    return 0;
}
