#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

int main(){
  printf("Statistics for directory:\n");
  DIR *cur;
  cur = opendir(".");
  struct dirent *entry = readdir(cur);
  int size = 0;
  while(entry) {
    printf("%s ", entry-> d_name);
    struct stat data;
    stat(entry->d_name, &data);
    if (data.st_mode & (1 << 11) ){
      printf("Directory ");
    }
    printf("%ld Bytes\n", data.st_size);
    size += data.st_size;



    entry = readdir(cur);
  }
  printf("Total Size: %d bytes\n", size);





  return 0;
}
