#include <stdio.h>

int main() {
    int x, z = 0;
    
    printf("\n Enter a positive integer: ");
    scanf("%d", &x);
    
    if (x < 0) {
        printf(" Please enter a positive integer\n");
        return 1;
    }

    int first;
    int n;
    
    n = x % 4; 
    x = x - n; 
    first = x / 4; 

    printf("\n To win pick: ");	

    if (first % 2 != 0) {
        if (n == 2) {
            printf("one\n");
	    z = 1;
        } else if (n == 3) {
            printf("two\n");
	    z = 2;
        } else if (n == 0) {
            printf("four\n");
	    z = 4;
        } else {
            printf("impossible to win\n");
	    z = -1;
        }
    } else {
        if (n == 1) {
            printf("four\n");
	    z = 4;
        } else if (n == 2) {
            printf("three\n");
	    z = 3;
        } else if (n == 3) {
            printf("two\n");
	    z = 2;
        } else if (n == 0) { 
            printf("one\n");
	    z = 1;
        } else {
            printf("impossible to win\n");
	    z = -1;
        }
    }
    printf("\n Pick: %d \n", z);
    return 0;
}
