// Question 4

#include <stdio.h>
#include<stdlib.h>

void input(int **arr, int numEmployees, int numPeriods){   
	for(int i = 0; i < numEmployees; i++){
        	for(int j = 0; j < numPeriods; j++){
            printf("\nEmployee[%d] Period[%d] Rating: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        	}//end nested for
    	}//end for
    	return;
}//end function input

void displayPerformance(int** arr, int numEmployees,int numPeriods){
	for(int i = 0; i < numEmployees; i++){
        	for(int j = 0; j < numPeriods; j++)
          		printf("\nEmployee[%d] Period[%d]: %d \n", i + 1, j + 1, arr[i][j]);
        	printf("\n");
    	}//end for
}//end function display performance

int employeeOfYear(int** arr, int numEmployees, int numPeriods){
	int average = 0.0, s = 0.0;
    	int index;
    	for(int i = 0; i < numEmployees; i++){
        	for(int j = 0; j < numPeriods; j++)
        		s += arr[i][j];
        	if(i == 0 || average < s){
            		average = s;
            		s = 0;
            		index = i;
        	}//end if
    	}//end for
    	return index;
}//end function employee of the year

int periodOfTime(int** arr, int numEmployees, int numPeriods){
	float average = 0.0, s = 0.0;
    	int index;
    	for(int i = 0; i < numPeriods; i++){
        	for(int j = 0; j < numEmployees; j++)
          	s += arr[i][j];
        	if(i == 0 || average < s){
            		average = s;
            		s = 0;
            		index = i;
        	}//end if
    	}//end for
    	return index;
}//end function period of time

int worstEmployeeOfYear(int** arr, int numEmployees, int numPeriods){
	float average = 100.0, s = 0;
    	int index;
    	for(int i = 0; i < numEmployees; i++){
        	for(int j = 0; j < numPeriods; j++)
          	s += arr[i][j];
        	if(i == 0 || average > s){
            		average = s;
            		s = 0;
            		index = i;
        	}//end if
    	}//end for
    	return index;
}//end function worst employee of the year

int main() {
	int **arr;
    	int numEmployees;
    	int numPeriods;
    	printf("\nNumber of employees: ");
    	scanf("%d", &numEmployees);
    	printf("\nEvaluation period: ");
    	scanf("%d", &numPeriods);
   
    	arr = (int **)malloc(sizeof(int *) * numEmployees);
    	for(int i = 0; i < numEmployees; i++)
        	arr[i] = (int *)malloc(sizeof(int) * numPeriods);
   
    	input(arr, numEmployees, numPeriods);
   
    	displayPerformance(arr, numEmployees, numPeriods);
   
    	int c = employeeOfYear(arr, numEmployees, numPeriods);
    	printf("\nEmployee of year: %d\n", c+1);
   
    	int d = periodOfTime(arr, numEmployees, numPeriods);
    	printf("\nTime period: %d\n", d + 1);
   
    	int e = worstEmployeeOfYear(arr, numEmployees, numPeriods);
    	printf("\nWorst employee of year: %d\n", e+1);
   
    	for(int i = 0; i < numEmployees; i++)
    		free(arr[i]);
    	free(arr);
    	return 0;
}//end main
