#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include<ctype.h>
#include<math.h>

int main(void)
{
    //take input text from user
    string text = get_string("Enter a Text : ");
    int letter = 0, word = 1, sentence = 0 ;
    
    //counting number of letters , words , sentences 
    for (int i = 0, n = strlen(text) ; i < n ; i++)
    {
        if (text [i] != '\0')
        {
            if (isalpha(text[i]))
            {
                letter++;
            }
            if (isspace(text[i]))
            {
                word++;
            }
            if (text[i] == '!' || text[i] == '.' || text[i] == '?')
            {
                sentence++;
            }
        } 
    }
    
    //calculate The Coleman-Liau index 

    float L = ((float)letter / word) * 100 ;
    float S = ((float)sentence / word) * 100 ;
    
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);
    //printing the grade index
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);

    }

}