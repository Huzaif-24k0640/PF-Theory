// Question 5

#include <stdio.h>
#include <stdlib.h>

void addSupplies(char **arr, int numOfSpecies, int numOfSupplies, int isNew) {
    	if (isNew == 0) {
        	for (int i = 0; i < numOfSpecies; i++) {
            		for (int j = 0; j < numOfSupplies; j++) {
                		printf("add supply (F for food, T for toys, B for beddings) for species[%d], supply[%d]: ", i + 1, j + 1);
                		scanf(" %c", &arr[i][j]);
            		}//end neested for
        	}//end for
    	} else {
        	for (int j = 0; j < numOfSupplies; j++) {
            		printf("Enter the supply FIRST LETTER (e.g., F for Food) for new species, supply %d: ", j + 1);
            		scanf(" %c", &arr[numOfSpecies][j]);
        	}//end for
    	}//end if else
	return;
}//end function add supplies

void updateSupplies(char **arr, int numOfSpecies, int numOfSupplies, int species) {
    	for (int j = 0; j < numOfSupplies; j++) {
        	printf("update supply (F for food, T for toys, B for beddings) for species[%d], supply[%d]: ", species + 1, j + 1);
        	scanf(" %c", &arr[species][j]);
    	}//end for
	return;
}//end function update supplies

void removeData(char **arr, int *numOfSpecies, int species) {
    	free(arr[species]);
    	for (int i = species; i < *numOfSpecies - 1; i++)
        	arr[i] = arr[i + 1];
    	(*numOfSpecies)--;
	return;
}//end function remove data

void display(char **arr, int numOfSpecies, int numOfSupplies) {
	for (int i = 0; i < numOfSpecies; i++) {
        	printf("Species %d supplies: ", i + 1);
        	for (int j = 0; j < numOfSupplies; j++)
            		printf("%c ", arr[i][j]);
        	printf("\n");
    	}//end for
	return;
}//end function display

int main() {
	char **arr = NULL;
    	int numOfSpecies = 0, numOfSupplies = 0;
    	int option, species;

    	do {
        	printf("\n----------Menu----------\n");
        	printf("1. Add supplies\n");
        	printf("2. Update supplies\n");
        	printf("3. Remove species\n");
        	printf("4. Display all supplies\n");
        	printf("5. Exit\n");
        	printf("Enter your choice: ");
        	scanf("%d", &option);

        	switch (option) {
            		case 1:
                		if (numOfSpecies == 0) {
                    			printf("Enter the number of species: ");
                    			scanf("%d", &numOfSpecies);
                    			printf("Enter the number of supplies per species: ");
                    			scanf("%d", &numOfSupplies);

                    			arr = (char **)malloc(numOfSpecies * sizeof(char *));
                    			for (int i = 0; i < numOfSpecies; i++)
                        			arr[i] = (char *)malloc(numOfSupplies * sizeof(char));
                    			addSupplies(arr, numOfSpecies, numOfSupplies, 0);
                		} else {
                    			arr = (char **)realloc(arr, (numOfSpecies + 1) * sizeof(char *));
                    			arr[numOfSpecies] = (char *)malloc(numOfSupplies * sizeof(char));
                    			addSupplies(arr, numOfSpecies, numOfSupplies, 1);
                    			numOfSpecies++;
                		}//end if else
                		break;

            		case 2:
                		if (numOfSpecies == 0)
                    			printf("No species to update. Please add supplies first.\n");
                		else {
                    			printf("Enter the species number to update (1 to %d): ", numOfSpecies);
                    			scanf("%d", &species);
				}//end if else
                    		if (species < 1 || species > numOfSpecies)
                        		printf("Invalid species number.\n");
                    		else
                        		updateSupplies(arr, numOfSpecies, numOfSupplies, species - 1);
                		break;
			case 3:
                		if (numOfSpecies == 0)
                    			printf("No species to remove. Please add supplies first.\n");
                		else {
                    			printf("Enter the species number to remove (1 to %d): ", numOfSpecies);
                    			scanf("%d", &species);
                    			if (species < 1 || species > numOfSpecies)
                        			printf("Invalid species number.\n");
                    			else {
                        			removeData(arr, &numOfSpecies, species - 1);
                        			printf("Species %d removed.\n", species);
                    			}
                		}//end if else
                		break;
            		case 4:
                		if (numOfSpecies == 0)
                    			printf("No data to display. Please add supplies first.\n");
                		else
                    			display(arr, numOfSpecies, numOfSupplies);
                		break;
            		case 5:
                		printf("Exiting program.\n");
                		break;
            		default:
                		printf("Invalid option. Please try again.\n");
		}//end switch
	} while (option != 5);


    	for (int i = 0; i < numOfSpecies; i++)
        	free(arr[i]);
    	
	free(arr);
	return 0;
}//end main
