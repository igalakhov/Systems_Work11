#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>


int main(){
  char * filename = "main.c";

  printf("\nPrinting out information about [%s]:\n", filename);

  struct stat info;

  stat(filename, &info);

  // print file size

  printf(" File size: [%s]\n", "");

  // print permissions

  printf(" Permissions: [%s]\n", "");

  // print time of last access
  printf(" Time of last access: [%s]\n", "");

  printf("\n");
  return 0;
}
