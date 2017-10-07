//C program to print a pattern
/*program to print the following pattern:-
*
**
***
****
*****
****
***
**
*
------------------------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>                                        //header file declaration
void main()                                              //main function execute from here
{
int i,j,n,m;                                             //declaring variables
printf("enter value for number of rows:");               //asking values from user for number of rows
scanf("%d",&n);                                          //taking values from user for number of rows
for(i=0;i<n;i++)                                         //loop for rows from 0 to n
{
    for(j=0;j<i+1;j++)                                   //loop for columns
    {
        printf("*");                                     //to print *
    }
    printf("\n");                                        //for changing rows
}
//for printing pattern in reverse direction
for (i=n;i>0;i--)                                        //loop for rows n to 0
{
    for (j=i;j>0;j--)                                    //loop for columns
    {
        printf("*");                                     //to print *

    }
    printf("\n");                                       //for changing rows
}

}
