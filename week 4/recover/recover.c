#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t byte8;
typedef uint16_t byte16;


// tge final number of files is 50 so making a conts 50
const int number = 50;

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    int i = 0;

    // opening the card.raw file into read format
    FILE *raw_file = fopen(argv[1], "r");
    if(raw_file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }


    byte8 buffer[512];
    bool found_jpeg = false;
    int counter = 0;
    char filename[8];
    FILE *img = NULL;

    while(fread(buffer, 1, 512, raw_file))
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            found_jpeg = true;
        }
        if(found_jpeg == true)
        {
            if(counter != 0)
            {
                fclose(img);
            }

                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(buffer, 1, 512, img);
                found_jpeg = false;
                counter++;


        }
        else if(counter != 0)
        {
            fwrite(buffer, 1, 512, img);
            // fclose(img);
        }
    }
    fclose(img);
    fclose(raw_file);

   return 0;
}
