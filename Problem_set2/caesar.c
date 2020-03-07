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
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //check if the single line command argument all digits 
    else
    {
        for (int i = 0 ; i < strlen(argv[1]) ; i++)
        {
            if (isdigit(argv[1][i]))
            {
                flag = true;
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
            int k = atoi(argv[1]);
            string plain = get_string("plaintext: ");
            int n = strlen(plain);
            int out[n];

            for (int i = 0 ; i < n ; i++)
            {
                if (plain[i] >= 'a' && plain[i] <= 'z')
                {
                    out[i] = (((int) plain[i] + k - (int)'a') % 26) + (int)'a' ;
                }
                else if (plain[i] >= 'A' && plain[i] <= 'Z')
                {
                    out[i] = (((int) plain[i] + k - (int)'A') % 26) + (int)'A' ;
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
            printf("Usage: ./caesar key\n");
            return 1;
        }

    }
    return 0;
}