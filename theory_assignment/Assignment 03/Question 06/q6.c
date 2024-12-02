// Question 6

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct weatherForecast{
	int temperature;
	int rainfall;
	int windPatterns;
}forecast;

typedef struct crops{
	char cropType[40];
	char growthStage[45];
	int expectedYield;
	forecast * forecast;
} crop;

typedef struct equipment{
	char operationalStatus[40];
	int fuelLevels; 
	char activitySchedules[40];
} equipment;

typedef struct senior{
	int nutrients;
	int pHLevels;
	int pestActivity;
} senior;

typedef struct fields{
	int GPSCoordinates;
	int soilHealthMetrics;
	int moistureLevels;
	equipment * equipments;
	crop * crops;
	senior * seniors;
	int numofequipments;
	int numofcrops;
	int numofsenior;
} field;

typedef struct regionalHubs{
	int yieldPrediction;
	char resource[40];
	char distribution[40];
	char emergencyResponsePlans[100];
	field * fields;
} regionalHub;
;
typedef struct analyticsServer{
	regionalHub * hubs;
	int numofhubs;
} analyticsServer;

void addcrops(crop * crop, int numofcrops){
	for (int i = 0; i < numofcrops; i++) {
		printf("Enter type of crop(str): ");
		scanf("%s", crop[i].cropType);
		printf("Enter growth stage(str): ");
		scanf(" %s", crop[i].growthStage);
		printf("Enter type expected yield(int): ");
		scanf("%d", &crop[i].expectedYield);
    		crop[i].forecast = (forecast *)malloc(sizeof(forecast));
    		printf("Enter temperature(int): ");
		scanf("%d", &crop[i].forecast->temperature);
		printf("Enter Rainfall(int): ");
		scanf("%d", &crop[i].forecast->rainfall);
		printf("Enter Wind Pattern(int): ");
		scanf("%d", &crop[i].forecast->windPatterns);
	}//end for
	return ;	
}//end function add crops

void addequipment(equipment * equipment, int numofequipment){
	for(int i = 0; i < numofequipment; i++){
		printf("Enter operational status(str): ");
		scanf("%s", equipment[i].operationalStatus);
		printf("Enter fuel level(int): ");
		scanf("%d", &equipment[i].fuelLevels);
		printf("Enter activity schedules(str): ");
		scanf("%s", equipment[i].activitySchedules);
	}//end for
	return ;
}//end function add equipment

void addsenior(senior * seniors,int numofsenior){
	for(int i = 0; i < numofsenior; i++){
		printf("Enter Nutrients(int): ");
		scanf("%d", &seniors[i].nutrients);
		printf("Enter pH Level(int): ");
		scanf("%d", &seniors[i].pHLevels);
		printf("Enter Pest activity(int): ");
		scanf("%d", &seniors[i].pestActivity);
	}//end for
	return ;
}//end function senior

void displayfield(field  fe){
	printf("\n\nGPS coordinates: %d\n", fe.GPSCoordinates);
	printf("soil health metrics: %d\n", fe.soilHealthMetrics);
	printf("moisture levels: %d\n",fe.moistureLevels);
	for (int i = 0; i < fe.numofcrops; i++) {
		printf("\nType of crop: %s\n", fe.crops[i].cropType);
		printf("Growth stage: %s\n", fe.crops[i].growthStage);
		printf("Type expected yield: %d\n", fe.crops[i].expectedYield);
    		printf("Temperature: %d\n", fe.crops[i].forecast->temperature);
		printf("Rainfall: %d\n", fe.crops[i].forecast->rainfall);
		printf("Wind Pattern: %d\n", fe.crops[i].forecast->windPatterns);
	}//end for
	
	for(int i = 0; i < fe.numofequipments; i++){
		printf("\nOperational status: %s\n", fe.equipments[i].operationalStatus);
		printf("Fuel level: %d\n", fe.equipments[i].fuelLevels);
		printf("Activity schedules: %s\n", fe.equipments[i].activitySchedules );
	}//end for
	
	for(int i = 0; i < fe.numofsenior; i++){
		printf("\nNutrients: %d\n", fe.seniors[i].nutrients);
		printf("PH Level: %d\n", fe.seniors[i].pHLevels);
		printf("Pest activity: %d\n", fe.seniors[i].pestActivity);
	}//end for
	return ;
}//end function display field

int main(){
	field fe;
	printf("\nEnter GPS coordinates(int): ");
	scanf("%d", &fe.GPSCoordinates);
	printf("Enter soil health metrics(int): ");
	scanf("%d", &fe.soilHealthMetrics);
	printf("Enter moisture levels(int): ");
	scanf("%d", &fe.moistureLevels);
	printf("Enter number of crops(int): ");
	scanf("%d", &fe.numofcrops);
	
	fe.crops=(crop *)malloc(sizeof(crop ) * fe.numofcrops);
	addcrops(fe.crops,fe.numofcrops);
	
	printf("Enter the number of  equipment: ");
	scanf("%d", &fe.numofequipments);

	fe.equipments = (equipment *)malloc(sizeof(equipment) * fe.numofequipments);
	addequipment(fe.equipments, fe.numofequipments);
	
	printf("Enter the number of Num of senior: ");
	scanf("%d", &fe.numofsenior);

	fe.seniors=(senior *)malloc(sizeof(senior) * fe.numofsenior);
	addsenior(fe.seniors,fe.numofsenior);

	displayfield(fe);
	for (int i = 0; i < fe.numofcrops; i++)
        	free(fe.crops[i].forecast);
    	free(fe.crops);
    	free(fe.equipments);
    	free(fe.seniors);
	return 0;
}//end main
