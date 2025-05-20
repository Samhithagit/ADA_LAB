#include <stdio.h>
#include <string.h>

void patternMatching(char text[], char pattern[]) {
    int textlen = strlen(text);
    int patternlen = strlen(pattern);
    int found = 0;

    for (int i = 0; i <= textlen - patternlen; i++) {
        int j;
        for (j = 0; j < patternlen; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == patternlen) {
            printf("Pattern found at position %d.\n", i);
            found = 1;
        }
    }

    if (!found) {
        printf("Pattern not found in the text.\n");
    }
}

int main() {
    char text[100], pattern[100];
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);

    // Remove newline character from fgets
    text[strcspn(text, "\n")] = '\0';

    printf("Enter the pattern to search: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0';

    patternMatching(text, pattern);

    return 0;
}
