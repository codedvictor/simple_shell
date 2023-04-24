#include "cshell.h"

/**
  * concat_path - Concatenate a path name and a program name
  * @pathname: The path name to concatenate with the program name
  * @progname: The program name to place in the path name
  *
  * Return: The path name concatenated with the program name
  */
char *concat_path(char *pathname, char *progname)
{
        int prog_leng = 0, path_leng = 0, new_sz = 0;

        prog_leng = _strlen(progname);
        path_leng = _strlen(pathname);
        new_sz = sizeof(char) * (path_leng + prog_leng + 2);
        pathname = _realloc(pathname, (path_leng + 1), new_sz);
        if (!pathname)
                return (NULL);

        _strcat(pathname, "/");
        _strcat(pathname, progname);

        return (pathname);
}
