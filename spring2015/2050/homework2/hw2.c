/* Name: Pearse Hutson
 * ID: 14040826
 * PawPrint: pah9qd
 * Assignment: Homework 2
 * Date: 3/13/2015
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct points {
    float axis[2];
    int id;
} Points;

typedef enum {
    SortById,
    SortByXAxis
} SortType;

//Function Prototypes
Points* fill_array(char *filename, int *length);
void print_set(Points *set, int number_of_points);
void mergesort(Points *set, int low, int high, int number_of_points,
               SortType sort);
void merge(Points *set, int low, int middle, int high,
           int number_of_points, SortType sort);
int binary_search(Points *set, int number_of_points, int ID_Target);
void range_query_on_x(Points *set, int number_of_points, float mean,
                      float std_dev);

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Error: Invalid arguments\n");
        printf("Expected input: ./a.out <input file>\n");
        return 0;
    }

    int length, searchFor, searchResult;
    float rangeX, rangeDist;
    Points *points_array;

    //Read in a file of points, each point has an ID, an x and y coordinate
    //(axis[0] and axis[1] respectively)
    points_array = fill_array(argv[1], &length);

    if(points_array == NULL)
        return 0;

    printf("Points Array:\n");
    print_set(points_array, length);

    //mergesort on IDs
    mergesort(points_array, 0, length - 1, length, SortById);

    printf("\n\nPoints Array after Sort by Id:\n");
    print_set(points_array, length);

    //binary search for an ID
    printf("What ID to search for?\n");
    scanf("%d", &searchFor);
    searchResult = binary_search(points_array, length, searchFor);

    if(searchResult == -1)
        printf("ID not found");
    else
    {
        printf("%d %f %f",
                points_array[searchResult].id,
                points_array[searchResult].axis[0],
                points_array[searchResult].axis[1]);
    }

    //mergesort again on the X axis(axis[0])
    mergesort(points_array, 0, length - 1, length, SortByXAxis);

    printf("\n\nSorting on X axis..\n");
    print_set(points_array, length);

    //perform a range query on X with user input of a point X and a
    //distance from that point X
    printf("Enter a X value and a distance from the X value you would like to "
           "return. E.g. <3.433 5.3432>\n");
    scanf("%f %f", &rangeX, &rangeDist);
    if(rangeDist < 0)
        rangeDist = -rangeDist;

    range_query_on_x(points_array, length, rangeX, rangeDist);

    free (points_array);
    return 0;
}

/************************************************
                fill_Array
Parameters:
    filename: The name of the input file
    length: A pointer to the variable where the
            length of the array should be held
Return: An allocated and filled array of points

Description: This function opens the user
    specified file and fills an array based on
    the data in the file.
************************************************/
Points* fill_array(char *filename, int *length)
{
    int i;
    Points *points_array;

    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Invalid File. Aborting Program\n");
        return NULL;
    }

    fscanf(fp, "%d", length);
    points_array = malloc(sizeof(Points) * *length);

    for(i = 0; i < *length; i++)
    {
        fscanf( fp, "%d %f %f", &points_array[i].id,
                &points_array[i].axis[0],
                &points_array[i].axis[1]);
    }

    fclose(fp);
    return points_array;
}

/************************************************
                print_set
Parameters:
    set : an array of points
    number_of_points : the length of the array
Return: None

Description: This function prints all of the
    points on the array. Each point is printed on
    it's own line. Points are printed in the
    order they appear in the array.
************************************************/
void print_set(Points *set, int number_of_points)
{
    int i;

    for(i = 0; i < number_of_points; i++)
    {
        printf("%d %f %f\n", set[i].id, set[i].axis[0], set[i].axis[1]);
    }
}

/************************************************
                mergesort
Parameters:
    set : an array of points
    low : the lowest valid index to sort
    high: the highest valid index to sort
    number_of_points: the length of the array
    sort: designates whether to sort on the Id
          or axis[0] (X)
Return: None

Description: This functin divides set in half
    and sends a copy of each half to itself
    recursively. Will return up the stack when
    the number_of_points reaches 1 or less.
    Set sorted half is merged together by
    calling merge.
************************************************/
void mergesort(Points *set, int low, int high,
               int number_of_points, SortType sort)
{
    if(number_of_points <= 1)
        return;

    int middle = (low + high) / 2,
        numOfFirst = (middle - low) + 1,
        numOfSecond = number_of_points - numOfFirst;

    mergesort(set, low, middle, numOfFirst, sort);
    mergesort(set, (middle + 1), high, numOfSecond, sort);

    merge(set, low, middle, high, number_of_points, sort);
}

/************************************************
                    merge
Parameters:
    set : an array of points
    low: the lowest index to merge
    middle: the separating point between the two
            sorted arrays
    high: the highest index to merge
    number_of_points: the number of points in the
                      entire array
    sort: designates whether to merge on the Id
          or axis[0] (X)
Return: None

Description: This function will copy all
    elements from the two arrays (both stored in
    set) into a helper array, and then copy the
    smaller element from each half back into set.
    Eventually one array will run out of elements
    before the other and at that point all points
    in the remaining array should be copied back
    into set.
************************************************/
void merge(Points *set, int low, int middle, int high,
           int number_of_points, SortType sort)
{
    int i = 0,
        arrayOneCurrent = 0,
        arrayTwoCurrent = 0,
        mergeCounter = low,
        numOfFirst = (middle - low) + 1,
        numOfSecond = number_of_points - numOfFirst;
    Points *helperArrayOne, *helperArrayTwo;

    helperArrayOne = malloc(sizeof(Points) * (middle - low + 1));
    helperArrayTwo = malloc(sizeof(Points) * (high - middle));

    for(i = 0; i < numOfFirst; i++)
        helperArrayOne[i] = set[i + low];

    for(i = 0; i < numOfSecond; i++)
        helperArrayTwo[i] = set[i + middle + 1];

    //Sort by id
    if(sort == SortById)
    {
        while(arrayOneCurrent < numOfFirst && arrayTwoCurrent < numOfSecond)
        {
            if(helperArrayOne[arrayOneCurrent].id <= helperArrayTwo[arrayTwoCurrent].id)
                set[mergeCounter++] = helperArrayOne[arrayOneCurrent++];
            else if(helperArrayOne[arrayOneCurrent].id > helperArrayTwo[arrayTwoCurrent].id)
                set[mergeCounter++] = helperArrayTwo[arrayTwoCurrent++];
        }
    }
    //Sort by X Axis
    else if(sort == SortByXAxis)
    {
        while(arrayOneCurrent < numOfFirst && arrayTwoCurrent < numOfSecond)
        {
            if(helperArrayOne[arrayOneCurrent].axis[0] <= helperArrayTwo[arrayTwoCurrent].axis[0])
                set[mergeCounter++] = helperArrayOne[arrayOneCurrent++];
            else if(helperArrayOne[arrayOneCurrent].axis[0] > helperArrayTwo[arrayTwoCurrent].axis[0])
                set[mergeCounter++] = helperArrayTwo[arrayTwoCurrent++];
        }
    }

    while(arrayOneCurrent < numOfFirst)
        set[mergeCounter++] = helperArrayOne[arrayOneCurrent++];
    while(arrayTwoCurrent < numOfSecond)
        set[mergeCounter++] = helperArrayTwo[arrayTwoCurrent++];

    free(helperArrayOne);
    free(helperArrayTwo);
}

/************************************************
                binary_search
Parameters:
    set: an array of points sorted on their ID’s
    number_of_points: the length of the array
    ID_Target: the ID to search for
Return: The index of the target ID if found,
        -1 otherwise.

Description: This function will search for a user
    specified target ID using a modified
    binary_search and will return the index
    number of the found ID.
************************************************/
int binary_search(Points *set, int number_of_points, int ID_Target)
{
    int lowIndex = 0,
        highIndex = number_of_points - 1,
        middleIndex = (highIndex + lowIndex) / 2;

    while(set[middleIndex].id != ID_Target)
    {

        if(ID_Target < set[middleIndex].id)
            highIndex = middleIndex - 1;
        else if(ID_Target > set[middleIndex].id)
            lowIndex = middleIndex + 1;

        if(lowIndex > highIndex)
            return -1;

        middleIndex = (highIndex + lowIndex) / 2;
    }

    return middleIndex;
}

/************************************************
                range_query_on_x
Parameters:
    set: an array of points sorted on axis[0] (X)
    number_of_points: the length of the array
    x: the axis[0] value at the middle of the range
    distance: how far in either direction to search
Return: None
This function

Description: This function will print out all
    points with axis[0] values within one
    standard deviation of the mean, all points
    with axis[0] values in the range
    [mean – std_dev, mean + std_dev].
************************************************/
void range_query_on_x(Points *set, int number_of_points,
                      float mean, float std_dev)
{
    int i = 0,
        changed = 0,
        lowIndex = 0,
        highIndex = number_of_points - 1,
        middleIndex = (highIndex + lowIndex) / 2;
    float std_dev_low = mean - std_dev,
          std_dev_high = mean + std_dev;

    if(std_dev_high < set[lowIndex].axis[0])
    {
        printf("No Points found within range\n");
        return;
    }
    else if(std_dev_low > set[highIndex].axis[0])
    {
        printf("No Points found within range\n");
        return;
    }
    else if(std_dev_low < set[lowIndex].axis[0] && std_dev_high > set[lowIndex].axis[0])
        i = 0; //Starts printing at set[0] since set[0] is in range, but not the lowest value
    else
    {
        while(set[middleIndex].axis[0] != std_dev_low)
        {
            // printf("searching...\n");
            if(std_dev_low < set[middleIndex].axis[0])
                highIndex = middleIndex - 1;
            else if(std_dev_low > set[middleIndex].axis[0] && std_dev_low < set[middleIndex + 1].axis[0])
            {
                middleIndex = middleIndex + 1;
                break;
            }
            else if(std_dev_low > set[middleIndex].axis[0])
                lowIndex = middleIndex + 1;

            if(lowIndex > highIndex)
            {
                printf("No Points found within range\n");
                return;
            }

            middleIndex = (highIndex + lowIndex) / 2;
        }

        i = middleIndex;
    }



    while(set[i].axis[0] <= std_dev_high && i < number_of_points)
    {
        if(set[i].axis[0] >= std_dev_low)
        {
            printf("%d %f %f\n", set[i].id, set[i].axis[0], set[i].axis[1]);
            changed++;
        }
        i++;
    }

    if(changed == 0)
        printf("No Points found within range\n");
}
