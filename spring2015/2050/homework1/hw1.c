/* Name: Pearse Hutson
 * Id: 14040826
 * Pawprint: pah9qd
 * Lab: E
 * Date: 2/19/15
 */

//Included Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Defined Constants
#define MAX_STRING_LEN 20

//Defined Structures
typedef struct {
	int year;
	char *make;
	char *model;
	int miles;
} Car;

//Function Prototypes
void fill_garage(Car **garage, char *cars, int *size);
int equals(Car *car, int year, char *make, char *model);
void drive_cars(Car *garage, int num_cars, char *driving_records);
void store_car_statistics(Car *garage, int num_cars, char *outFile);
void empty_garage(Car *garage, int num_cars);

int main(int argc, char **argv)
{
	if(argc != 4)
	{
		printf("Error: Invalid number of arguments\n");
		printf("Example: ./a.out input.txt update.txt output.txt");
	}

	int size;
	Car *garage;

	fill_garage(&garage, argv[1], &size);

	drive_cars(garage, size, argv[2]);

	store_car_statistics(garage, size, argv[3]);

	empty_garage(garage, size);

	return 0;
}

/************************************************
Function: fill_garage
	Parameters:	garage - A Pointer to the pointer, which points to the
						 head of an array of cars
				cars - The name of the input file
				size - A pointer to the variable where the size of the
					   array will be stored
	Return: None

	This function will dynamically create an array to hold the cars 
and read the contents of the input file into it. This is the only 
function which is allowed to use malloc.
************************************************/
void fill_garage(Car **garage, char *cars, int *size)
{
	FILE *carsFile = fopen(cars, "r");
	int i;
	
	fscanf(carsFile, "%d", size);

	*garage = malloc(sizeof(Car) * *size);

	for(i = 0; i < *size; i++)
	{
		(*garage)[i].make = malloc(sizeof(char) * MAX_STRING_LEN);
		(*garage)[i].model = malloc(sizeof(char) * MAX_STRING_LEN);
		fscanf( carsFile, "%d %s %s %d",
				&(*garage)[i].year,
				(*garage)[i].make,
				(*garage)[i].model,
				&(*garage)[i].miles);
	}

	fclose(carsFile);
	return;
}

/************************************************
Function: equals
	Parameters:	car - A pointer to a car struct
				year - A valid year
				make - A car's make
				model - A car's model
	Return: 1 if the car has the given year, make, and model
			0 otherwise

	This function will determine if the provided car has the 
specified year, make, and model.	
************************************************/
int equals(Car *car, int year, char *make, char *model)
{
	if((*car).year != year)
	{
		return 0;
	}
	else if(strcmp((*car).make, make) != 0)
	{
		return 0;
	}
	else if(strcmp((*car).model, model) != 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

/************************************************
Function: drive_cars
	Parameters:	garage - An array of cars
				num_cars - The length of the garage array
				driving_records - The name of a file containing driving records
	Return: None

	This function will read from the file specified by the driving_records 
parameter and on each line read in a year, make, model, and number of 
miles driven. It will then add the number of miles to the specified car. 
If the car does not exist, no action wil be taken.
************************************************/
void drive_cars(Car *garage, int num_cars, char *driving_records)
{
	FILE *drivingRecords = fopen(driving_records, "r");
	int i, j, numOfRecords, searchYear, additionalMiles;
	char searchMake[MAX_STRING_LEN], searchModel[MAX_STRING_LEN];

	fscanf(drivingRecords, "%d", &numOfRecords);

	for(i = 0; i < numOfRecords; i++)
	{
		fscanf(drivingRecords, "%d", &searchYear);
		fscanf(drivingRecords, "%s", searchMake);
		fscanf(drivingRecords, "%s", searchModel);
		fscanf(drivingRecords, "%d", &additionalMiles);

		for(j = 0; j < num_cars; j++)
		{
			if(equals(&garage[j], searchYear, searchMake, searchModel) == 1)
			{
				garage[j].miles += additionalMiles;
			}
		}
	}

	fclose(drivingRecords);
	return;
}

/************************************************
Function: store_car_statistics
	Parameters:	garage - An array of cars
				num_cars - The length of the garage array
				outFile - The name of the file to store the car information			
	Return: None

	This function will write the car statistics to the output file.
************************************************/
void store_car_statistics(Car *garage, int num_cars, char *outFile)
{
	FILE *carStorage = fopen(outFile, "w");
	int i;

	for(i = 0; i < num_cars; i++)
	{
		fprintf(carStorage, "The %d %s %s drove %d miles\n",
				garage[i].year,
				garage[i].make,
				garage[i].model,
				garage[i].miles);
	}

	fclose(carStorage);
	return;
}

/************************************************
Function: empty_garage
	Parameters:	garage - An array of cars
				num_cars - The length of the garage array		
	Return: None

	This function will free all malloc'ed memory
************************************************/
void empty_garage(Car *garage, int num_cars)
{
	int i;

	for(i = 0; i < num_cars; i++)
	{
		free(garage[i].make);
		free(garage[i].model);
	}

	free(garage);
	return;
}


