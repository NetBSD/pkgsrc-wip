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
 * $Id: curses_helpers.c,v 1.4 2005/03/15 17:14:25 imilh Exp $ 
 */

#include "pkg_select.h"
#include "curses_input.h"

static int combo_entry(WINDOW *, Etree *, HL_datas *, int, int, const char *);
static int dcount(Etree **);

void
print_kb(const char *key, const char *label, int y, int x)
{
	move(y, x);
	attron(A_BOLD);
	printw("%-5s", key);
	attroff(A_BOLD);
	printw(" %s", label);
}

void
wprint_kb(WINDOW *win, const char *key, const char *label, int y, int x)
{
	wmove(win, y, x);
	wattron(win, A_BOLD);
	wprintw(win, "%-5s", key);
	wattroff(win, A_BOLD);
	wprintw(win, " %s", label);
}

void
exit_curses()
{
	reset_shell_mode();
	endwin();
}

void
clr_win(WINDOW *win)
{
	wclear(win);
	wrefresh(win);
}

void
clr_del_win(WINDOW *win)
{
	clr_win(win);
	delwin(win);
}

void
clr_allscr(WINDOW *win)
{
	/* clear entire screen */
	clear(); refresh();
	if (win != NULL)
		clr_win(win);
}

WINDOW *
info_popup(const char *label, const char *info, 
	   int h, int w, int y, int x)
{
	WINDOW *popup;

	popup = newwin(h, w, y, x);
	box(popup, 0, 0);
	wmove(popup, 0, 1);
	wattron(popup, A_BOLD);
	wprintw(popup, "[ %s ]", label);
	wattroff(popup, A_BOLD);
	wmove(popup, 2, 2);
	wprintw(popup, "%s", info);

	return(popup);
}

char
getch_popup(const char *label, const char *question, 
	    int h, int w, int y, int x)
{
	WINDOW *popup;
	char c;

	popup = newwin(h, w, y, x);
	box(popup, 0, 0);
	wmove(popup, 0, 1);
	wattron(popup, A_BOLD);
	wprintw(popup, "[ %s ]", label);
	wattroff(popup, A_BOLD);
	wmove(popup, 2, 2);
	wprintw(popup, "%s", question);

	c = wgetch(popup);

	clr_win(popup);
	delwin(popup);
	return(c);
}

WINDOW *
mid_info_popup(const char *label, const char *msg)
{
	int len;
	WINDOW *popup;

	len = strlen(msg);
	popup = info_popup(label, msg, 5, len + 4, 
			   (LINES / 2) - 2, (COLS / 2) - (len / 2) - 2);

	return(popup);
}

char
mid_getch_popup(const char *label, const char *msg)
{
	int len;

	len = strlen(msg);
	return(getch_popup(label, msg, 5, len + 4, 
			   (LINES / 2) - 2, (COLS / 2) - (len / 2) - 2));
}

char *
getstr_ci(WINDOW *popup, int w, int y, int x)
{
	char buf[MAXLEN], *dispbuf, *key;
	char fmt[10];
	int c, modified;
	int dispw, pos, offset, i, l;

	dispw = w - 2;
	sprintf(fmt, "%%-%ds", dispw);
	XMALLOC(dispbuf, (dispw + 1) * sizeof(char));

	keypad(popup, TRUE);

	pos = 0;
	offset = 0;
	memset(buf, 0, MAXLEN);

	while ((c = wgetch(popup)) != KEY_ENTER) {
		i = pos + offset;
		modified = 0;

		/* Process keys that modify string first */
		if (c < 0x100 && isprint((unsigned char) c)) {
			/* Normal char */
			if (i >= MAXLEN - 1) {
				/* buffer is full */
				continue;
			}

			if (buf[i] != '\0') {
				/* "insert" */
				memmove((char *) (buf + i + 1), 
					(char *) (buf + i),
					MAXLEN - i - 1);
			}

			buf[i] = (char) c;
			c = KEY_RIGHT;
			modified = 1;
		} else if (c == KEY_BACKSPACE) {
			if (i == 0) {
				/* already at start of string */
				continue;
			}

			/* delete previous char */
			memmove((char *) (buf + i - 1), 
				(char *) (buf + i), MAXLEN - i - 1);
			c = KEY_LEFT;
			modified = 1;
		} else if (c == KEY_DC || c == KEY_CTRL_D) {
			if ((unsigned int)i == strlen(buf)) {
				/* nothing to delete at end of string */
				continue;
			}

			/* delete current char */
			memmove((char *) (buf + i), 
				(char *) (buf + i + 1), MAXLEN - i - 2);
			modified = 1;
		}

		curs_set(0);

		/* Handle navigation keys (or fake keys) */
		switch (c) {
		case KEY_RIGHT:
			if (modified || buf[i] != '\0') {
				if (pos < dispw - 1) {
					pos += 1;
				} else {
					offset += dispw / 2;
					pos = dispw / 2;
				}
			}
			break;
		case KEY_LEFT:
			if (pos > 0) {
				pos -= 1;
			} else {
				if (offset >= dispw / 2) {
					offset -= dispw / 2;
					pos = dispw / 2 - 1;
				} else if (offset > 0) {
					offset -= 1;
				}
			}
			break;
		case KEY_HOME:
		case KEY_CTRL_A:
			pos = 0;
			offset = 0;
			break;
		case KEY_END:
		case KEY_CTRL_E:
			l = strlen(buf);

			if (l - (offset + 1) >= dispw) {
				mvwprintw(popup, 0, 0, "%04d", l - (offset + 1));
				offset = strlen(buf) - (dispw - 1);
				pos = dispw - 1;
			} else {
				pos = l - offset;
			}
			break;
		default:
			if (!modified) {
				continue;
			}
			break;
		}

		/* update display */
		if (offset > 0) {
			mvwprintw(popup, y, x, "<");
		} else {
			mvwprintw(popup, y, x, " ");
		}

		if (strlen((char *) (buf + offset)) > (unsigned int)dispw) {
			mvwprintw(popup, y, x + dispw + 1, ">");
		} else {
			mvwprintw(popup, y, x + dispw + 1, " ");
		}

		strlcpy(dispbuf, (char *) (buf + offset), dispw + 1);
		mvwprintw(popup, y, x + 1, fmt, dispbuf);
		wmove(popup, y, x + 1 + pos);

		curs_set(1);
	}

	XFREE(dispbuf);
	XSTRDUP(key, buf);

	return (key);
}

char *
getstr_popup(const char *label, int h, int w, int y, int x)
{
	WINDOW *popup;
	char *key;

	popup = newwin(h, w, y, x);
	box(popup, 0, 0);
	wmove(popup, 0, 1);
	wprintw(popup, "[ %s ]", label);
	wmove(popup, 2, 2);

	noecho();
	curs_set(1);

	key = getstr_ci(popup, w - 2, 2, 1);

	curs_set(0);

	delwin(popup);
	return(key);
}

char *
mid_getstr_popup(const char *label)
{
	int len;

	len = (COLS * 2) / 3;
	return(getstr_popup(label, 5, len + 4, 
			   (LINES / 2) - 2, (COLS / 2) - (len / 2) - 2));
}

void
draw_box(WINDOW *win, const char *path)
{
	char *p, title[MAXLEN] = "";

	if (path != NULL) {
		/* clean up title when deeply recursing */
		if ((strstr(path, "/..") != NULL) && 
		    (p = strrchr(path, '/')) != NULL)
			snprintf(title, MAXLEN, "dependency: %s", ++p);
		else
			strcpy(title, path);
	}

	wclear(win);
	/* draw box */
	box(win, 0 , 0);
	wattron(win, A_BOLD);
	/* top right item */
	/* 6 == [ + ' ' + ' ' + ] + 2 borders */
	mvwprintw(win, 0, getmaxx(win) - 6 - strlen(title), "[ %s ]", title);
	wattroff(win, A_BOLD);
}

/* Scroll list section */

/* count entries */
static int
dcount(Etree **etree)
{
	int i;

	for (i = 0; etree[i] != NULL; i++);
	i--;

	return(i);
}

/* print item + descr, d_index = y + i (relative / delta index) */
static int
combo_entry(WINDOW *list_win, Etree *item, HL_datas *hl, 
	    int d_index, int y, const char *path) {

	int i, real_hl;
	int sb_real, sb_y;
	static int last_sb = -1;
	static int delta = 0;
	char buf[MAXLEN], tmp_entry[MAXLEN], tmp_comment[MAXLEN], 
		status, tbi;

#define PS_ALIGN 20

	if (item->entry != NULL) {
		/* we don't want to modify pkg name */
		strcpy(tmp_entry, item->entry);
		/* -1 : spaces between entry and comment */
		cut_str(tmp_entry, PS_ALIGN - 8);
	}
	if (item->comment != NULL) {
		strcpy(tmp_comment, item->comment);
		/* 9 = 3 dots + [\ ]\ \ + scrollbar */
		cut_str(tmp_comment, hl->ncols - PS_ALIGN - 9);
	}
	
	/* highlight*/
	real_hl = hl->hl_index + hl->top_line;
	/* delta between hl and old */
	delta = hl->old_index - hl->hl_index;
	
	/* scroll up */
	if ((y == 0) && (delta >= hl->nlines)) {
		hl->old_index--;
		return(-1);
	}

	/* hl_index == actual index, highligh the line */
	if (hl->hl_index == d_index) {
		wattron(list_win, A_REVERSE);
		hl->hl_entry = item->entry;
		hl->hl_comment = item->comment;
	}
	/* reset cursor */
	wmove(list_win, y + hl->top_line, 1);

	status = tbi = ' ';
	/* build entry */
	/* if item->dep_path != NULL we are browsing pkgfind */
	if (path != NULL) {
		if (!toplevel(path) || item->dep_path != NULL)
			if (getpkginfo(item->entry, PKG_VERSION) != NULL)
				status = '*';
		if (!toplevel(path))
			if (tb_installed(item->entry))
				tbi = '+';
	}

	if (item->entry != NULL)
		snprintf(buf, MAXLEN, "[ %-15s%c%c]  %s", 
			 tmp_entry, tbi, status, tmp_comment);
	else
		/* no entry column, simple scroll box */
		snprintf(buf, MAXLEN, " %s", tmp_comment);

	/* fill with whitespaces*/
	for (i = strlen(buf); i < (hl->ncols - 2); i++)
		buf[i] = ' ';

	/* ensure string is NULL terminated */
	/* 5 == 2 borders - scrollbar - 2 */
	buf[hl->ncols - 5] = '\0';

	/* print entry*/
	wprintw(list_win, "%s", buf);

	/* scrollbar */
	if (hl->count > 0) {
		sb_real = (hl->hl_index * 10) / hl->count;
		sb_y = (y * 10) / (hl->nlines - 1);
	} else
		sb_real = sb_y = 0;

	/* display scrollbar */
	if (hl->count > hl->nlines && sb_y == sb_real && sb_y != last_sb) {
		wattron(list_win, A_REVERSE);
		mvwprintw(list_win, y + 1, hl->ncols - 2,  "-");
	} else {
		wattroff(list_win, A_REVERSE);
		mvwprintw(list_win, y + 1, hl->ncols - 2,  " ");
	}
	last_sb = sb_y;

	wattroff(list_win, A_REVERSE);

	return(1);
}

int
combo_list(WINDOW *list_win, Etree **etree, HL_datas *hl, const char *path)
{
	int visible_index, y, i, d_index;

	hl->count = dcount(etree);
	
	/* if hl < old we are scrolling up, don't update y */
	if (hl->hl_index < hl->old_index)
		visible_index = hl->old_index;
	else {
		visible_index = hl->hl_index;
		hl->old_index = hl->hl_index;
	}
	
	y = (visible_index + hl->top_line) - hl->nlines;
	
	/* hl + top is > to screen lines */
	if (y > 0)
		for (i = 0; i < y; i++);
	else
		i = 0;
	
	/* loop thru lines */
	for (y = 0; y < hl->nlines; y++) {
		d_index = y + i;
		if (etree[d_index]) {
			/* print item and directory description */
			if (combo_entry(list_win, etree[d_index], 
					hl, d_index, y, path) < 0) {
				/* scrolling up, old index changed, 
				   recall me */
				combo_list(list_win, etree, hl, path);
				return(0);
			}
		}
		else
			break;
	}
	return(0);
}

char *
combo_select(Etree **etree, const char *title, 
	     int lines, int cols, int y, int x, int top)
{
	HL_datas hl;
	int c;
	char *ret;
	WINDOW *combo_win;

	/* init highlight index */
	hl.hl_index = hl.old_index = 0;
	/* save screen props */
	hl.nlines = lines; /* printable screen */
	hl.ncols = cols;
	hl.top_line = top;

	/* init scroll window */
        combo_win = newwin(hl.nlines + 2, hl.ncols, y, x);
	keypad(combo_win, TRUE);

	draw_box(combo_win, title);

	for (;;) {
		combo_list(combo_win, etree, &hl, NULL);

		c = wgetch(combo_win);
		switch(c) {

			/* macro defining up, down, pgup and pgdown */
			BASIC_NAV

		case KEY_RIGHT:
		case KEY_ENTER:
			XSTRDUP(ret, hl.hl_comment);
			clr_del_win(combo_win);
			return(ret);
			break;
		case KEY_LEFT:
		case 'q':
			clr_del_win(combo_win);
			return(NULL);
			break;
		} /* switch */
	} /* for (;;) */

	clr_del_win(combo_win);
	return(NULL);
}

int
progress_bar(const char **keylist, char *key, int mode)
{
	int h, w, y, x, i, pg, percent;
	static int bar = 0, size;
	static const char **list = NULL, *last;
	static WINDOW *popup;
	char buf[MAXLEN] = "";

	if (keylist == NULL)
		return(T_FALSE);

	h = 6;
	w = (COLS * 2) / 3;
	y = (LINES / 2)- (h / 2);
	x = (COLS / 2) - (w / 2);

	if (keylist != NULL && list == NULL) {
		list = keylist;
		size = listlen(list) - 1;
		/* draw window and box */
		popup = newwin(h, w, y, x);
	}
	/* redraw box */
	box(popup, 0, 0);

	/* parse list and find matching entry */
	for (i = 0; list[i] != NULL; i++)
		if (key != NULL && strstr(key, list[i]) != NULL) {
			/* match ! increase progress bar */
			if (mode == CYCLIC)
				/* CYCLIC mode, progress bar has the same
				 * size as the number we are in list
				 */
				bar = i + 1;
			else { /* INCREMENTAL mode 
				* if key matches any item in list that's not
				* very last item, increment progress bar.
				* Used for pkgsrc deflate progress
				*/
				if (last != NULL && 
				    strcmp(last, list[i]) != 0)
					bar++;
				last = list[i];
			}
			break;
		}

	if (list[i] == NULL)
		/* no match, continue */
		return(T_TRUE);

	w -= 4;
	pg = (bar  * w) / (size + 1);

	percent = (bar  * 100) / (size + 1);
	mvwprintw(popup, 0, w - 8, "[%3d%%]", percent);
	wrefresh(popup);
	for (i = 0; i < pg; i++) {
		/* clear line */
		line_padding(buf, ' ', w);
		mvwprintw(popup, 1, 2, buf);
		trimcr(key);
		cut_str(key, w - 3);
		line_padding(key, ' ', w);
		mvwprintw(popup, 1, 2, key);
		wattron(popup, A_REVERSE);
		mvwprintw(popup, 3, i + 2, " ");
		wattroff(popup, A_REVERSE);

		wrefresh(popup);
	}

	if (bar > size) {
		list = NULL;
		bar = 0;
		delwin(popup);
		/* progressbar ended, don't recall me */
		return(T_FALSE);
	}
	return(T_TRUE);
}

void
cmd_spawn(int waitkey, const char **progress_list, const char *command, ...)
{
	int next;
	FILE *fp;
	char buf[MAXLEN];

	va_list args;
	va_start(args, command);
	vsnprintf(buf, MAXLEN, command, args);
	va_end(args);

	if ((fp = popen(buf, "r")) == NULL)
		return;

	if (conf.shell_output)
		endwin();

	next = T_TRUE;
	while (fgets(buf, MAXLEN, fp) != NULL) {
		/* shell output preferred instead of progress bars */
		if (conf.shell_output)
			printf(buf);
		else
			if (next)
				next = progress_bar(progress_list, 
						    buf, CYCLIC);
	}
	pclose(fp);

	if (conf.shell_output && waitkey) {
		printf("\nPress [Enter] to continue...");
		(void) getchar();
	}
}
