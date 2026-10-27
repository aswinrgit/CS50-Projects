#include <stdio.h>
#include <cs50.h>
#include <math.h>
void credit_card(int a, int b, int n);

int main (void)
{
    long credit = get_long("Number : ");
    int sum1 =0, sum2 =0, i = 0, digit =0, leading_digit = 0, second_digit =0;
while ( credit > 0)
{
    if(credit/10 < 10 && credit/10 > 0)
    {
second_digit = credit % 10;
leading_digit = credit / 10;
    }

    //adding the product of the digit with 2 if it's a the last or the series from the last digit
    if(i%2!=0 || i==1)
    {
    digit = (credit % 10) * 2;
    credit /= 10;

    //checking whether the digit is more than an one digit number

    if (digit / 10 !=0 )
    {
        digit = digit % 10;
        sum1 = sum1 + digit + 1;
        
    }
    else
    {
        sum1 += digit;
            
    }
     i++;
    }
    else
    {
        digit = credit % 10;
        sum2 += digit;
        credit /= 10;
        
        i++;

    }
}

if((sum1+sum2) % 10 == 0)
credit_card(leading_digit, second_digit,i);
else
printf("INVALID\n");
}

//passing the first digit, second digit and the number of digits 

void credit_card(int a, int b, int n)
{
    int check_number = (a*10)+b;
 
    if(a==4 && ((n==13)|| (n==16)))
    {
        printf("VISA\n");
    }
    else if ((check_number == 34 || check_number == 37) && (n==15))
    {
        printf("AMEX\n");
    }
    else if ((check_number<56 && check_number>50) && (n==16))
    {
        printf("MASTERCARD\n");
    }
    else{
        printf("INVALID\n");
    }
}

