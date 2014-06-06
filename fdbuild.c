#include "transit_bdd.h"

char *read_fd(int fd)
{
  char *buffer;
  int compt;

  buffer = (char *)malloc(2000);
  compt = -1;
  while (read(fd, &buffer[++compt], 1) > 0 && buffer[compt] && compt < 1999)
    ;
  buffer[compt] = '\0';
  return (buffer);
}

int size_fd(int fd)
{
  struct stat status;

  fstat(fd, &status);

  return (status.st_size);
}
