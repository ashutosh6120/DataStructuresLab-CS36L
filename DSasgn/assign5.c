// Using pointers, write a function that receives a charecter string and a charecter as an argument
// and deletes all the occurences of this charecter in the string. The function should return the
// corrected string with no holes.

#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING 100

char* rem_char(char*, char);

int main() {
    char str[MAX_STRING], c;
    printf("Enter character to be removed from string: ");
    scanf("%c", &c);
    printf("Enter string: ");
    scanf("%s", str);

    char* result_str = rem_char(str, c);
    printf("The string after removing %c is : %s\n", c, result_str);
    free(result_str);

    return 0;
}

char* rem_char(char* str, char c) {
    char* nstr = (char*)malloc(MAX_STRING* sizeof(char));
    int i, j;
    for (i = 0, j = 0; *(str + i) != '\0'; i++) {
        if (str[i] == c)
            continue;
        *(nstr + j) = *(str + i);
        j++;
    }
    *(nstr + j) = '\0';
    return nstr;
}
