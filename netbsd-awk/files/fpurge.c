#include <stdio.h>

#if HAVE_FUNC1___FPURGE_STDIO_EXT_H
#include <stdio_ext.h>
#endif

int fpurge(FILE *stream);

int fpurge(FILE *stream)
{
#if HAVE_FUNC1___FPURGE_STDIO_EXT_H
  __fpurge (stream);
  return 0;
#else
#error "cannot find fpurge(3), sorry"
#endif
}
