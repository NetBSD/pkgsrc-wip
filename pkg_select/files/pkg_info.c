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
 * $Id: pkg_info.c,v 1.2 2005/02/22 09:52:41 imilh Exp $ 
 */

#include "pkg_select.h"

static int show_pkgfile(WINDOW *, char *, const char *);
static void pkg_popup(WINDOW *, char *, char *, 
		      const char *, const char *, const char *);
static void pkg_depends(char *, const char *);

static int
show_pkgfile(WINDOW *win, char *path, const char *file)
{
	char buf[MAXLEN];

	snprintf(buf, MAXLEN, "%s/%s", path, file);
	/* if 'q' was pressed, return 0 so we quit */
	return(more_file(win, buf, LINES - 2, COLS - 2, 1, 1));
}

static void
pkg_popup(WINDOW *win, char *path, char *pkg, 
	  const char *label, const char *msg, const char *action)
{
	int len;
	char rep, *env, pkg_path[MAXLEN];

	len = strlen(msg) + 4;
	rep = getch_popup(label, msg, 
			  5, len, 
			  (LINES / 2) - 2, (COLS / 2) - (len / 2));

	if (rep != 'n') {
		wclear(win);
		wrefresh(win);

		/* recursive pkg_delete was asked */
		if (*action == 'd' && rep == 'r')
			PKG_TOOL("delete", pkg, "-r");

		/* make action */
		if ((*action == 'i' || *action == 'u' || *action == 'd') && 
		    (rep != 'r'))
				PKGSRC_MAKE(action, path);

		/* pkg_* action */
		if (*action == 'a') {
			env = getenv("PKG_PATH");
			if (env == NULL) {
				build_pkg_path(&pkg_path[0]);
				mvwprintw(win, 0, 0, 
					"PKG_PATH variable not set, default to\n%s\n", pkg_path);
				setenv("PKG_PATH", pkg_path, 1);
				wprintw(win, ANY_KEY);
				(void) wgetch(win);

				wclear(win);
				wrefresh(win);
			}
			PKG_TOOL(action, "", pkg);
		} /* answer was yes */

		wclear(win);
		wrefresh(win);
	}
}

static void
pkg_depends(char *path, const char *varname)
{
	int len;
	char **list;
	WINDOW *popup;
	char buf[MAXLEN];

	snprintf(buf, MAXLEN, "%s %s", PLEASE_WAIT_CALC, varname);
	len = strlen(buf) + 4;
	
	popup = info_popup("information", buf, 
			   5, len, 
			  (LINES / 2) - 2, (COLS / 2) - (len / 2));
	wrefresh(popup);

	list = show_var(path, varname, T_TRUE);
	/* enter main_loop */
	nodir_loop(path, list);

	free_list(&list);
	delwin(popup);
}

int
info_win(WINDOW *win, char *pkg, char *path)
{
	int ret, c, line_index, msv, len;
	struct cf *file;
	char buf[MAXLEN], *homepage, *comment, *distname, *version;
	WINDOW *popup;

	snprintf(buf, MAXLEN, "%s/MESSAGE", path);

	/* info window needs all screen */
	wresize(win, LINES - 2, COLS - 2);
	
	for (;;) {
		/* load Makefile* */
		file = load_makefile(path, FULL);

		line_index = 2;

		/* redraw box and title */
		draw_box(win, path);

		mvwprintw(win, line_index, 2, PKG_ADMIN_INFO);
		wattroff(win, A_BOLD);
		line_index += 2;

		/* get values from Makefile slist */
		distname = getval(file, "DISTNAME=");
		homepage = getval(file, "HOMEPAGE=");
		comment = getcomment(file);
		
		msv = 0;
		/* one or more members could not be read from Makefile 
		 * use make show-var to fill all of them
		 */
		if (distname == NULL || comment == NULL) {
			len = strlen(SEARCH_INFOS) + 4;

			/* this cound take a moment, warn user */
			popup = info_popup("information", 
					   SEARCH_INFOS, 
					   5, len, 
					   (LINES / 2) - 2, 
					   (COLS / 2) - (len / 2));
			wrefresh(popup);

			distname = show_first_var(path, "DISTNAME");
			homepage = show_first_var(path, "HOMEPAGE");
			comment = show_first_var(path, "COMMENT");
			/* set make show-var variable */
			msv = 1;

			delwin(popup);
		}

		if (distname == NULL) {
			wprint_kb(win, "package:", "none", line_index, 2);
		} else
			wprint_kb(win, "distname:", distname, line_index, 2);
		line_index++;

		if ((version = getpkginfo(pkg, PKG_VERSION)) != NULL)
			wprint_kb(win, "installed:", version, line_index, 2);
		else
			wprint_kb(win, "installed:", "none", line_index, 2);
		line_index++;

		if (homepage == NULL) {
			wprint_kb(win, "homepage:", "none", line_index, 2);
		} else
			wprint_kb(win, "homepage:", homepage, line_index, 2);
		line_index++;

		if (comment == NULL)
			wprint_kb(win, "comment:", "none", line_index, 2);
		else {
			/* 7 == strlen("comment:") + 2 borders + 
			   "..." + 2 spaces */
			cut_str(comment, COLS - 17);
			wprint_kb(win, "comment:", comment, line_index, 2);
		}
		line_index += 2;
		
		wprint_kb(win, "[m]", "show package description", 
			  line_index, 2);
		line_index++;

		if (file_exists(buf)) {
			wprint_kb(win, "[v]", 
				  "view package message", line_index, 2);
			line_index++;
		}

		wprint_kb(win, "[e]", "show package dependancies",
			  line_index, 2);
		line_index += 2;

		wprint_kb(win, "[i]", "build and install package",
			  line_index, 2);
		line_index++;
		wprint_kb(win, "[u]", "build and upgrade package",
			  line_index, 2);
		line_index++;

		wprint_kb(win, "[b]", "install binary package", line_index, 2);
		line_index++;

		wprint_kb(win, "[d]", "de-install package", line_index, 2);

		wprint_kb(win, "[<-]", "back", LINES - BOTTOM_KB, 2);
		wprint_kb(win, "[q]", "quit", LINES - BOTTOM_KB, 14);
	
		/* we got infos from make show-var, must free */
		if (msv) {
			XFREE(distname);
			XFREE(homepage);
			XFREE(comment);
		}
	
		c = wgetch(win);
		switch (c) {
		case 'm':
			ret = show_pkgfile(win, path, "DESCR");
			if (!ret)
				/* quit was asked */
				return(ret);
			break;
		case 'v':
			ret = show_pkgfile(win, path, "MESSAGE");
			if (!ret)
				/* quit was asked */
				return(ret);
			break;
		case 'i':
			pkg_popup(win, path, pkg, 
				  "Install package", 
				  "build and install package ? [Y/n]",
				  "install");
			break;
		case 'u':
			pkg_popup(win, path, pkg, 
				  "Upgrade package", 
				  "build and upgrade package ? [Y/n]",
				  "update");
			break;
		case 'd':
			pkg_popup(win, path, pkg, 
				  "De-install package", 
				  "de-install package ? [Y/n/r(ecursive)]",
				  "deinstall");
			break;
		case 'b':
			pkg_popup(win, path, pkg, 
				  "Install package",
				  "install binary package ? [Y/n]",
				  "add");
			break;
		case 'e':
			pkg_depends(path, "DEPENDS");
			/* back from main_loop, resize */
			wresize(win, LINES - 2, COLS - 2);

			break;
		case 'q':
			/* if we are on a depend list, we want a clean exit */
			freecf(file);
			return(IN_QUIT);

			break;
		case KEY_LEFT:
			freecf(file);
			return(1);
			break;
		}

	}
	/* NOTREACHED */
	return(1);
}
