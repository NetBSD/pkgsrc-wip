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
 * $Id: main.c,v 1.2 2005/02/22 09:52:39 imilh Exp $ 
 */

#include <sys/cdefs.h>
#ifndef lint
#if 0
static char *rcsid = "$Id: main.c,v 1.2 2005/02/22 09:52:39 imilh Exp $";
#else
__RCSID("$Id: main.c,v 1.2 2005/02/22 09:52:39 imilh Exp $");
#endif
#endif

#include <stdlib.h>
#include <signal.h>

#include "pkg_select.h"

/* reset hl_index and clear screen */
#define DO_RESET 1
#define DONT_RESET 0

static void usage(void);
static void init_curses(void);
static void init_windows(void);
static void finish(int);
static int dcount(Etree **);
static void clear_tree(Etree ***, int);
static int toplevel(const char *);
static int print_entry(Etree *, HL_datas *, char *, int, int);
static void list_win_refresh(void);
static int print_list(Etree **, HL_datas *, char *, int);
static void print_kb(const char *, const char *, int, int);
static void print_bindings(void);

static int nlines, ncols, top_line;
static WINDOW *list_win;

static void
usage()
{
	(void) fprintf(stderr,
		       "usage: %s [ -b pkgsrcdir ] [-K pkg_dbdir]\n",
		       getprogname());
        exit(1);
}

static void
init_curses()
{
        initscr();
        nonl();
        cbreak();
        noecho();
	curs_set(0);
}

static void
init_windows()
{
	nlines = MAINWIN_LINES;
	ncols = MAINWIN_COLS;
	top_line = 1;
        /* create a window 1 char smaller than term */
        list_win = newwin(nlines + 2, ncols, 1, 1);
}

static void
finish(int sig)
{
	/* do something useful with sig so compiler does not 
	   complain on unused variable (FreeBSD) */
	if (sig)
		sig &= 0;
	/* free dir list */
	free_pkgdb();

	curs_set(1);
	delwin(list_win);
	endwin();
	exit(EXIT_SUCCESS);
}

static int
toplevel(const char *path)
{
	if (strcmp(path, pkgsrcbase) != 0)
		return(0);
	else
		return(1);
}

/* count entries */
static int
dcount(Etree **etree)
{
	int i;

	for (i = 0; etree[i] != NULL; i++);
	i--;

	return(i);
}

/* etree's address is passed so we can NULL **etree */
static void
clear_tree(Etree ***etree, const int where)
{
	if (where == IN_DEPENDS)
		free_nodir_tree(etree);
	else
		free_tree(etree);
}

/* print item + descr, d_index = y + i (relative / delta index) */
static int
print_entry(Etree *item, HL_datas *hl, char *path, int d_index, int y) {

	int i, real_hl;
	int sb_real, sb_y;
	static int last_sb = -1;
	static int delta = 0;
	char buf[MAXLEN], tmp_entry[MAXLEN], status;

#define PS_ALIGN 20

	/* 9 = 3 dots + [\ ]\ \ + scrollbar */
	cut_str(item->comment, ncols - PS_ALIGN - 9);
	/* we don't want to modify pkg name */
	strcpy(tmp_entry, item->entry);
	/* -1 : spaces between entry and comment */
	cut_str(tmp_entry, PS_ALIGN - 8);
	
	/* highlight*/
	real_hl = hl->hl_index + top_line;
	/* delta between hl and old */
	delta = hl->old_index - hl->hl_index;
	
	/* scroll up */
	if ((y == 0) && (delta >= nlines)) {
		hl->old_index--;
		return(-1);
	}

	/* hl_index == actual index, highligh the line */
	if (hl->hl_index == d_index) {
		wattron(list_win, A_REVERSE);
		hl->hl_entry = item->entry;
	}
	/* reset cursor */
	wmove(list_win, y + top_line, 1);

	status = ' ';
	/* build entry */
	/* if item->dep_path != NULL we are browsing pkgfind */
	if (!toplevel(path) || item->dep_path != NULL)
		if (getpkginfo(item->entry, PKG_VERSION) != NULL)
			status = '*';

	snprintf(buf, MAXLEN, "[ %-15s%c]  %s", 
			 tmp_entry, status, item->comment);

	/* fill with whitespaces*/
	for (i = strlen(buf); i < (ncols - 2); i++)
		buf[i] = ' ';

	/* ensure string is NULL terminated */
	/* 5 == 2 borders - scrollbar - 2 */
	buf[ncols - 5] = '\0';

	/* print entry*/
	wprintw(list_win, "%s", buf);

	/* scrollbar */
	if (hl->count > 0) {
		sb_real = (hl->hl_index * 10) / hl->count;
		sb_y = (y * 10) / (nlines - 1);
	} else
		sb_real = sb_y = 0;

	/* display scrollbar */
	if (hl->count > nlines && sb_y == sb_real && sb_y != last_sb) {
		wattron(list_win, A_REVERSE);
		mvwprintw(list_win, y + 1, ncols - 2,  "-");
	} else {
		wattroff(list_win, A_REVERSE);
		mvwprintw(list_win, y + 1, ncols - 2,  " ");
	}
	last_sb = sb_y;

	wattroff(list_win, A_REVERSE);

	return(1);
}

/* refresh and resize screen (coming from info window) */
static void
list_win_refresh()
{
	wclear(list_win);
	wrefresh(list_win);
	wresize(list_win, nlines + 2, ncols);
}

/* parse directory listing */
static int
print_list(Etree **etree, HL_datas *hl, char *path, const int where)
{
	int i, y, visible_index, d_index;
	char buf[MAXLEN], *ppath, *item;

	/* don't show path when listing PKGDB */
	if (where == IN_PKGDB)
		draw_box(list_win, INST_PKGS);

	/* etree == NULL, no directories found */
	if (etree == NULL || etree[0] == NULL) {
		/* there was no entries, are we in a pkg dir ? */
		snprintf(buf, MAXLEN, "%s/Makefile", path);
		if ((item = strrchr(path, '/')) == NULL)
		/* should never happen */
			return(IN_DESCR);
		item++;
		
		if (file_exists(buf)) {
			/* remember initial path */
			ppath = path;
			/* switch to information window */
			i = info_win(list_win, item, path);
		}
		/* back from information window */
		/* clean and restore window size */
		list_win_refresh();

		/* return IN_QUIT from info window, quit*/
		if (i == IN_QUIT)
			/* etree == NULL, nothing to free() */
			finish(0);

		if (where == IN_PKGDB)
			/* redraw borders */
			draw_box(list_win, INST_PKGS);
		
		if (where == IN_DEPENDS) {
			if ((ppath = strstr(path, "/..")) != NULL)
				/* dependency */
				*ppath = '\0';
			else
				/* pkgfind */
				strcpy(path, pkgsrcbase);

			draw_box(list_win, path);
		}

		if (where == IN_PKGSRC) {
			/* rewind to parent dir */
			ppath = strrchr(path, '/');
			*ppath = '\0';
			
			/* redraw borders */
			draw_box(list_win, path);
		}
		/* jump back to main loop with etree = NULL */
		return(IN_DESCR);

	} /* etree == NULL */

	/* there were entries */
	hl->count = dcount(etree);
	
	/* if hl < old we are scrolling up, don't update y */
	if (hl->hl_index < hl->old_index)
		visible_index = hl->old_index;
	else {
		visible_index = hl->hl_index;
		hl->old_index = hl->hl_index;
	}
	
	y = (visible_index + top_line) - nlines;
	
	/* hl + top is > to screen lines */
	if (y > 0)
		for (i = 0; i < y; i++);
	else
		i = 0;
	
	/* loop thru lines */
	for (y = 0; y < nlines; y++) {
		d_index = y + i;
		if (etree[d_index]) {
			/* print item and directory description */
			if (print_entry(etree[d_index], hl,
					path, d_index, y) < 0) {
				/* scrolling up, old index changed, 
				   recall me */
				print_list(etree, hl, path, where);
				return(0);
			}
		}
		else
			break;
	}
	return(0);
}

static void
print_kb(const char *key, const char *label, int y, int x)
{
	move(y, x);
	attron(A_BOLD);
	printw("%-5s", key);
	attroff(A_BOLD);
	printw(" %s", label);
}

static void
print_bindings()
{
	int spacing;

	spacing = strlen(ps_installed.descr);

	print_kb(ps_enter.icon, ps_enter.descr, nlines + 3, 2);
	print_kb(ps_back.icon, ps_back.descr, nlines + 4, 2);
	print_kb(ps_search.icon, ps_search.descr, nlines + 3, spacing);
	print_kb(ps_quit.icon, ps_quit.descr, nlines + 4, spacing);
	print_kb(ps_next.icon, ps_next.descr, nlines + 3, spacing * 2);
	print_kb(ps_find.icon, ps_find.descr, nlines + 4, spacing * 2);
	print_kb(ps_installed.icon, ps_installed.descr, 
		 nlines + 4, spacing * 3);

	refresh();
}

/*
 * non-directory based loop, we build etree with **list 
 * comments are built from *path/
 */
void
nodir_loop(const char *path, char **list)
{
	Etree **etree;

	if (list != NULL && list[0] != '\0') {
		/* call main loop with tree built from deps */
		etree = get_nodir_tree(path, list);
		if (etree != NULL)
			etree = main_loop(etree, list, path, IN_DEPENDS);
		/* at this point etree should be NULL */
	}
}

Etree **
main_loop(Etree **etree, char **list, const char *basepath, const int where)
{
	int c, tmp;
	HL_datas hl;
	char wpath[MAXLEN], *p, **pkglist;

	/* init highlight index */
	hl.hl_index = hl.old_index = 0;

	/* init working path */
	strcpy(wpath, basepath);

	/* we are called from show-deps, clean display from info window */
	if (where == IN_DEPENDS)
		list_win_refresh();

	/* redraw box */
	draw_box(list_win, wpath);

	/* main loop */
	for (;;) {
		if (print_list(etree, &hl, wpath, where) == IN_DESCR)
			/* recursive call led to DESCR, return NULL */
			return(NULL);

		/* print bindings */
		print_bindings();

		c = wgetch(list_win);
		switch(c) {
		case KEY_UP:
			if (hl.hl_index > 0)
				hl.hl_index--;
			break;
		case KEY_DOWN:
			if (hl.hl_index < hl.count)
				hl.hl_index++;
			break;
		case KEY_PPAGE:
			if ((hl.hl_index - nlines) > 0)
				hl.hl_index -= nlines;
			else
				hl.hl_index = 0;
			break;
		case KEY_NPAGE:
			if ((hl.hl_index + nlines) < hl.count)
				hl.hl_index += nlines;
			else
				hl.hl_index = hl.count;
			break;
		case KEY_RIGHT:
		case '\r':
			if (where == IN_PKGDB) {
				/* point to corresponding pkgdb line */
				p = getpkginfo(hl.hl_entry, PKG_CATEGORY);
				if (p == NULL)
					break;
				snprintf(wpath, MAXLEN, "%s/%s",
					 pkgsrcbase, p);
			}

			if (where == IN_DEPENDS)
				snprintf(wpath, MAXLEN, "%s/%s",
					 basepath, 
					 etree[hl.hl_index]->dep_path);

			if (where == IN_PKGSRC)
				snprintf(wpath, MAXLEN, "%s/%s", 
					 basepath, hl.hl_entry);
			
			/* load new basepath tree */
			clear_tree(&etree, where);
			etree = get_tree(wpath, where);
			/* re-enter main_loop with new tree */
			etree = main_loop(etree, NULL, wpath, where);
			/* back from recursion with NULL etree */
			break;
		case KEY_LEFT:
			clear_tree(&etree, where);

			if (!toplevel(basepath) || where == IN_DEPENDS)
				return(NULL);

			/* NOTREACHED */
			break;
		case 'n':
			tmp = entry_search(etree,1);
			if (tmp >= 0)
				hl.hl_index = tmp;
			break;
		case '/':
			tmp = entry_search(etree, 0);
			if (tmp >= 0)
				hl.hl_index = tmp;
			break;
		case 'f':
			/* show popup, p gets result */
			p = getstr_popup("pkgfind", 5, 30, 
					   (LINES / 2) - 2, (COLS / 2) - 15);
			/* split p into malloc'ed char * pieces */
			pkglist = pkgfind(pkgsrcbase, p, 0);
			XFREE(p);
			if (pkglist == NULL)
				break;
			/* non dir-listing loop */
			nodir_loop(pkgsrcbase, pkglist);
			/* back from pkgfind browsing, free the pkglist */
			free_list(&pkglist);
			break;
		case 'l':
			if (where != IN_PKGDB) {
				/* set basepath to pkgdb_dir */
				strncpy(wpath, pkg_dbdir, 
					strlen(pkg_dbdir) + 1);
				clear_tree(&etree, IN_PKGDB);
				etree = get_tree(wpath, IN_PKGDB);
				/* recurse */
				etree = main_loop(etree, NULL, 
						  wpath, IN_PKGDB);
			}
			break;
		case 'q':
			clear_tree(&etree, where);
			finish(0);
			break;
		} /* switch */

		/* if we return from DESCR section, etree == NULL */
		if (etree == NULL) {
			/* coming from DESCR, show basepath (parent) */
			if (where == IN_DEPENDS)
				etree = get_nodir_tree(basepath, list);
			else
				etree = get_tree(basepath, where);

			/* re-init screen */
			draw_box(list_win, basepath);
		}
	} /* for (;;) */
	/* NOTREACHED */
}

int
main(int argc, char *argv[])
{
	Etree **etree;
	char ch, basepath[MAXLEN];
	
	if ((pkgsrcbase = getenv("PKGSRCDIR")) == NULL)
		/* default basepath */
		pkgsrcbase = PKGSRCBASE;

	if ((pkg_dbdir = getenv("PKG_DBDIR")) == NULL)
		/* default pkg_dbdir */
		pkg_dbdir = PKGDB;

	/* command line handling */
	while ((ch = getopt(argc, argv, "b:K:h")) != -1)
		switch(ch) {
		case 'b':
			pkgsrcbase = optarg;
			break;
		case 'K':
			pkg_dbdir = optarg;
			break;
		case 'h':
			usage();
			/* NOTREACHED */
		}

        argc -= optind;
        argv += optind;
	/* end of command line handlig */

	/* default basepath */
	strncpy(basepath, pkgsrcbase, MAXLEN);

	signal(SIGINT, finish);

	/* load installed package list */
	load_pkgdb();

        /* init ncurses */
	init_curses();

	/* init different windows */
	init_windows();

	/* enable KEY_* */
	keypad(list_win, TRUE);

	/* get directory listing */
	etree = get_tree(basepath, IN_PKGSRC);

	/* enter browser */
	(void) main_loop(etree, NULL, basepath, IN_PKGSRC);

	/* NOTREACHED */
	exit(EXIT_SUCCESS);
}
