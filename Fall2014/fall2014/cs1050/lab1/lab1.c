/* 
 * Pearse Hutson
 * pah9qd
 * 9.2.2014
lab1
Lab code: 
*/

#include <stdio.h>

int main()
{

int x, y, z, sum, distance, speed; 
float time;

printf("\n Enter the first number: ");
scanf("%d", &x);

printf("\n Enter the second number: ");
scanf("%d", &y);

printf("\n Enter the third number: ");
scanf("%d", &z);

sum=x+y+z;

printf("\n Sum of the three numbers is %d \n", sum);

printf("\n Bonus part \n");

printf("\n Enter the distance: ");
scanf("%d", &distance);

if(distance < 1)
{
printf("\n Distance should be a positive number");
printf("\n Enter the distance: ");
scanf("%d", &distance);
}

printf("\n Enter the speed: ");
scanf("%d", &speed);

if(speed < 1)
{
printf("\n Speed should be a positive number");
printf("\n Enter the speed: ");
scanf("%d", &speed);
}

time = (((float)distance/1600)/speed) * 3600;
printf("\n Flight time of the plane is %f \n", time);

return 0;
}
