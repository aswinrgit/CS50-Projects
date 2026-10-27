#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    int word = 1;
    int sentence = 0;
    int letter = 0;
    double L, S;
    string para = get_string("Text: ");

    //iterate through each letter in the string

    for(int i = 0; para[i] != '\0'; i++)
    {
        if(((para[i]<91 && para[i]>64)) || ((para[i]<123) && (para[i]>96))) //increase letter count based on whether it's an alphabet
        letter++;
        if(para[i] == ' ') //increase word count based on every space
        word++;
        if((para[i] == '.') || (para[i] == '!') || (para[i] == '?')) //increase sentence count based on each punctuation
        sentence++;

    }
     L = ((float)letter / word) * 100; //calculate letter average per 100 words
     S = ((float)sentence / word) * 100; //calculate sentence average per 100 words
     double C = 0.0588 * L - 0.296 * S - 15.8;
     C = round(C);
     if(C < 1)
     {
        printf("Before Grade 1\n");
     }
     else if ( C < 16)
     {
        printf("Grade %d\n", (int)C);
     }
     else
     {
        printf("Grade 16+\n");
     }

   // printf("%i %i %i %f %f %f\n", word, sentence, letter, L, S, C); (debugging)
}
