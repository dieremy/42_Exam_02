#include "get_next_line.h"

char    *get_next_line(int fd)
{
    int     i;
    int     b;
    char    c;
    char    *line;

    b = 0;
    i = 0;
    line = malloc(10000);
    while((b = read(fd, &c, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
    {
        line[i++] = c;
        if (c == '\n')
            break;
    }
    if ((!line[i - 1] && !b) || b == -1)
    {
        free(line);
        return (NULL);
    }
    line[i] = '\0';
    return (line);
}

int main()
{
    // int fd = open("file.txt", O_RDONLY);
    // char *s = get_next_line(fd);
    // printf("%s\n", s);
    // free(s);
    // int f = open("file.txt", O_RDONLY);
    // char *x = get_next_line(f);
    // printf("%s\n", x);
    // free(x);
    // int d = open("file.txt", O_RDONLY);
    // char *t = get_next_line(d);
    // printf("%s\n", t);
    // free(t);
    int f = open("file.txt", O_RDONLY);
    printf("%s", get_next_line(f));
    printf("%s", get_next_line(f));
    printf("%s", get_next_line(f));
}