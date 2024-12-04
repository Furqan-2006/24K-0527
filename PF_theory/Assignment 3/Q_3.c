#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateEmail(char* email) {
    int atCount = 0;
    char* atPosition = NULL;

    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            atCount++;
            if (atCount == 1) {
                atPosition = &email[i];
            }
        }
    }

    if (atCount != 1) {
        return 0; 
    }

    if (atPosition != NULL) {
        char* dotPosition = strchr(atPosition, '.');
        if (dotPosition == NULL || dotPosition == atPosition + 1) {
            return 0; 
        }
    }

    return 1; 
}

int main() {
    char* email = (char*)malloc(256 * sizeof(char)); // Allocate memory for email
    if (email == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter an email address: ");
    fgets(email, 256, stdin);

    size_t len = strlen(email);
    if (len > 0 && email[len - 1] == '\n') {
        email[len - 1] = '\0';
    }

    if (validateEmail(email)) {
        printf("The email address is valid.\n");
    } else {
        printf("The email address is invalid.\n");
    }

    free(email);
    return 0;
}
