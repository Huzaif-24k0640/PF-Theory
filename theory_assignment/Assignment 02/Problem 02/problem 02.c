/*
* Name: Syed Huzaif 
*  Roll Number: 24K-0640
*  Problem 02
*/

#include<stdio.h>
#include<string.h>

int main(){

	int i, j = 0, k, n = 0, l;
	char ch[100];
	int an[j];
	printf("\n Slogan: ");
	fgets(ch,100,stdin);
	int c = strlen(ch);
	int arr[100][100];
	int sam[100][256] = {0};

	for(i = 0; i < c - 1;i++){
		if(ch[i] == ','){
			an[j] = n;
			j++;
			n = 0;
		}else{
		arr[j][n++] = ch[i];
		}//end if
	}//end for
	an[j] = n;
	j++;
	
	for(i = 0; i < j;i++){
		for(k = 0; k < an[i];k++){
		sam[i][arr[i][k]]++;
		}//end for
	}//end for
	
	for(k = 0; k < j;k++){
		printf("\n For (");
		for(i = 0; i < an[k];i++){
			printf("%c", arr[k][i]);
		}//end for
		printf("): ");
		printf("{");
		for(l = 0; l < an[k];l++){
			int ci = arr[k][l];
			if(sam[k][ci] > 0){
				printf("'%c': %d,", ci, sam[k][ci]);
				sam[k][ci] = -99;
			}//end if
		}//end for
		printf("}\n ");
	}//end for

	return 0;
}//end main
