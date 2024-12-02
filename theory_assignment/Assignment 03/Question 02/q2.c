// Question 2

#include<stdio.h>

struct player{
	int playerScore[12];
	char playerName[100];
	int totalScore;
} player;

int scoreCheck(int score){
	if(score >= 0 && score <= 6){
		return 1;
	}
	return 0;
}//end function score check

void playerInput(struct player arr[], int i){
	int j, total = 0;
	printf("\nPlayer[%d] name: ", i + 1);
	getchar();
	fgets(arr[i].playerName, 100, stdin);
	for(j = 0 ; j < 12; j++){
		printf("Ball[%d] score: ", j + 1);
		scanf("%d", &arr[i].playerScore[j]);
		int c = scoreCheck(arr[i].playerScore[j]);
		if(c == 0) 
			arr[i].playerScore[j] = 0;
		total += arr[i].playerScore[j]; 
	}//end for
	arr[i].totalScore = total;
}//end function player input

int checkWinner(struct player arr[]){
	if(arr[0].totalScore > arr[1].totalScore) 
		return 0;
	return 1;
}//end function check winner

void displayScore(struct player arr[]){
	int j;
	for(j = 0; j < 12; j++){
		printf("Player 1: %d Player 2: %d:", arr[0].playerScore[j] , arr[1].playerScore[j]);
		if(arr[0].playerScore[j] > arr[1].playerScore[j])
			printf("Player 1 played well at that ball\n");	
		else
			printf("Player 2 played well at that ball\n");
	}//end for
	if(arr[0].totalScore > arr[1].totalScore){
		printf("Player 1 scored %d runs more than player 2\n", arr[0].totalScore - arr[1].totalScore);	
	}else{
		printf("Player 2 scored %d runs more than player 1\n", arr[1].totalScore - arr[0].totalScore);	
	}//end if
}//end function display score

int main(){
	int i;
	struct player arr[2];
	for(i = 0; i < 2; i++)
		playerInput(arr, i);	
	int c = checkWinner(arr);
	printf("\nWinner: %s", arr[c].playerName);
	displayScore(arr);
	return 0;	
}//end main
