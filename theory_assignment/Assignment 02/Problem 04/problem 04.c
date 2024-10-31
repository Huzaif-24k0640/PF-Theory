#include <stdio.h>
#include <string.h>

int areAnagrams(char str1[], char str2[]) {
	int count[26] = {0}; 

	for(int i = 0; str1[i] != '\0'; i++) {
        	count[str1[i] - 'a']++; 
        }
    
    	for (int i = 0; str2[i] != '\0'; i++) {
        	count[str2[i] - 'a']--;  
    	}
    	for (int i = 0; i < 26; i++) {
        	if (count[i] != 0) return 0;
    	}
    
    return 1; 
}//end function areAnagrams

void groupAnagrams(char transactions[1000][100]) {
    	int used[1000] = {0}; 
    
    	for (int i = 0; i < 6; i++) {
        	if (used[i]) {
			continue;
		}//end if
        	printf("[");
        	for (int j = i; j < 6; j++) {
            		if (!used[j] && areAnagrams(transactions[i], transactions[j])) {
                		printf("'%s'", transactions[j]);
                		used[j] = 1; 
            		}//end if
      		}//end nested for
        	printf("] ");
    	}//end for
}//end groupAnagrams

int main() {
    	char transactions[1000][100];
    
	for (int i = 0; i < 6; i++) {
		printf("\n enter the transaction[%d]: ", i);
        	scanf("%s", transactions[i]);
    	}//end for

	printf("\n Grouped anagrams: ");
	groupAnagrams(transactions);
	printf("\n");
    
	return 0;
}//end main
