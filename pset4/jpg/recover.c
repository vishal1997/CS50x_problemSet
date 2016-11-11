#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
// help taken from "https://github.com/CoreData/cs50/blob/master/pset4/jpg/recover.c"
int main(int argc, char* argv[])

{
		FILE* filePointer = fopen("card.raw", "r");	
		if(filePointer == NULL)
		{	
				fclose(filePointer);
				fprintf(stderr, "Can't open file.\n");
				return 1;
		}
	 // starting bytes of a jpeg file.

		uint8_t checkjpg1[4] = {0xff, 0xd8, 0xff, 0xe0};

		uint8_t checkjpg2[4] = {0xff, 0xd8, 0xff, 0xe1};

		int jpgcount = 0;

		int open = 0;

		FILE* outptr;

	  // Read 512b blocks from file.

		uint8_t buffer[512];

		uint8_t check[4];

		fread(buffer, 512, 1, filePointer);	

		while(fread(buffer, 512, 1, filePointer) > 0)

		{
				// Add first four bytes into the check buffer

				for(int i = 0; i < 4; i++)
				{
						check[i] = buffer[i];
				}

				// Check jpeg signature

				if((memcmp(checkjpg1, check, 4) == 0 ) || (memcmp(checkjpg2, check, sizeof(check)) == 0))

				{
						char filename[8];
						sprintf(filename, "%03d.jpg", jpgcount);
						if(open == 0)
						{
								outptr = fopen(filename, "w");
								fwrite(buffer, sizeof(buffer), 1, outptr);
								open = 1;
						}

						if(open == 1)
						{
								fclose(outptr);
								outptr = fopen(filename, "w");
								fwrite(buffer, sizeof(buffer), 1, outptr);
								jpgcount++;
						}
				}
				else
				{
						if(open == 1)
						{
								fwrite(buffer, sizeof(buffer), 1, outptr);
						}
				}
		}
        if(outptr)
        {
            fclose(outptr);
        }
		fclose(filePointer);
		return 0;
}