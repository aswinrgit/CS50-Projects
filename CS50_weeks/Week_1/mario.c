#include <cs50.h>
#include <stdio.h>
void mario (int n);

int main (void)
{
    int choice =0;
    do
    {
     choice = get_int("Number of rows between 1 and 8: ");
    }
    while (choice>8 || choice<1);
    mario(choice);
}
void mario (int n)
{

     for (int i = 0 ; i< n; i++)
     {
        for (int j=0; j<n*2+2 ; j++)
     {
        if (j==n || j==n+1)
        printf(" ");
        else if ((i+j>=n-1 && j<n) || (j-i<=n+2 && j>n+1))
        printf("#");
        else
        printf(" ");
     }
printf("\n");

     }
}
