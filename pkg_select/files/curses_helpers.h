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
 * $Id: curses_helpers.h,v 1.3 2005/03/15 17:14:25 imilh Exp $ 
 */

#include <curses.h>
#include "tools.h"
#include "datatypes.h"

extern void print_kb(const char *, const char *, int, int);
extern void wprint_kb(WINDOW *, const char *, const char *, int, int);
extern void clr_win(WINDOW *);
extern void clr_del_win(WINDOW *);
extern void clr_allscr(WINDOW *);
extern void exit_curses(void);
extern WINDOW *info_popup(const char *, const char *, int, int, int, int);
extern char getch_popup(const char *, const char *, int, int, int, int);
extern char mid_getch_popup(const char *, const char *);
extern WINDOW *mid_info_popup(const char *, const char *);
extern char *getstr_ci(WINDOW *, int, int, int);
extern char *getstr_popup(const char *, int, int, int, int);
extern char *mid_getstr_popup(const char *);
extern void draw_box(WINDOW *, const char *);
extern int combo_list(WINDOW *, Etree **, HL_datas *, const char *);
extern char *combo_select(Etree **, const char *, int, int, int, int, int);
extern int progress_bar(const char **, char *, int);
extern void cmd_spawn(int, const char **, const char *, ...);
#define ANY_KEY "\nPress any key to continue..."

#define CYCLIC 0
#define INCREMENTAL 1

#define BASIC_NAV							\
		case KEY_UP:						\
			if (hl.hl_index > 0)				\
				hl.hl_index--;				\
			break;						\
		case KEY_DOWN:						\
			if (hl.hl_index < hl.count)			\
				hl.hl_index++;				\
			break;						\
		case KEY_PPAGE:						\
			if ((hl.hl_index - hl.nlines) > 0)		\
				hl.hl_index -= hl.nlines;		\
			else						\
				hl.hl_index = 0;			\
			break;						\
		case ' ':						\
		case KEY_NPAGE:						\
			if ((hl.hl_index + hl.nlines) < hl.count)	\
				hl.hl_index += hl.nlines;		\
			else						\
				hl.hl_index = hl.count;			\
			break;
