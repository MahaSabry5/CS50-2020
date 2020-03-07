#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    bool flag = false;

    // check if single line command arguments
    if (argv[1] == NULL || argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //check if the single line command argument all charachters and has no duplicates
    else if (strlen(argv[1]) == 26)
    {
        for (int i = 0 ; i < 26 ; i++)
        {
            if (isalpha(argv[1][i]))
            {
                for (int j = 0 ; j < 26 ; j++)
                {
                    if (i == j)
                    {
                        continue;
                    }
                    if (argv[1][i] == argv[1][j])
                    { 
                        printf("Key must contain 26 characters.\n");
                        return 1;
                    }
                    else
                    {
                        flag = true;
                    }

                }
            }
            else
            {
                flag = false ;
                break;
            }
        }
        //start to cipher the text
        if (flag)
        {
            //int k = atoi(argv[1]);
            string plain = get_string("plaintext: ");
            int n = strlen(plain);
            int out[n];

            for (int i = 0 ; i < n ; i++)
            {
                if (plain[i] >= 'a' && plain[i] <= 'z')
                {
                    out[i] = tolower((int)argv[1][(int)plain[i] - 97]) ;
                }
                else if (plain[i] >= 'A' && plain[i] <= 'Z')
                {
                    out[i] = toupper((int)argv[1][(int)plain[i] - 65]) ;
                }
                else
                {
                    out[i] = plain[i];
                }
            }

            printf("ciphertext: ");

            for (int i = 0 ; i < n ; i++)
            {
                printf("%c", out[i]);
            }
            printf("\n");
        }
        else
        {
            printf("Key must only contain alphapetic characters.\n");
            return 1;
        }
    }
    else
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }


    return 0;
}