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
 * $Id: more.c,v 1.1.1.1 2005/02/21 10:38:07 imilh Exp $
 */

#include "pkg_select.h"

static void
print_page(WINDOW *win, char **page, int y, int x, int maxlines)
{
	int i, j, len;
	char buf[MAXLEN], *c;
	
	for (i = 0; (page[i] != NULL) && (i < maxlines); i++) {
		/* clear the line */
		for (j = 0; j < COLS - 4; j++)
			buf[j] = ' ';
		buf[j] = 0;
		wmove(win, y + i, x);
		wprintw(win, "%s", buf);

		/* print entry */
		len = strlen(page[i]);
		snprintf(buf, MAXLEN, "%s", page[i]);

		/* curses doesn't like newlines */
		c = strchr(buf, '\n');
		if (c != NULL)
			*c = 0;

		wmove(win, y + i, x);
		wprintw(win, "%s", buf);
	}
}

int
more_file(WINDOW *win, char *path, int h, int w, int y, int x)
{
	int ret;
	char **lfile;

	lfile = NULL;

	if (!file_exists(path))
		return(1);

	lfile = loadfile(path);

	ret = more_list(win, lfile, h, w, y, x);

	freefile(lfile);

	return(ret);
}

int
more_list(WINDOW *win, char **list, int h, int w, int y, int x)
{
	int i, c, bottom, percent, scr_i, lines;

	wclear(win);

	bottom = LINES - BOTTOM_KB;
	wprint_kb(win, ps_down.icon, ps_down.descr, bottom, 2);
	wprint_kb(win, ps_up.icon, ps_up.descr, bottom, 22);
	wprint_kb(win, ps_back.icon, ps_back.descr, bottom, 40);
	wprint_kb(win, ps_quit.icon, ps_quit.descr, bottom, 52);

	/* substract info bar size */
	h -= BOTTOM_KB;

	/* count lines */
	for (i = 0; list[i] != NULL; i++);
	lines = i;

	box(win, 0, 0);

	i = 0;
	print_page(win, &list[i], y, x, h);

	for (;;) {

		scr_i = i + h;
		
		if (scr_i < lines)
			percent = (100 * scr_i) / lines;
		else
			percent = 100;

		mvwprintw(win, 0, COLS - 12, "[%3d%%]", percent);

		c = wgetch(win);
		switch (c) {
		case KEY_UP:
			if (i > 0)
				i--;
			break;
		case KEY_DOWN:
			if ((i + h) < lines)
				i++;
			break;
		case KEY_LEFT:
			return(1);
			break;
		case 'q':
			return(0);
			break;
	}

		print_page(win, &list[i], y, x, h);
		
		wrefresh(win);
	}

	/* NOTREACHED */
	return(0);
}
