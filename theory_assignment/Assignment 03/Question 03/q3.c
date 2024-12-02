// Question 3

#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int validCheck(char *ptr, int c){
    	int i, found = 1, dot = 0;
    	for(i = 0; i < c; i++){
        	if(ptr[i] == '@')
            		found--;
        	if(ptr[i] == '.')
			dot++;
    	}//end for
    	if(found == 0 && dot >= 1)
        	return 1;
    	return 0;
}//end function valid check

int main() {
    	char str[100];
	int i;
    	fgets(str, 100, stdin);
    	int c = strlen(str);
    	char *ptr = (char *)malloc(sizeof(char)* (c-1));
    
    	for(i = 0; i < c - 1; i++)
    	    ptr[i] = str[i];
    
    	int check = validCheck(ptr, c-1);
    	if(check == 1) 
		printf("Valid Email");
    	else 
		printf("Invalid Email");
    
    	free(ptr);

    	return 0;
}//end main
