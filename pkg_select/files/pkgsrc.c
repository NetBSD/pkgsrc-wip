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
 * $Id: pkgsrc.c,v 1.1 2005/03/15 17:14:26 imilh Exp $ 
 */

#include "pkg_select.h"

#define CVS_CMD "/usr/bin/cvs"
#define CHECKOUT 0
#define UPDATE 1

const char *current = "pkgsrc-current";

static char **build_mirror_list(const char *);
static int ftp_fetch(const char *, const char *);
static int cvs_fetch(const char *, const char *, int);
static char *get_cvs_branch(const char *, int);

static char **
build_mirror_list(const char *method)
{
	char **list, path[MAXLEN];
	struct stat sb;

	snprintf(path, MAXLEN, "%s/mirrors.%s", MIRRORS, method);

	if (stat(path, &sb) < 0)
		return(NULL);

        list = loadfile(path);

	if (list == NULL)
		return(NULL);

	return(list);
}

char *
list_mirrors(const char *method)
{
	Etree **etree;
	char *ret, **list;

	if (*method == 'f')
		if (conf.ftp_mirror != NULL)
			return(strdup(conf.ftp_mirror));
	if (*method == 'c')
		if (conf.cvs_mirror != NULL)
			return(strdup(conf.cvs_mirror));

	if ((list = build_mirror_list(method)) == NULL)
		return(NULL);
	if ((etree = build_tree_from_list(list)) == NULL) {
		free_list(&list);
		return(NULL);
	}

	free_list(&list);
	/* ret is malloc'ed */
	ret = combo_select(etree, "Choose mirror", 
			   LINES - 4, COLS - 2, 1, 1, 1);
	free_nodir_tree(&etree);

	return(ret);
}

int
pkgsrc_chk(const char *path)
{
	int rc, len;
	struct stat sb;
	char resp, *mirror, *p, bpath[MAXLEN], message[MAXLEN];

	/* check if we are browsing a directory */
	if (stat(path, &sb) > -1 && 
	    (sb.st_mode & S_IFMT) == S_IFDIR &&
	    strstr(path, "pkgsrc") != NULL)
		/* pkgsrc exists, return */
		return(0);

	snprintf(message, MAXLEN, PKGSRC_NOTFOUND, path );
	resp = mid_getch_popup("No pkgsrc", message);

	if (resp == 'n')
		return(-1);

	strcpy(bpath, path);
	/* NULL last '/' if any */
	len = strlen(bpath);
	if (bpath[len - 1] == '/')
		bpath[len - 1] = '\0';
	/* in case user set a bad path, rewind to last / */
	if ((p = strrchr(bpath, '/')) == NULL)
		/* no / ?? set p to curdir */
		strcpy(bpath, "./");
	else
		*(++p) = '\0';

	do {
		resp = mid_getch_popup("Download method", DL_METHOD);

		switch(resp) {
		case 'f':
			if ((mirror = list_mirrors("ftp")) != NULL)
				rc = ftp_fetch(mirror, bpath);
			break;
		case 'c':
			if ((mirror = list_mirrors("cvs")) != NULL)
				rc = cvs_fetch(mirror, bpath, CHECKOUT);
			break;
		}

		if (mirror == NULL || rc < 0) {
			resp = mid_getch_popup("fetch failed", 
					       FETCH_FAILED);
			/* don't try again */
			if (resp == 'n')
				break;
			/* free mirror and retry */
			XFREE(mirror);
		}

	} while (mirror == NULL || rc < 0);

	if (mirror == NULL)
		return(-1);

	XFREE(mirror);

	return(rc);
}

/* fetch pkgsrc by ftp */
static int
ftp_fetch(const char *base, const char *dir)
{
	char url[MAXLEN], cmd[MAXLEN];
	WINDOW *popup;

	pasv_ftp();

	snprintf(url, MAXLEN, "%s/NetBSD-current/tar_files/", base);

	popup = mid_info_popup("ftp", "connecting to ftp server...");
	wrefresh(popup);

	if (conf.shell_output)
		endwin();

	if (ftp_start(url) < 0) {
		clr_del_win(popup);
		return(-1);
	}

	clr_del_win(popup);

	/* mostly ripped from libinstall's extractURL() */
	(void) snprintf(cmd, sizeof(cmd), 
				"get pkgsrc.tar.gz \"| ( cd %s ; gunzip 2>/dev/null | " TAR_CMD " -%sx -f - 2>&1 )\"\n", dir, "vv");

	if (ftp_cmd(cmd, "\n(226|550).*\n") != 226) {
		warnx("Cannot fetch file !");
		return -1;
	}
	ftp_stop();

	return(0);
}

static char *
get_cvs_branch(const char *anoncvs, int mode)
{
	int i, j;
	Etree **etree;
	char *p, *branch, cmd[MAXLEN] = "", **list, **branchlist;

	if (mode == CHECKOUT)
		snprintf(cmd, MAXLEN, "%s%s -d %s rlog -l -h pkgsrc/Makefile", 
			 cmd, CVS_CMD, anoncvs);
	if (mode == UPDATE)
		snprintf(cmd, MAXLEN, "%s%s -d %s log -l -h Makefile", 
			 cmd, CVS_CMD, anoncvs);

	if ((list = exec_list(cmd, "pkgsrc")) == NULL)
		return(NULL);

	for (i = 0; list[i] != NULL; i++);
	XMALLOC(branchlist, (i + 1) * sizeof(char *));

	XSTRDUP(branchlist[0], current);
	/* show only valid branches */
	for (i = 0, j = 1; list[i] != NULL; i++) {
		/* only match pkgsrc-YYYYQX*/
		if (strncmp(list[i], "pkgsrc", 6) == 0 && 
		    strstr(list[i], "base") == NULL) {
			trimcr(list[i]);

			for (p = list[i]; *p; p++)
				if (*p == ':')
					*p = ',';
					
			XSTRDUP(branchlist[j], list[i]);
			j++;
		}
	}

	branchlist[j] = list[i];
	free_list(&list);
	
	if ((etree = build_tree_from_list(branchlist)) == NULL) {
		free_list(&branchlist);
		return(NULL);
	}

	branch = combo_select(etree, "Choose a branch", 
			      LINES - 4, COLS - 2, 1, 1, 1);
	free_nodir_tree(&etree);

	return(branch);
}

static const char *pkgsrc_progress[] = PKGSRC_PROGRESS;

/* fetch pkgsrc by cvs */
static int
cvs_fetch(const char *anoncvs, const char *dir, int mode)
{
	WINDOW *popup;
	char *branch, cmd[MAXLEN] = "", *p, rel[MAXLEN] = "";

	if (chdir(dir) < 0)
		err(1, "chdir failed");

	if (strstr(anoncvs, ":pserver:") != NULL)
		/* if it's a pserver, be sure to login */
		snprintf(cmd, MAXLEN, "%s -d %s login && ", CVS_CMD, anoncvs);

	popup = mid_info_popup("cvs", "connecting to cvs server...");
	wrefresh(popup);

	/* select branch */
	if (conf.cvs_branch != NULL)
		XSTRDUP(branch, conf.cvs_branch);
	else
		branch = get_cvs_branch(anoncvs, mode);

	clr_del_win(popup);
	if (branch == NULL)
		return(-1);

	if (strncmp(branch, current, strlen(current)) != 0) {
		if ((p = strchr(branch, ',')) != NULL)
			*p = '\0';
		snprintf(rel, MAXLEN, "-r%s ", branch);
	}

	popup = mid_info_popup("cvs", "comparing trees, please wait...");
	wrefresh(popup);

	if (mode == CHECKOUT)
		snprintf(cmd, MAXLEN, "%s -d %s checkout %spkgsrc 2>&1", 
			 CVS_CMD, anoncvs, rel);
	if (mode == UPDATE)
		snprintf(cmd, MAXLEN, "%s -d %s update -PAd %s 2>&1", 
			 CVS_CMD, anoncvs, rel);

	cmd_spawn(DONT_WAIT, pkgsrc_progress, cmd);
	clr_del_win(popup);
	XFREE(branch);

	return(0);
}

int
cvs_up(const char *dir)
{
	FILE *fp;
	char buf[MAXLEN];
	
	if (chdir(dir) < 0)
                err(1, "chdir failed");

	snprintf(buf, MAXLEN, "%s/CVS/Root", dir);
	if ((fp = fopen(buf, "r")) == NULL)
		return(-1);
	fgets(buf, MAXLEN, fp);
	fclose(fp);
	
	trimcr(buf);
	return(cvs_fetch(buf, dir, UPDATE));
}
