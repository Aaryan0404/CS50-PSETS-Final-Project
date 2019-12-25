#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    //Checks if the input-argument in valid in length//
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image_file\n");
        return 1;
    }

    //Stores and opens user-inputted image file (checks to see is that the image file is not NULL)//
    FILE *image_file = fopen(argv[1], "r");

    if (image_file == NULL)
    {
        fprintf(stderr, "Unable to open and read file\n");
        return 2;
    }

    //Allocates 512 bytes to a 'string', and stores the string//
    unsigned char *buffer = malloc(512);
    int number = 0;
    FILE *JPG = NULL;

    //Loop for moving by each 512-byte memory block on the memory card//
    while (fread(buffer, 512, 1, image_file) == 1)
    {
        //When JPEG is first identified//
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //If previous JPEG already exists...//
            if (number != 0)
            {
                fclose(JPG);
            }

            //Opens previously created JPG file to store memory in//
            char filename[7];
            sprintf(filename, "%03i.jpg", number);
            JPG = fopen(filename, "w");

            //Checks that the JPG file is not NULL//
            if (JPG == NULL)
            {
                fclose(image_file);
                free(buffer);
                fprintf(stderr, "Unable to create JPEG file\n");
                return 3;
            }

            //Writes memory from buffer (512-byte memory block) into JPG file, and increments JPEG counter//
            fwrite(buffer, 512, 1, JPG);
            number++;
        }

        //If JPEG-starter-block is not identified//
        else
        {
            //If JPEG file has not been created previously, skip over 512-byte-memory block//
            if (number == 0)
            {
                continue;
            }

            //If JPEG file has already been created previously, add 512-byte-memory-block to already opened JPEG file//
            else
            {
                fwrite(buffer, 512, 1, JPG);
            }
        }
    }

    //When EOF-block identified//
    if (fread(buffer, 512, 1, image_file) != 1)
    {
        //Close all files and free memory//
        fclose(image_file);
        fclose(JPG);
        free(buffer);
    }

    return 0;
}
