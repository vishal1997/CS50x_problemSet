/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
		printf("Usage:resize n infile outfile\n");
		return 1;
    }



    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];
    int n=atoi(argv[1]);
    
    if(n < 0 || n > 100)
	{
	    printf("The resize factor should be a positive integer <= 100.\n");
        return 2;
	    
	}

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    
    // bitmap headers for the outfile
		BITMAPFILEHEADER out_bf;
		BITMAPINFOHEADER out_bi;	
		out_bf = bf;
		out_bi = bi;
		out_bi.biWidth = bi.biWidth * n;
		out_bi.biHeight = bi.biHeight * n;

		// determine padding for scanlines

		// Image size calculation

		int inPadding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
		int outPadding =  (4 - (out_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

		// Compute file and image size

		// source https://code.google.com/p/kupl09/ for suggesting the formula for 

		// biSizeImage calculation.

		out_bf.bfSize = 54 + out_bi.biWidth * abs(out_bi.biHeight) * 3 + abs(out_bi.biHeight) *  outPadding;
		out_bi.biSizeImage = ((((out_bi.biWidth * out_bi.biBitCount) + 31) & ~31) / 8) * abs(out_bi.biHeight);

    // outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
		{
				// Write each line n-times
				for(int z = 0; z < n; z++)
				{
						// iterate over pixels in scanline
						for (int j = 0; j < bi.biWidth; j++)
						{
								// temporary storage
								RGBTRIPLE triple;
								// read RGB triple from infile
								fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
								// write RGB triple to outfile
								for(int m = 0; m < n; m++) 
								{
										fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
								}
						}
						// skip over padding in infile
						fseek(inptr, inPadding, SEEK_CUR);
						for (int k = 0; k <outPadding; k++)
								fputc(0x00, outptr);
						fseek(inptr, -(bi.biWidth * 3 + inPadding ), SEEK_CUR);
				}
				fseek(inptr, bi.biWidth*3+inPadding, SEEK_CUR);
		}
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
