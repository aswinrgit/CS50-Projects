#include<stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
int value (char letter);

int main (void)
{
    string word1 = get_string("Player 1 : ");
    string word2 = get_string("Player 2 : ");
    int  sum1 =0, sum2 = 0;
    for( int i = 0; word1[i] != '\0' ; i++)
    { 
       // convert every word in input to it's lowercase 

       word1[i] = tolower(word1[i]);

       // get the value of each letter
       
       sum1+= value(word1[i]);

    }
    for ( int i =0; word2[i] != '\0'; i++)
    {
        word2[i] = tolower(word2[i]);
        sum2+= value(word2[i]);
    }
    if(sum1 == sum2)
    {
        printf("Tie!\n");
    }
    else if(sum1> sum2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
}
int value (char letter)
{
if((letter == 'a') || (letter == 'e') || (letter == 'i') || (letter == 'l') || (letter == 'n') || (letter == 'o') || (letter == 'o') || (letter == 'r') || (letter == 's') || (letter == 't') || (letter == 'u') )
return 1;
else if((letter == 'd') || (letter == 'g'))
return 2;
else if((letter == 'b') || (letter == 'c') || (letter == 'm') || (letter == 'p'))
return 3;
else if((letter == 'f') || (letter == 'h') || (letter == 'v') || (letter == 'w') || (letter == 'y'))
return 4;
else if(letter == 'k')
return 5;
else if((letter == 'x') || (letter == 'j'))
return 8;
else if((letter == 'q') || (letter == 'z'))
return 10;
else
return 0;
}
