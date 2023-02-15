#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

// # define BUFFER_SIZE 5

char    *get_next_line(int fd);

#endif