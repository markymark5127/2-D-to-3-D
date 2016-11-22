#include <stdio.h>
#include <stdlib.h>
#include "EasyBMP.h"
#include "Image.h"

namespace {
	class Init {
	public:
		Init() { SetEasyBMPwarningsOff(); }
	};

	static Init s_init;
}

void ReadImage(const char *filename, int red[WIDTH][HEIGHT], int green[WIDTH][HEIGHT], int blue[WIDTH][HEIGHT])
{
	BMP source;
	source.ReadFromFile(filename);

	if (source.TellWidth() != WIDTH || source.TellHeight() != HEIGHT) {
		printf("Image is not 400x300\n");
		exit(1);
	}

	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			red[i][j] = source(i, j)->Red;
			green[i][j] = source(i, j)->Green;
			blue[i][j] = source(i, j)->Blue;
		}
	}
}

void WriteImage(const char *filename, int red[WIDTH][HEIGHT], int green[WIDTH][HEIGHT], int blue[WIDTH][HEIGHT])
{
	BMP dest;
	dest.SetBitDepth(24);
	dest.SetSize(WIDTH, HEIGHT);
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			dest(i, j)->Red = (unsigned) red[i][j];
			dest(i, j)->Green = (unsigned) green[i][j];
			dest(i, j)->Blue = (unsigned) blue[i][j];
		}
	}
	dest.WriteToFile(filename);
}

void WriteDoubleSizeImage(const char *filename, int red[WIDTH*2][HEIGHT*2], int green[WIDTH*2][HEIGHT*2], int blue[WIDTH*2][HEIGHT*2])
{
	BMP dest;
	dest.SetBitDepth(24);
	dest.SetSize(WIDTH*2, HEIGHT*2);
	for (int i = 0; i < WIDTH*2; i++) {
		for (int j = 0; j < HEIGHT*2; j++) {
			dest(i, j)->Red = (unsigned) red[i][j];
			dest(i, j)->Green = (unsigned) green[i][j];
			dest(i, j)->Blue = (unsigned) blue[i][j];
		}
	}
	dest.WriteToFile(filename);
}
