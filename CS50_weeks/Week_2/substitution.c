#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

int check_key(string key);
void cipher(string plain_text, string key);

int main ( int argc, string argv[])
{
    if(argc != 2)
    {
        printf("INVALID\n");
        return 1;
    }


    if(check_key(argv[1]) == 1)
    {
        printf("INVALID\n");
        return 1;

    }
    else
    {
          string plain_text = get_string("plain text : ");
          cipher(plain_text, argv[1]);
    return 0;

    }
}

int check_key(string key)
{
    int check = 0;
     for (int i = 0; key[i] != '\0'; i++)
    {
        if (isalpha(key[i]) != 0)
        {
            check++;
        }
        for(int j = i+1; key[j] != '\0'; j++) //checking for repeated alphabets in the key
        {
            if(key[i] == key[j] || key[i] == tolower(key[j]))
            {
                return 1;
            }

        }

    }
    if(check == 26)
    {
        return 0;
    }
    else
    {
        return 1;
    }

}

void cipher(string plain_text, string key)
{

    string sample = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string sample1 = "abcdefghijklmnopqrstuvwxyz";
    for (int i=0 ; key[i] != '\0'; i++)
    {
        key[i] = toupper(key[i]);
    }

    for (int i = 0; plain_text[i] != '\0'; i++)
        {
            for (int j = 0; key[j] != '\0'; j++)
            {
                if(plain_text[i] == sample[j])
                {
                    plain_text[i] = key[j];
                    break;
                }
                else if(plain_text[i] == sample1[j])
                {
                    plain_text[i] = tolower(key[j]);
                    break;
                }
            }

            }
            printf("ciphertext: %s\n", plain_text);
}



