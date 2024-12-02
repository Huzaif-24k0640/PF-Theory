// Question 1

#include<stdio.h>

struct employees {
    int employeeCode;
    char employeeName[60];
    int dateOfJoining[3];
} arr[4];

int main(){
	int i;
    
    	for (i = 0; i < 4; i++){
        	printf("\nEmployee[%d] code: ", i+1);
        	scanf("%d", &arr[i].employeeCode);
       		printf("Employee[%d] name: ", i+1);
        	getchar();
        	fgets(arr[i].employeeName,60,stdin);
        	printf("Employee[%d] joining date[date month year]: ", i+1);
        	scanf("%d %d %d", &arr[i].dateOfJoining[0], &arr[i].dateOfJoining[1], &arr[i].dateOfJoining[2]);
    	}//end for

    	int currentdate[3],count=0;
    	printf("\nCurrent date[date month year]: ");
    	scanf("%d %d %d",&currentdate[0],&currentdate[1],&currentdate[2]);
    	for(i = 0; i < 4; i++){
        	int years = currentdate[2] - arr[i].dateOfJoining[2];
        	int months = currentdate[1] - arr[i].dateOfJoining[1];
        	int days = currentdate[0] - arr[i].dateOfJoining[0];
		if (years > 3 || (years == 3 && months > 0) || (years == 3 && months == 0 && days >= 0)){
    			printf("\nCode: %d\nName: %sJoining date: %d %d %d\n",  arr[i].employeeCode, arr[i].employeeName, arr[i].dateOfJoining[0], arr[i].dateOfJoining[1], arr[i].dateOfJoining[2]);
    			count++;
			}//end if
	}//end for

	printf("\nTotal employees having tenure of three years: %d\n", count);
}//end main
