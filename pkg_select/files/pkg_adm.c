/*
 * Copyright (c) 2005
 *      iMil <imil@gcu.info>.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by iMil.
 * 4. Neither the name of the author nor the names of any co-contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY iMil AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL iMil OR THE VOICES IN HIS HEAD
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $Id: pkg_adm.c,v 1.2 2005/02/22 09:52:39 imilh Exp $ 
 */

#include "pkg_select.h"
#include <sys/utsname.h>

struct pkg_info {
	char *pkgname;
	char *pkgversion;
	char *pkgcategory;
};

static struct dirent **pkgdb_dirent;
static struct pkg_info **pkgdb;
static int count;

static struct pkg_info *loadpkginfo(char *);

void
free_pkgdb()
{
	int i;
	for (i = 0; i < count; i++) {
		XFREE(pkgdb[i]->pkgcategory);
		XFREE(pkgdb[i]->pkgname);
		XFREE(pkgdb[i]);
		XFREE(pkgdb_dirent[i]);
	}
	XFREE(pkgdb_dirent);
	XFREE(pkgdb);
}

void
load_pkgdb()
{
	int i;

	if ((count = scandir(pkg_dbdir, &pkgdb_dirent, NULL, NULL)) < 0 )
		err(EXIT_FAILURE, "scandir");

	XMALLOC(pkgdb, (count + 1) * sizeof(struct pkg_info *));
	for (i = 0; i < count; i++) {
		pkgdb[i] = loadpkginfo(pkgdb_dirent[i]->d_name);

		/* extract version from pkg_dbdir/package name */
		pkgdb[i]->pkgversion = strrchr(pkgdb_dirent[i]->d_name, '-');
		if (pkgdb[i]->pkgversion != NULL)
			(pkgdb[i]->pkgversion)++;
	}
}

void
reload_pkgdb()
{
	free_pkgdb();
	load_pkgdb();
}

char *
getpkginfo(char *pkg, int info_type)
{
	int i;

	for (i = 0; i < count; i++) {
		if (pkgdb[i]->pkgversion != NULL &&
		    pkgdb[i]->pkgname != NULL)
			if (strcmp(pkg, pkgdb[i]->pkgname) == 0)
				switch (info_type) {
				case PKG_VERSION:
					return(pkgdb[i]->pkgversion);
					break;
				case PKG_CATEGORY:
					return(pkgdb[i]->pkgcategory);
					break;
				}
	}
	return(NULL);
}

/* return a NULL terminated list for make show-var command */
char **
show_var(char *path, const char *varname, int split)
{
	FILE *fp;
	int len;
	char *rawlist, *praw, **list, buf[MAXLEN];

	snprintf(buf, MAXLEN, "cd %s && %s show-var VARNAME=%s",
		 path, MAKE, varname);
	
	if ((fp = popen(buf, "r")) == NULL)
		return(NULL);

	while (fgets(buf, MAXLEN, fp) != NULL)
		strncpy(buf, buf, MAXLEN);

	pclose(fp);

	if (*buf == '\0' || *buf == '\n')
		return(NULL);

	XSTRDUP(rawlist, buf);
	if (split == T_FALSE) {
		XMALLOC(list, 2);
		list[0] = rawlist;
		list[1] = NULL;

		return(list);
	}
	praw = rawlist;

	if (praw != NULL) {
		/* annoying little space before depend list */
		if (*praw == ' ')
			praw++;
		/* annoying little \n at EOL */

		len = strlen(praw) - 1;
		if (praw[len] == '\n')
			praw[len] = '\0';
		
	} else {
		XFREE(rawlist);
		return(NULL);
	}
	list = splitstr(praw, " ");
	XFREE(rawlist);

	return(list);
}

/* return first item from make show-var */
char *
show_first_var(char *path, const char *varname)
{
	char **tlist, *ret;

	tlist = show_var(path, varname, T_FALSE);
	ret = NULL;

	if (tlist != NULL && *tlist != NULL) {
		trimcr(*tlist);
		XSTRDUP(ret, *tlist);
		XFREE(*tlist);
		XFREE(tlist);

		if (*ret == '\0')
			/* XFREE set pointer to NULL */
			XFREE(ret);
	}

	return(ret);
}

void
build_pkg_path(char *pkg_path)
{
	struct utsname u;

        if (uname(&u) != 0) {
                err(EXIT_FAILURE, "uname");
                /* NOTREACHED */
        }
	snprintf(pkg_path, MAXLEN, "%s/%s/%s/All", 
		 DEFAULT_PKG_PATH, u.release, u.machine);
}

static struct pkg_info *
loadpkginfo(char *pkg)
{
	int i;
	struct pkg_info *ret;
	char **file, *tmp, buf[MAXLEN];

	XMALLOC(ret, sizeof(struct pkg_info));
	ret->pkgname = NULL;
	ret->pkgcategory = NULL;

	snprintf(buf, MAXLEN, "%s/%s/+BUILD_INFO", pkg_dbdir, pkg);

	file = loadfile(buf);
	if (file == NULL)
		return(ret);

	for (i = 0; file[i] != NULL; i++) {
		if (strncmp(file[i], "PKGPATH=", 8) == 0) {
			/* files coming from file have \n's */
			trimcr(file[i]);
			tmp = strchr(file[i], '=');
			if (tmp != NULL) {
				tmp++;
				XSTRDUP(ret->pkgcategory, tmp);
			}
			tmp = strchr(file[i], '/');
			if (tmp != NULL) {
				tmp++;
				XSTRDUP(ret->pkgname, tmp);
			}

			break; /* no need to go further */
		}
	}
	freefile(file);
	return(ret);
}
