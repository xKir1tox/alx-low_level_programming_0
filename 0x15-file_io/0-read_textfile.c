#include "main.h"

ssize_t read_textfile(const char *filename, size_t letters)
{
    ssize_t n_read;
    char *buffer;
    FILE *fp;

    if (filename == NULL)
        return (0);

    fp = fopen(filename, "r");
    if (fp == NULL)
        return (0);

    buffer = malloc(sizeof(char) * letters);
    if (buffer == NULL)
        return (0);

    n_read = fread(buffer, sizeof(char), letters, fp);
    if (n_read == 0)
    {
        free(buffer);
        fclose(fp);
        return (0);
    }

    if (fwrite(buffer, sizeof(char), n_read, stdout) != n_read)
    {
        free(buffer);
        fclose(fp);
        return (0);
    }

    free(buffer);
    fclose(fp);
    return (n_read);
}

