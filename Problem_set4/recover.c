#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
    // check if single line command arguments
    if (argv[1] == NULL || argc > 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) 
    {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        return 2;
    }
        
    BYTE buffer[512];
    int i = 0 ; 
    char filename[8];
    FILE *img = NULL;

    while (file != NULL)
    {
        size_t bytesRead = fread(buffer, 512, sizeof(BYTE), file);
        //check if sucessfully read block of bytes
        if (bytesRead == 0)
        {
            break;
        }
        //check if starting of jpeg file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //check if there is opening file
            if (img != NULL)
            {
                fclose(img);
                i++;
            }
            //write the bytes into file     
            sprintf(filename, "%03i.jpg", i);
            img = fopen(filename, "w");
        }
        //complete writing in file if the new block isn't the start of new jpeg file           
        if (img != NULL)
        {
            fwrite(buffer, 512, sizeof(BYTE), img);
        }
                    
    }
    //close all opening files to free memory
    fclose(img);
           
    fclose(file);
       
    return 0 ;

}
