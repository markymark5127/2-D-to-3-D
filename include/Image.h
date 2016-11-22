#ifndef IMAGE_H
#define IMAGE_H

#define WIDTH 400
#define HEIGHT 300

void ReadImage(const char *filename, int red[WIDTH][HEIGHT], int green[WIDTH][HEIGHT], int blue[WIDTH][HEIGHT]);
void WriteImage(const char *filename, int red[WIDTH][HEIGHT], int green[WIDTH][HEIGHT], int blue[WIDTH][HEIGHT]);
void WriteDoubleSizeImage(const char *filename, int red[WIDTH*2][HEIGHT*2], int green[WIDTH*2][HEIGHT*2], int blue[WIDTH*2][HEIGHT*2]);

#endif
