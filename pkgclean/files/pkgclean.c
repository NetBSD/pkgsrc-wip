/*
 * Copyright (c) 2004 Peter Postma <peter@pointless.nl>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

#include <sys/types.h>
#include <sys/param.h>
#include <sys/stat.h>

#include <err.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PKGSRCDIR	"/usr/pkgsrc"

static const char	skip[][] = { ".", "..", "CVS", "bootstrap", "doc", "distfiles", "licenses", "mk" };

static void		pkgclean(const char *);
static int		checkskip(const struct dirent *);

int
main(void)
{
	const char *path;

	if ((path = getenv("PKGSRCDIR")) == NULL)
		path = PKGSRCDIR;

	pkgclean(path);

	return 0;
}

static void
pkgclean(const char *path)
{
	struct dirent **cat, **list;
	int ncat, nlist, i, j;
	char tmp[PATH_MAX];
	struct stat sb;

	if ((ncat = scandir(path, &cat, checkskip, alphasort)) < 0)
		err(1, "%s", path);

	for (i = 0; i < ncat; i++) {
		(void)snprintf(tmp, sizeof(tmp), "%s/%s", path, cat[i]->d_name);
		if (stat(tmp, &sb) < 0 || !S_ISDIR(sb.st_mode))
			continue;
		nlist = scandir(tmp, &list, checkskip, alphasort);
		for (j = 0; j < nlist; j++) {
			(void)snprintf(tmp, sizeof(tmp), "%s/%s/%s/work", path,
			    cat[i]->d_name, list[j]->d_name);
			if (stat(tmp, &sb) < 0 || !S_ISDIR(sb.st_mode))
				continue;
			printf("Deleting %s\n", tmp);
			if (fork() == 0) {
				(void)execl("/bin/rm", "-rf", tmp, NULL);
			}
			free(list[j]);
		}
		free(cat[i]);
	}
	free(list);
	free(cat);
}

static int
checkskip(const struct dirent *dp)
{
	char *p, *t, *save;

	if ((save = t = strdup(skip)) == NULL)
		err(1, "strdup");
	while ((p = strsep(&t, ":")) != NULL) {
		if (strcmp(dp->d_name, p) == 0) {
			free(save);
			return 0;
		}
	}
	free(save);
	return 1;
}
