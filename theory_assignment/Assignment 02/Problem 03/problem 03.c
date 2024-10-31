#include<stdio.h>
#include<string.h>

int main(){

	char ch[1000];
	int n=0,l=0,k;
	printf("\n enter any string: ");
	fgets(ch,1000,stdin);
	int c = strlen(ch);
	int i, j, arr[100][100], an[100];

	for(i = 0; i < c - 1; i++){
		if(ch[i] == ' '){
			
		}
		else if(ch[i] == ','){
			an[n] = l;
			n++;
			l = 0;
		}
		else{
		arr[n][++l] = ch[i];
		}//end if
	}//end for

	an[n]=l;
	n++;
	printf("\n ");

	for(k = 0; k < n; k++){
		for(j = 1; j <= an[k]; j++){
		        printf("%c", arr[k][j]);
				if(arr[k][j] == arr[k][j+1]){
				    while(arr[k][j] == arr[k][j+1]){
				        j++;
				    }//end while
				}//end if
		}//end nested for
	}//end for
	printf("\n ");

	return 0;
}//end main
