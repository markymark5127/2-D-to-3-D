#include <iostream>
#include <stdio.h> 
#include "Image.h" 

using namespace std;
int red[WIDTH][HEIGHT];
int green[WIDTH][HEIGHT];
int blue[WIDTH][HEIGHT];
int red_out[WIDTH * 2][HEIGHT * 2];
int green_out[WIDTH * 2][HEIGHT * 2];
int blue_out[WIDTH * 2][HEIGHT * 2];
int midWidth = 15;


int main(void)
{
	ReadImage("kitten.bmp", red, green, blue);
	for (int r = 0; r < (WIDTH * 2) + midWidth; r++)
	{
		for (int c = 0; c < HEIGHT * 2; c++)
		{
			if (r !< WIDTH && r < WIDTH + midWidth)
			{
				red_out[r][c] = 0;
				green_out[r][c] = 0;
				blue_out[r][c] = 0;
			}
			if (r > WIDTH + midWidth)
			{
				red_out[r][c] = red[r - (WIDTH+midWidth)][c];
				green_out[r][c] = green[r - (WIDTH + midWidth)][c];
				blue_out[r][c] = blue[r - (WIDTH + midWidth)][c];
			}
		}
	}
	WriteDoubleSizeImage("rgb.bmp", red_out, green_out, blue_out);
	printf("Done writing image\n");
	return 0;
}