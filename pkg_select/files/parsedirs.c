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
 * $Id: parsedirs.c,v 1.3 2005/02/21 14:11:26 poppnk Exp $ 
 */

#include "pkg_select.h"

#if __NetBSD__
#define DIRENT const struct dirent
#else
#define DIRENT struct dirent
#endif

static int checkskip(DIRENT *);
static int partialmatch(const char *, const char *);

/* from pkgfind */
static const char *skip[] = {
        ".", "..", "CVS", "bootstrap", "doc", "cross", "mk", 
	"distfiles", "packages", "licenses", "templates", NULL
};

static struct dirent **dlist;
static int count;

static int
checkskip(DIRENT *dp)
{
        const char **p;

        for (p = skip; *p != NULL; p++)
                if (strcmp(dp->d_name, *p) == 0)
                        return 0;
        return 1;
}

Etree **
get_tree(const char *path, int where)
{
	int i, j, deepness;
	struct stat sb;
	struct cf *file;
	Etree **etree;
	char buf[MAXLEN], **tmp, *p;

	/* check if we are browsing a directory */
	if (stat(path, &sb) < 0)
		return(NULL);
	if ((sb.st_mode & S_IFMT) != S_IFDIR)
		return(NULL);

	if ((count = scandir(path, &dlist, checkskip, alphasort)) < 0)
		err(EXIT_FAILURE, "%s", path);

	if (count == 0)
		return(NULL);

	/* we donc want to recurse on pkgsrc-wip */
	if (strstr(path, "/wip") != NULL)
		deepness = ONE_LEVEL;
	else
		deepness = PARTIAL;


	XMALLOC(etree, count * sizeof(Etree *));
	/* NULL every line */
	for (i = 0; i < count; i++)
		etree[i] = NULL;

	/* map list to an array */
	for (i = 0, j = 0; i < count; i++, j++) {
		/* DESCR found, we are in a package dir */
		if (strcmp(dlist[i]->d_name, "DESCR") == 0) {
			etree[j] = NULL;
			free_tree(&etree);
			return(NULL);
		}

		/* check if entry is a directory */
		snprintf(buf, MAXLEN, "%s/%s", path, dlist[i]->d_name);

		if ((stat(buf, &sb) < 0) || !S_ISDIR(sb.st_mode)) {
			j--;
			continue;
		}

		XMALLOC(etree[j], sizeof(Etree));
		/* unused here */
		etree[j]->dep_path = NULL;

		if (where == IN_PKGSRC) {
			etree[j]->entry = dlist[i]->d_name;
			file = load_makefile(buf, deepness);
			etree[j]->comment = getcomment(file);
			freecf(file);
		} else {
			snprintf(buf, MAXLEN, "%s/%s/+COMMENT", 
				 pkg_dbdir, dlist[i]->d_name);
			tmp = loadfile(buf);
			if (tmp != NULL && tmp[0] != NULL)
				XSTRDUP(etree[j]->comment, tmp[0]);
			else
				XSTRDUP(etree[j]->comment, NOCOMMENT);
			freefile(tmp);

			p = strrchr(etree[j]->comment, '\n');
			if (p != NULL)
				*p = '\0';

			p = strrchr(dlist[i]->d_name, '-');
			if (p != NULL)
				*p = '\0';
			etree[j]->entry = dlist[i]->d_name;
		}
	}
	etree[j] = NULL;

	return(etree);
}

void
free_tree(Etree ***etree)
{
	int i;
	Etree **ptree;

	/* free dirent's */
	if (dlist != NULL) {
		for (i = 0; i < count; i++)
			XFREE(dlist[i]);
		XFREE(dlist);
	}

	if (*etree != NULL) {
		ptree = *etree;
		for (i = 0; ptree[i] != NULL; i++) {
			XFREE(ptree[i]->comment);
			XFREE(ptree[i]);
		}
		XFREE(*etree);
	}
}

Etree **
get_nodir_tree(const char *path, char **list)
{
	int i;
	char *p, pkgdep[MAXLEN];
	Etree **etree;
	struct cf *file;

	if (list == NULL)
		return(NULL);

	for (i = 0; list[i] != NULL; i++);
	count = i;

	XMALLOC(etree, (count + 1) * sizeof(Etree *));

	for (i = 0; i < count; i++) {
		XMALLOC(etree[i], sizeof(Etree));

		p = strchr(list[i], ':');
		if (p != NULL) {
			snprintf(pkgdep, MAXLEN, "%s/%s", path, ++p);
			XSTRDUP(etree[i]->dep_path, p);
			p = strrchr(etree[i]->dep_path, '/');
			if (p != NULL) {
				p++;
				XSTRDUP(etree[i]->entry, p);
			}
			file = load_makefile(pkgdep, PARTIAL);
			etree[i]->comment = getcomment(file);
			freecf(file);
		}
	}
	etree[i] = NULL;

	return(etree);
}

void
free_nodir_tree(Etree ***etree)
{
	int i;
	Etree **ptree;

	if (*etree != NULL) {
		ptree = *etree;
		for (i = 0; ptree[i] != NULL; i++) {
			XFREE(ptree[i]->entry);
			XFREE(ptree[i]->dep_path);
			XFREE(ptree[i]->comment);
			XFREE(ptree[i]);
		}
		XFREE(*etree);
	}
}

/* adaptation from Peter Postma's pkgfind */
char **
pkgfind(const char *path, const char *pkg, int nres)
{
        struct dirent **cat, **list;
        int ncat, nlist, i, j, k, called;
        char tmp[MAXLEN];
        char *text;
	static char **reslist = NULL;
        struct stat sb;

	if (!isalnum((int)pkg[0]))
		return(NULL);

        if ((ncat = scandir(path, &cat, checkskip, alphasort)) < 0)
		return(NULL);

	k = 0;
	if (nres > 0) {
		XMALLOC(reslist, (nres + 1) * sizeof(char *));
		called = T_TRUE;
	} else
		called = T_FALSE;

        for (i = 0; i < ncat; i++) {
                if (snprintf(tmp, sizeof(tmp), "%s/%s", path, cat[i]->d_name)
                    >= sizeof(tmp)) {
                        warnx("filename too long");
                        continue;
                }
                if (stat(tmp, &sb) < 0 || !S_ISDIR(sb.st_mode))
                        continue;
                if ((nlist = scandir(tmp, &list, checkskip, alphasort)) < 0) {
                        warn("%s", tmp);
                        continue;
                }
                for (j = 0; j < nlist; j++) {
                        if (snprintf(tmp, sizeof(tmp), "%s/%s/%s", path,
				     cat[i]->d_name, list[j]->d_name) >= sizeof(tmp)) {
                                warnx("filename too long");
                                continue;
                        }
                        if (stat(tmp, &sb) < 0 || !S_ISDIR(sb.st_mode))
                                continue;
			
			text = list[j]->d_name;
			/* match */
                        if (partialmatch(text, pkg)) {
				if (called == T_FALSE)
					nres++;
				else {
					snprintf(tmp, MAXLEN, 
						 ":%s/%s",
						 cat[i]->d_name, 
						 list[j]->d_name);

					XSTRDUP(reslist[k], tmp);
					k++;
				}
			}
			/*  showpkg(path, cat[i]->d_name, list[j]->d_name);*/
                        free(list[j]);
                }
                free(cat[i]);
        }
        free(list);
        free(cat);
	
	if (called == T_FALSE) {
		if (nres == 0)
			return(NULL);

		return(pkgfind(path, pkg, nres));
	}
	reslist[k] = NULL;

	return(reslist);
}

static int
partialmatch(const char *s, const char *find)
{
        size_t len, n;

        len = strlen(find);
        n = strlen(s) - len;

        do {
           if (strncasecmp(s, find, len) == 0)
		   return 1;
        } while (*++s != '\0' && n-- > 0);

        return 0;
}
