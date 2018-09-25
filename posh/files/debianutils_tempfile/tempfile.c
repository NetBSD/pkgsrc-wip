#include "config.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#ifdef HAVE_GETOPT_H
#include <getopt.h>
#endif /* HAVE_GETOPT_H */
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

char *progname;

void usage(int);
void syserror(const char *);
int parsemode(const char *, mode_t *);

void
usage (int status)
{
  if (status)
    fprintf(stderr, "Try `%s --help' for more information.\n", progname);
  else
    printf("Usage: %s [OPTION]\n\n"
"Create a temporary file in a safe manner.\n\n"
"-d, --directory=DIR  place temporary file in DIR\n"
"-m, --mode=MODE      open with MODE instead of 0600\n"
"-n, --name=FILE      use FILE instead of tempnam(3)\n"
"-p, --prefix=STRING  set temporary file's prefix to STRING\n"
"-s, --suffix=STRING  set temporary file's suffix to STRING\n"
"    --help           display this help and exit\n"
"    --version        output version information and exit\n", progname);
  exit(status);
}


void
syserror (const char *fx)
{
  perror(fx);
  exit(1);
}


int
parsemode (const char *in, mode_t *out)
{
  char *endptr;
  long int mode;
  mode = strtol(in, &endptr, 8);
  if (*endptr || mode<0 || mode>07777)
    return 1;
  *out = (mode_t) mode;
  return 0;
}


int
main (int argc, char **argv)
{
  char *name=0, *dir=0, *pfx="file", *sfx=0, *filename=0;
  mode_t mode = 0600;
  int fd, optc;
  struct option long_options[] = {
    {"prefix", required_argument, 0, 'p'},
    {"suffix", required_argument, 0, 's'},
    {"directory", required_argument, 0, 'd'},
    {"mode", required_argument, 0, 'm'},
    {"name", required_argument, 0, 'n'},
    {"help", no_argument, 0, 'h'},
    {"version", no_argument, 0, 'v'},
    {0, 0, 0, 0}
  };
  progname = argv[0];

  while ((optc = getopt_long (argc, argv, "p:s:d:m:n:", long_options, 0))
	 != EOF) {
    switch (optc) {
    case 0:
      break;
    case 'p':
      pfx = optarg;
      break;
    case 's':
      sfx = optarg;
      break;
    case 'd':
      dir = optarg;
      break;
    case 'm':
      if (parsemode(optarg, &mode)) {
	fprintf(stderr, "Invalid mode `%s'.  Mode must be octal.\n", optarg);
	usage(1);
      }
      break;
    case 'n':
      /* strdup because it is freed later on */
      if((name = strdup(optarg)) == NULL)
        syserror("strdup");
      break;
    case 'h':
      usage(0);
    case 'v':
      puts("tempfile " PACKAGE_VERSION);
      exit(0);
    default:
      usage(1);
    }
  }

  if (name) {
    if ((fd = open(name, O_RDWR | O_CREAT | O_EXCL, mode)) < 0)
      syserror("open");
    filename = name;
  }
  else {
    /*
       a) In case the environment variable TMPDIR exists
          and contains the name of an appropriate directory,
          that is used.
       b) Otherwise, if the --directory argument is specified
          and appropriate, it is used.
       c) Otherwise, P_tmpdir (as defined in <stdio.h>) is used
          when appropriate.
       d) Finally an implementation-defined directory (/tmp)
          may be used.
    */

    char *tmpdirs[] = {
	getenv("TMPDIR"),
	dir,
	P_tmpdir,
	"/tmp"
    };
    int i;

    for (i = 0; i < sizeof(tmpdirs) / sizeof(char *); i++) {
      char *tmpdir = tmpdirs[i];
      if (!tmpdir)
	continue;

      size_t len =
	strlen(tmpdir) + 1 + /* / */
	(pfx ? strlen(pfx) : 0) +
	6 + /* XXXXXX */
	(sfx ? strlen(sfx) : 0) +
	1; /* NUL */

      if (!(filename = malloc(len)))
	syserror("malloc");

      snprintf(filename, len, "%s/%sXXXXXX%s",
	tmpdir,
	pfx ? pfx : "",
	sfx ? sfx : "");

      if ((fd = mkstemps(filename, sfx ? strlen(sfx) : 0)) < 0) {
	if (errno == EEXIST) {
	  free(filename);
	  continue;
	}
	syserror("mkstemps");
      }

      if (fchmod(fd, mode) < 0)
	syserror("fchmod");
      break;
    }
  }
  
  if (close(fd))
    syserror("close");
  puts(filename);
  if(name != filename)
    free(name);
  free(filename);
  exit(0);
}
