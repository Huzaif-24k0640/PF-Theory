/*
* Name: Syed Huzaif 
*  Roll Number: 24K-0640
*  Problem 01
*/

#include<stdio.h>
int main(){
	int i, min, previous_min;
	int arr[5] = {0};

	printf("\n Input 5 elements in the array (value must be <9999): ");
	for(i = 0; i < 5; i++){
		printf("\n enter element[%d]: ", i);
		scanf("%d", &arr[i]);
	}//end for

	min = arr[0];
	previous_min = arr[1];
	for(i = 4; i > -1 ; i--){
		if(min > arr[i]){
			previous_min = min;
			min = arr[i];
		}
		else if(previous_min > arr[i] && arr[i] != min){
			previous_min = arr[i];
		}//end if
	}//end for
	printf("\n The Second smallest element in the array is:%d \n", previous_min);
}//end main
