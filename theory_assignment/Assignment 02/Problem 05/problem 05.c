#include<stdio.h>
int main(){
    	int n;
	printf("\n enter array size: ");
    	scanf("%d", &n);
    	int arr[n], an[n];

    	for(int i = 0; i < n; i++){
		printf("\n enter value %d: ", i);
    		scanf("%d", &arr[i]);
    	}//end for

    	int max = arr[0];

    	for(int i = 0; i < n; i++){
        	if(max < arr[i]){
            	max = arr[i];
        	}//end if
    	}//end for

    	for(int i = 0; i < n; i++){
        	printf("\n value %d: ", i+1);
        	for(int j = 0; j < arr[i]; j++){
            		printf("*");
        	}//end nested for
	        an[i] = arr[i];
        	printf(" \n");
    	}//end for
	printf("\n");

 	for(int i = max; i > 0; i--){
        	for(int j = 0; j < n; j++){
            		if(arr[j] == i){
                		arr[j]--;
                		printf(" *");
            		}else{
                		printf("  ");
            		}//end if
        	}//end nested for
        	printf(" \n");
    	}//end for

    	for(int i = 0; i < n; i++){
        	printf(" %d",an[i]);
    	}//end for
	printf("\n");

}//end main
