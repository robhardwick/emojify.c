#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <locale.h>
#include <stdint.h>
#include <time.h>

const wchar_t emojis[] = {
    L'👌', L'👏', L'😂', L'😛',
    L'💯', L'😤', L'😩', L'🤔',
    L'👀', L'😳', L'😜', L'💩',
    L'👻', L'💪', L'😏', L'🔥',
};

int main(void) {
    // Set locale
    setlocale(LC_ALL, "");

    // Seed rand
    srand(time(NULL));

    // Read input
    char c;
    while((c = getc(stdin)) != EOF) {
        // Output emoji character on whitespace with 50% probability
        if (c == ' ' && rand() % 2) {
            printf(" %lc  ", emojis[rand() % (sizeof(emojis) / sizeof(wchar_t))]);

        // Output all other characters as-is
        } else {
            putchar(c);
        }
    }

    return 0;
}
