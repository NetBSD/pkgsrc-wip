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
 * $Id: live.c,v 1.1 2005/03/15 17:14:25 imilh Exp $ 
 */

#include "pkg_select.h"

struct ftp_data {
	char *entry;
	SLIST_ENTRY(ftp_data) next;
};

static Etree **build_tree_from_slist(void);
/*static char **build_list_from_slist(void);*/
static void free_ftp_data(void);
static char *ftp_get(const char *, const char *);
static void free_tmpfile(char *);
static T_Bool is_ftpdir(const char *);
static T_Bool ftpdir_has_descr(void);

static const char *skip[] = { "CVS", "INDEX", "Makefile", "Packages.txt", 
			      "README", "licenses", "mk", "bootstrap", 
			      "doc", "distfiles", NULL };
static SLIST_HEAD(, ftp_data) top = SLIST_HEAD_INITIALIZER(top);
static int count = 0;
static int is_connected = 0;

int
is_ftpurl(const char *url)
{
	if (strncmp(url, "ftp://", 6) == 0)
		return(T_TRUE);
	else
		return(T_FALSE);
}

int
ftp_connected()
{
	return(is_connected);
}

int
ftp_info_start(char *url)
{
	WINDOW *popup;
	int len;

	len = strlen(url) - 1;
	/* force to have a 250 code as ftpio doesn't like 200's */
	if (url[len] != '/')
		XSTRCAT(url, "/./");
	else
		XSTRCAT(url, "./");

	if (conf.shell_output)
		endwin();
	else {
		popup = mid_info_popup("ftp", 
				       "negociation with ftp server...");
		wrefresh(popup);
	}
		
	if (ftp_start(url) < 0) {
		if (!conf.shell_output)
			clr_del_win(popup);
		warn("ftp connection failed");
		return(-1);
	}
	
	if (!conf.shell_output)
		clr_del_win(popup);
	return(0);
}

/* ftpio callback */
void
fill_store(char *item)
{
	struct ftp_data *ls;

	XMALLOC(ls, sizeof(struct ftp_data));
	/* entry holds the line */
	XSTRDUP(ls->entry, item);

	SLIST_INSERT_HEAD(&top, ls, next);
	count++;
}

static T_Bool
is_ftpdir(const char *line)
{
	if (line != NULL && strncmp(line, "dr", 2) == 0)
		return(T_TRUE);

	return(T_FALSE);
}

static T_Bool
ftpdir_has_descr(void)
{
	struct ftp_data *ls;

	SLIST_FOREACH(ls, &top, next)
		if (strstr(ls->entry, "DESCR") != NULL)
			return(T_TRUE);

	return(T_FALSE);
}

static Etree **
build_tree_from_slist()
{
	int i;
	char *p;
	struct ftp_data *ls;
	struct Etree **etree;

	count = 0; /* count valid ls entries */
	SLIST_FOREACH(ls, &top, next)
		if (is_ftpdir(ls->entry)) {
			/* point to category or pkg name 
			 * received: 
			 * drwxr-xr-x    20 0     0    512 Jan 19 13:50 pkg
			 */
			p = strrchr(ls->entry, ' ');
			p++;
			
			if (!is_listed(skip, p))
				/* item is not a member of the skip list */
				count++;
		}
		 

	XMALLOC(etree, (count + 1) * sizeof(Etree *));

	i = count;
	etree[i] = NULL;
	/* redo, now fill */
	SLIST_FOREACH(ls, &top, next) {
		if (is_ftpdir(ls->entry)) {

			p = strrchr(ls->entry, ' ');
			p++;
			
			if (!is_listed(skip, p)) {
				i--;
				XMALLOC(etree[i], sizeof(Etree));
				XSTRDUP(etree[i]->entry, p);
				etree[i]->dep_path = NULL;
			}
		}
	}

	return(etree);
}

void
pasv_ftp()
{
	if (getenv("FTP_PASSIVE_MODE") == NULL &&
	    mid_getch_popup("ftp mode", "(a)ctive or (p)assive ftp ?") == 'p')
		setenv("FTP_PASSIVE_MODE", "yes", 1);
}

static char *
ftp_get(const char *path, const char *file)
{
	int rc;
	char *tmppath, cmd[MAXLEN];

	XMALLOC(tmppath, MIDLEN * sizeof(char));

	snprintf(tmppath, MAXLEN, "%s/%s.pkg_select", TMPDIR, file);

	snprintf(cmd, MAXLEN, "cd %s\n", path);
	if ((rc = ftp_cmd(cmd, "\n(550|250).*\n")) != 250)
		return(NULL);

	snprintf(cmd, MAXLEN, "get %s %s\n", file, tmppath);
	if ((rc = ftp_cmd(cmd, "\n(550|226).*\n")) != 226)
		return(NULL);

	if (!file_exists(tmppath))
		return(NULL);

	return(tmppath);
}

static void
free_tmpfile(char *file)
{
	(void) unlink(file); /* remove file if any */
	XFREE(file);
}

char **
ftp_loadfile(const char *path, const char *file)
{
	char **ret, *tmppath;

	if ((tmppath = ftp_get(path, file)) == NULL)
		return(NULL);
	ret = loadfile(tmppath);
	free_tmpfile(tmppath);
	
	return(ret);
}

struct cf *
ftp_loadcf(const char *path, const char *file)
{
	struct cf *ret;
	char *tmppath;

	if ((tmppath = ftp_get(path, file)) == NULL)
		return(NULL);
	ret = loadcf(tmppath, NULL);
	free_tmpfile(tmppath);

	return(ret);
}

Etree **
live_ftp(const char *base)
{
	int i;
	Etree **etree;
	struct cf *file;
	WINDOW *popup;
	char url[MAXLEN], cmd[MAXLEN], *comment, *path;

	if (base == NULL)
		return(NULL);

	if (!is_ftpurl(base)) /* base is not a full url */
		snprintf(url, MAXLEN, "%s/%s", conf.live_ftp, base);
	else
		XSTRCPY(url, base);

	if (!is_connected)
		pasv_ftp();
		
	if (ftp_info_start(&url[0]) < 0)
		return(NULL);
	else
		/* 1st pass */
		is_connected = 1;

	/* point to relative path for further relocation */
	path = &url[6];
	path = strchr(path, '/');

	/* listing */
	if (ftp_cmd("ls\n:store_expect", "\n(550|226).*\n") != 226)
		return(NULL);

	if (ftpdir_has_descr()) { /* ls has DESCR in it */
		free_ftp_data();
		return(NULL);
	}

	etree = build_tree_from_slist();

	free_ftp_data(); /* release slist */

	if (!conf.live_ftp_read_makefiles) {
		for (i = 0; etree[i] != NULL; i++)
			XSTRDUP(etree[i]->comment, "no comment.");

		ftp_stop();
		return(etree);
	}

	/* comments */
	popup = mid_info_popup("ftp", "reading Makefiles...");
	wrefresh(popup);

	for (i = 0; etree[i] != NULL; i++) {

		file = ftp_loadcf(etree[i]->entry, "Makefile");

		snprintf(cmd, MAXLEN, "cd %s\n", path);
		/* return to parent directory */
		ftp_cmd(cmd, "\n(250|550).*\n");

		if ((comment = getval(file, "COMMENT=")) != NULL)
			XSTRDUP(etree[i]->comment, comment);
		else {
			int j;

			XFREE(etree[i]->entry);
			XFREE(etree[i]);

			for (j = i; etree[j + 1] != NULL; j++)
				etree[j] = etree[j + 1];

			etree[j] = NULL;
			i--;
		}

		freecf(file); /* release list */
	}

	clr_del_win(popup);
	ftp_stop();

	return(etree);
}

static void
free_ftp_data()
{
	struct ftp_data *p;

	while (!SLIST_EMPTY(&top)) {
		p = SLIST_FIRST(&top);
		SLIST_REMOVE_HEAD(&top, next);
		XFREE(p->entry);
		XFREE(p);
	}

}
