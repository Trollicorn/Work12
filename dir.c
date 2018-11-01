#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int main(){
  printf("Statistics for directory: .\n");
  DIR *cur;
  cur = opendir(".");
  struct dirent * entry = readdir(cur);
  int size = 0;
  char directories[200] = "Directories:\n\t";
  char files[200] = "Files:\n\t";
  while(entry) {
    struct stat data;
    stat(entry->d_name, &data);

    if (S_ISDIR(data.st_mode)){ //idk why, but it works
      strcat(directories, entry->d_name);
      strcat(directories, "\n\t");
    }
    else{
      strcat(files, entry->d_name);
      strcat(files, "\n\t");
    }
    size += data.st_size;
    entry = readdir(cur);
  }
  printf("Total Size: %d bytes\n", size);
  printf("%s\n", directories);
  printf("%s\n", files);
  return 0;
}
