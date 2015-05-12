/* -----------------------------------------------
Student: 		  Pearse Hutson
Student ID: 	  14040826
Student Pawpring: pah9qd
Lab Code: 		  Monday
Assignment: Lab2
	lab2.c - Using structs. Program reads a list 
	of points from a file and performs some 
	operations on them
----------------------------------------------- */

// Included Libraries
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define Structs
struct point {
	int x;
	int y;
	int errorCode;
};

//Function Prototypes
struct point* read_file(char *file_name, int size);
double distance(struct point first, struct point second);
struct point* sort(struct point *array, int size);
void print_points(struct point *array, int size, 
		struct point intersectPoint);
struct point intersection(struct point p1, struct point p2, 
		struct point p3, struct point p4);

/* ===============================================
Function: main 
	main will take the number of points to be read as
well as the name of the input file as command line
arguments. It will then call read_file, sort the array
and print it out.
=============================================== */
int main(int argc, char **argv)
{
	// Initialize and check command line arguments
	if(argc != 3)
	{
		printf("Error: Invalid command line arguments\n");
		printf("Example:  \"./a.out 5 input.txt\"\n");
		return 0;
	}
	int size = atoi(argv[1]);
	char *file_name = argv[2];

	// Initalize local variables
	struct point *pointArray;
	struct point intersectPoint;

	// Call the read_file function to read data from the input file
	pointArray = read_file(file_name, size);
	if(pointArray == NULL)
	{
		printf("Error: Invalid input file\n");
		return 0;
	}

	// Call the sort function to sort the data in the array
	pointArray = sort(pointArray, size);

	// Call the intersection function
	intersectPoint = intersection(*pointArray, *(pointArray + 1),
			*(pointArray + 2), *(pointArray + 3));

	// Call the print_points function to print out the data
	// from the array
	print_points(pointArray, size, intersectPoint);

	
	// Terminate program
	return 0;
}

/* ===============================================
Function: read_file
	Parameter: file_name - The name of a file containing points
	Parameter: size - the number of points in the file
	Return: A pointer to an array the points from the input file

	This function will dynamically create an array to hold the 
points and read the ontents of the input file into it
=============================================== */
struct point* read_file(char *file_name, int size)
{
	int i;
	struct point *pointArray = malloc(sizeof(struct point) * size);

	FILE *file = fopen(file_name, "r");
	if(file == NULL)
	{		
		return NULL;
	}
	
	for(i = 0; i < size; i++)
	{
		fscanf( file, "%d %d", 
				&((pointArray + i)->x), &((pointArray + i)->y));
	}

	return pointArray;
}

/* ===============================================
Function: distance
	Parameter: first - A point
	Parameter: second - Another point
	Return: The distance between two points

	This function will return the distance between two
points based on the formula:
sqrt((x1 - x2)^2 + (y1 - y2)^2)
=============================================== */
double distance(struct point first, struct point second)
{
	return  sqrt(
			pow(first.x - second.x, 2) + 
			pow(first.y - second.y, 2));
}

/* ===============================================
Function: sort
	Parameter: array - An array of points
	Parameter: size - The size of the array
	Return: A pointer to the sorted array

	This function will sort points based on their 
distance from the origin (0,0).
=============================================== */
struct point* sort(struct point *array, int size)
{
	int i;
	int j;
	struct point pointHolder = {0, 0};
	struct point origin = {0, 0};

	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size - 1; j++)
		{
			if(distance(*(array + j), origin) > 
					distance(*(array + j + 1), origin))
			{
				pointHolder.x = (array + j)->x;
				pointHolder.y = (array + j)->y;
				(array + j)->x = (array + j + 1)->x;
				(array + j)->y = (array + j + 1)->y;
				(array + j + 1)->x = pointHolder.x;
				(array + j + 1)->y = pointHolder.y;
			}
		}
	}

	return array;
}

/* ===============================================
Function: print_points
	Parameter: array - An array of points
	Parameter: size - The size of the array
	Parameter: intersectPoint - The point of intersection
	Return: None

	This function will print out al of the points
in the array, as well as the point of intersection 
between two lines.
=============================================== */
void print_points(struct point *array, int size, 
		struct point intersectPoint)
{
	int i;

	printf("Points sorted based on distance from the origin\n");

	for(i = 0; i < size; i++)
	{
		printf("(%d,%d)\n", (array + i)->x, (array + i)->y);
	}

	printf("Bonus\n");
	if(intersectPoint.errorCode == -1)
	{
		printf("No intersection point - Parallel Lines\n");
	}
	else
	{
		printf("(%d,%d)\n", intersectPoint.x, intersectPoint.y);
	}

	return;
}

/* ===============================================
Function: intersection
	Parameter: p1 - A distinct point in line L1
	Parameter: p2 - A distinct point in line L1
	Parameter: p3 - A distinct point in line L2
	Parameter: p4 - A distinct point in line L2	
	Return: A point representing the intersection of the two lines

	This function will find the intersection of two lines
based on four points.
=============================================== */
struct point intersection(struct point p1, struct point p2, 
		struct point p3, struct point p4)
{
	double xPart1, xPart2, xPart3, xPart4;
	double yPart1, yPart2, yPart3, yPart4;
	double slope1, slope2;
	struct point pntOfIntersect;

	// Does not allow slope calculations of vertical lines
	if(p2.x - p1.x != 0 || p4.x - p3.x != 0)
	{
		slope1 = (p2.y - p1.y) / (p2.x - p1.x);
		slope2 = (p4.y - p3.y) / (p4.x - p3.x);
	
	
		//Return an error code if the lines do not intersect
		if(slope1 == slope2)
		{
			pntOfIntersect.errorCode = -1;
			return pntOfIntersect;
		}
	}
	// If both are vertical lines, return error code that they
	// do not intersect
	else if(p2.x - p1.x == 0 && p4.x - p3.x == 0)
	{
		pntOfIntersect.errorCode = -1;
		return pntOfIntersect;
	}

	xPart1 = ((p1.x * p2.y) - (p1.y * p2.x)) * (p3.x - p4.x);
	xPart2 = (p1.x - p2.x) * ((p3.x * p4.y) - (p3.y * p4.x));
	xPart3 = (p1.x - p2.x) * (p3.y - p4.y);
	xPart4 = (p1.y - p2.y) * (p3.x - p4.x);
	pntOfIntersect.x = (xPart1 - xPart2) / (xPart3 - xPart4);

	yPart1 = ((p1.x * p2.y) - (p1.y * p2.x)) * (p3.y - p4.y);
	yPart2 = (p1.y - p2.y) * ((p3.x * p4.y) - (p3.y * p4.x));
	yPart3 = (p1.x - p2.x) * (p3.y - p4.y);
	yPart4 = (p1.y - p2.y) * (p3.x - p4.x);
	pntOfIntersect.y = (yPart1 - yPart2) / (yPart3 - yPart4);

	return pntOfIntersect;
}
