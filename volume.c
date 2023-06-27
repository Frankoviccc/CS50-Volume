// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

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
    // Initialize array with type for 8-bit integers, length of header_size
    uint8_t header[HEADER_SIZE];
    for (int i = 0; i < HEADER_SIZE; i++)
    {
        printf("uint8: %d\n", header[i]);
    }
    // read the input file
    fread(header, HEADER_SIZE, 1, input);
    // Write the header into output file
    fwrite(header, HEADER_SIZE, 1, output);
    // TODO: Read samples from input file and write updated data to output file
    // Initialize buffer big enough to store 2 samples (16bits)
    int16_t buffer;
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        printf("int16 %d\n", buffer);
        // Update volume
        buffer *= factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }
    // Close files
    fclose(input);
    fclose(output);
}
