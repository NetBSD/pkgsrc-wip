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
 * $Id: pkg_adm.c,v 1.3 2005/03/15 17:14:25 imilh Exp $ 
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
build_pkg_path(char *pkg_path, char *base)
{
	struct utsname u;
	char *p, release[MAXLEN];

        if (uname(&u) != 0) {
                err(EXIT_FAILURE, "uname");
                /* NOTREACHED */
        }
	strcpy(release, u.release);
	/* remove any _XX extension */
	if ((p = strchr(release, '_')) != NULL)
		*p = '\0';
	else
		p = release;

	snprintf(pkg_path, MAXLEN, "%s/packages/%s/%s/All", 
		 base, release, u.machine);
}

void
set_pkg_path(const char *conf_pkg_path)
{
	char *env, pkg_path[MAXLEN];

	env = getenv("PKG_PATH");
	if (env == NULL) {
		char *base;
		
		/* call curses select combo */
		if (conf_pkg_path == NULL)
			base = list_mirrors("ftp");
		else
			XSTRDUP(base, conf_pkg_path);
		
		build_pkg_path(&pkg_path[0], base);
		XFREE(base);
		setenv("PKG_PATH", pkg_path, 1);
	}
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

static const char *make_inst_progress[] = MAKE_INST_PROGRESS;
static const char *make_updt_progress[] = MAKE_UPDT_PROGRESS;
static const char *make_deinst_progress[] = MAKE_DEINST_PROGRESS;

void
pkgsrc_make(const char *action, const char *path, int waitkey)
{
	char *env;
	const char **make_progress;

	switch (*action) {
	case 'i':
		make_progress = make_inst_progress;
		break;
	case 'd':
		make_progress = make_deinst_progress;
		break;
	case 'u':
		make_progress = make_updt_progress;
		break;
	}

	/* if PKG_PATH exists, unset it for make */
	if ((env = getenv("PKG_PATH")) != NULL)
		unsetenv("PKG_PATH");

	(void) cmd_spawn(waitkey, make_progress,
			 "cd %s && %s %s %s",
			 path, MAKE, action, "clean");

	/* restore PKG_PATH */
	if (env != NULL)
		setenv("PKG_PATH", env, 1);
	reload_pkgdb();
}

static const char *pkg_add_progress[] = PKG_ADD_PROGRESS;
static const char *pkg_del_progress[] = PKG_DEL_PROGRESS;

void
pkg_tool(const char *action, const char *pkg, const char *option, int waitkey)
{
	const char **tool_progress;

	switch (*action) {
	case 'a':
		tool_progress = pkg_add_progress;
		break;
	case 'd':
		tool_progress = pkg_del_progress;
		break;
	}

	(void) cmd_spawn(waitkey, tool_progress,
			 "%s/pkg_%s %s %s 2>&1",
			 PKGTOOLS_PATH, action, option, pkg);
	reload_pkgdb();
}
