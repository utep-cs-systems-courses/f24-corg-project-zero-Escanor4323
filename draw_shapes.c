#include <stdio.h>
#include "draw.h"

/* Prints a size x size square whose left col is at startCol */
void print_square(int leftCol, int size)
{
  int i, j;
  int endCol = leftCol + size;
  for (int row = 0; row < size; row++){
    int col;
    for (col = 0; col < leftCol; col++) putchar(' ');
    for (       ; col < endCol;  col++) putchar('*');
    putchar('\n');
  }
}


void print_triangle(int leftCol, int size)
{
  for (int row = 0; row <= size; row++) {
    int minCol = leftCol + size - row, maxCol = leftCol + size + row;
    int col;
    for (col = 0; col < minCol; col++) putchar(' ');
    for (       ; col <= maxCol; col++) putchar('*');
    putchar('\n');
  }
}

void print_line(int leftPadding, int stars) {
  for (int i = 0; i < leftPadding; i++) {
    printf(" ");
  }
  for (int i = 0; i < stars; i++) {
    printf("*");
  }
  printf("\n");
}

// Function to print an arrow with configurable position and size
void print_arrow(int leftCol, int size) {
  int max_width = size * 2 + 1; // Maximum width at the center of the arrow
  int half_size = size / 2;

  // Print the top part of the arrow
  for (int i = 0; i < half_size; i++) {
    int stars = i + 1;
    int padding = leftCol + half_size - i;
    print_line(padding, stars);
  }

  // Print the middle part (widest part)
  print_line(leftCol, max_width - 1);
  print_line(leftCol, max_width);

  // Print the bottom part of the arrow
  for (int i = half_size - 1; i >= 0; i--) {
    int stars = i + 1;
    int padding = leftCol + half_size - i;
    print_line(padding, stars);
  }
}