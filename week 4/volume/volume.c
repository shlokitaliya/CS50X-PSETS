// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// creating 8bit datatype
typedef uint8_t byte8;
// creating 16bit datatype
typedef int16_t byte16;

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

// an array of byte8 for storing the headerfile
byte8 header[HEADER_SIZE];

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    for(int i = 0; i < HEADER_SIZE; i++)
    {
         fread(header, sizeof(byte8), 1, input);
         fwrite(header, sizeof(byte8), 1, output);
    }


    // TODO: Read samples from input file and write updated data to output file
    byte16 sample;
    while(fread(&sample, sizeof(byte16), 1, input) == 1)
    {
        sample *= factor;
        fwrite(&sample, sizeof(byte16), 1, output);

    }
    

    // Close files
    fclose(input);
    fclose(output);
}
