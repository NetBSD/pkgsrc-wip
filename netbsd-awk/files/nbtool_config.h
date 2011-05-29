#ifndef _NBTOOL_CONFIG_H_
#define _NBTOOL_CONFIG_H_

#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define __UNCONST(a)   ((void *) (intptr_t) (const void *) (a))

#ifndef HAVE_FUNC1_FPURGE
int fpurge (FILE *stream);
#endif

#ifndef HAVE_FUNC3_STRLCAT
size_t strlcat(char *dst, const char *src, size_t size);
#endif

#endif // _NBTOOL_CONFIG_H_
