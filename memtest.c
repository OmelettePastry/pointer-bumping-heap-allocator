#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main (int argc, char **argv){

  // =================== Calling malloc() ====================

  // malloc() calls
  char* x = malloc(24);
  char* y = malloc(19);
  char* z = malloc(32);

  // Sample contents to be stored at address y
  char text1[19] = "There was once four";

  // Our loop to copy the above string (text1) to our location at y
  int a; // counter variable
  
  for (a = 0; a < 19; a++) {
    *(y + a) = text1[a];
  }

  // Display all pointer values and contents
  printf("malloc():\n");

  // Value of x and alignment information  
  printf("x = %p\n", x);
  
  if(((intptr_t)x % 16) == 0) {
    printf("Block is 16-byte aligned.\n\n");
  }
  else {
    printf("Block is NOT 16-byte aligned.\n\n");
  }
  
  // Value of y, alignment information and contents
  printf("y = %p -> ", y);

  for (a = 0; a < 19; a++) {
    printf("%c", *(y + a)); // print contents at address y
  }
  printf("\n");

  if(((intptr_t)y % 16) == 0) {
    printf("Block is 16-byte aligned.\n\n");
  }
  else {
    printf("Block is NOT 16-byte aligned.\n\n");
  }

  // Value of z and alignment information
  printf("z = %p\n", z);
  if(((intptr_t)z % 16) == 0) {
    printf("Block is 16-byte aligned.\n\n");
  }
  else {
    printf("Block is NOT 16-byte aligned.\n\n");
  }
    
  // ==================== Calling realloc() ====================
  // realloc() calls
  x = realloc(x, 13);
  y = realloc(y, 21);  // size requested is bigger than old size, should allocate a new block
  z = realloc(z, 14);

  // Display pointer values and contents
  printf("realloc():\n");

  // Value of x and alignment information
  printf("x = %p\n", x);
  
  if(((intptr_t)x % 16) == 0) {
    printf("Block is 16-byte aligned.\n\n");
  }
  else {
    printf("Block is NOT 16-byte aligned.\n\n");
  }
  
  // Value of y, alignment information and contents
  printf("y = %p -> ", y);

  for (a = 0; a < 19; a++) {
    printf("%c", *(y + a));
  }
  printf("\n");

  if(((intptr_t)y % 16) == 0) {
    printf("Block is 16-byte aligned.\n\n");
  }
  else {
    printf("Block is NOT 16-byte aligned.\n\n");
  }

  // Value of z and alignment information
  printf("z = %p\n", z);
    if(((intptr_t)z % 16) == 0) {
    printf("Block is 16-byte aligned.\n\n");
  }
  else {
    printf("Block is NOT 16-byte aligned.\n\n");
  }
}
