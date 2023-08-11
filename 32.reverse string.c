#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
	int i;
    int length = strlen(str);
    for ( i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main() {
    char input[100];
    
    printf("Enter a string: ");
    scanf("%s", input);
    
    printf("Reverse of the string: ");
    reverseString(input);
    
    return 0;
}

