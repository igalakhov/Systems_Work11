#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>

int main(){
  char * filename = "main.out";

  printf("\nPrinting out information about [%s]:\n\n", filename);

  struct stat info;

  stat(filename, &info);

  // print file size
  int size = info.st_size;
  printf(" File size:\n  actual value: %d\n  formatted value: %d GB, %d MB, %d KB, %d B\n\n",
      size,
      (size/(1024 * 1024 * 1024) % 1024),
      (size/(1024 * 1024) % 1024),
      (size/(1024) % 1024),
      (size % 1024));

  // print permissions
  int perm = info.st_mode;
  printf(" Permissions:\n  actual value: %o\n  formatted value: -%s%s%s%s%s%s%s%s%s\n\n",
        perm,
        ((perm & ( 1 << 8 )) >> 8) ? "r":"-",
        ((perm & ( 1 << 7 )) >> 7) ? "w":"-",
        ((perm & ( 1 << 6 )) >> 6) ? "x":"-",
        ((perm & ( 1 << 5 )) >> 5) ? "r":"-",
        ((perm & ( 1 << 4 )) >> 4) ? "w":"-",
        ((perm & ( 1 << 3 )) >> 3) ? "x":"-",
        ((perm & ( 1 << 2 )) >> 2) ? "r":"-",
        ((perm & ( 1 << 1 )) >> 1) ? "w":"-",
        ((perm & ( 1 << 0 )) >> 0) ? "x":"-");

  // print time of last access
  int laccess = info.st_atime;
  printf(" Time of last access:\n  %s", ctime((const long * ) &laccess));

  printf("\n");
  return 0;
}
