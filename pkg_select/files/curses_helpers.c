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
 * $Id: curses_helpers.c,v 1.2 2005/02/22 09:52:33 imilh Exp $ 
 */

#include "pkg_select.h"

void
wprint_kb(WINDOW *win, const char *key, const char *label, int y, int x)
{
	wmove(win, y, x);
	wattron(win, A_BOLD);
	wprintw(win, "%-5s", key);
	wattroff(win, A_BOLD);
	wprintw(win, " %s", label);
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

	delwin(popup);
	return(c);
}

char *
getstr_popup(const char *label, int h, int w, int y, int x)
{
	WINDOW *popup;
	char buf[MAXLEN], *key;

	popup = newwin(h, w, y, x);
	box(popup, 0, 0);
	wmove(popup, 0, 1);
	wprintw(popup, "[ %s ]", label);
	wmove(popup, 2, 2);

        echo();
	curs_set(1);

	wgetnstr(popup, buf, MAXLEN);
	curs_set(0);
        noecho();

	XSTRDUP(key, buf);

	delwin(popup);
	return(key);
}

void
cmd_spawn(const char *command, ...)
{
	FILE *fp;
	WINDOW *shell;
	char buf[MAXLEN];

	va_list args;
	va_start(args, command);
	vsnprintf(buf, MAXLEN, command, args);
	va_end(args);

	shell = newwin(LINES, COLS, 0, 0);
	
	wclear(shell);
	wrefresh(shell);
	nl();
	echo();
	curs_set(1);

	if ((fp = popen(buf, "r")) == NULL)
		return;

	while (fgets(buf, MAXLEN, fp) != NULL) {
		if (getcury(shell) >= LINES - 1) {
			wclear(shell);
			wmove(shell, 0, 0);
		}
		wprintw(shell, "%s", buf);
		wrefresh(shell);
	}

	pclose(fp);

	wprintw(shell, ANY_KEY);
	(void) wgetch(shell);
	/* clean screen from shell junk */
	wclear(shell);
	wrefresh(shell);
	delwin(shell);
	
	nonl();
	noecho();
	curs_set(0);
}

void
draw_box(WINDOW *win, const char *path)
{
	char *p, title[MAXLEN];
	/* clean up title when deeply recursing */
	if ((strstr(path, "/..") != NULL) && (p = strrchr(path, '/')) != NULL)
		snprintf(title, MAXLEN, "dependency: %s", ++p);
	else
		strcpy(title, path);

	wclear(win);
	/* draw box */
	box(win, 0 , 0);
	wattron(win, A_BOLD);
	/* top right item */
	mvwprintw(win, 0, COLS - 8 - strlen(title), "[ %s ]", title);
	wattroff(win, A_BOLD);
}
