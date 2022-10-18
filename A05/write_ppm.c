#include "write_ppm.h"
#include <stdio.h>
#include <string.h>

// implement one

void write_ppm(const char* filename, struct ppm_pixel* pixels, int w, int h) {
    FILE* outfile = NULL;
    outfile = fopen(filename, "w");
    if (outfile == NULL) {
        printf("Error opening file. %s\n", filename);
        return;
    }
    fprintf(outfile, "P6\n");
    fprintf(outfile, "%d %d\n", w, h);
    fprintf(outfile, "255\n");
    for(int i = 0; i < w * h; i++) {
        fwrite(&pixels[i].red, sizeof(unsigned char), 1, outfile);
        fwrite(&pixels[i].green, sizeof(unsigned char), 1, outfile);
        fwrite(&pixels[i].blue, sizeof(unsigned char), 1, outfile);
    }
    fclose(outfile);
}

void write_ppm_2d(const char* filename, struct ppm_pixel** pixels, int w, int h) {

}
