#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

ssize_t getline (char **lineptr, size_t *n, FILE *stream)
{
	size_t len;
	char *str;

	if (!n || !lineptr)
		return EINVAL;

	str = fgetln (stream, &len);
	if (!str)
		return (size_t) -1;

	*n = len;

	*lineptr = realloc (*lineptr, len+1);
	if (! *lineptr)
		return (size_t) -1;

	memcpy (*lineptr, str, len);
	(*lineptr) [len] = 0;
	return len;
}
