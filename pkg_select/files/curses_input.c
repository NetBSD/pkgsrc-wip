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
 * $Id: curses_input.c,v 1.1 2005/03/15 17:14:25 imilh Exp $ 
 */

#include <curses.h>

#include "tools.h"
#include "curses_input.h"

SLIST_HEAD(, Keysym) alt_map;
SLIST_HEAD(, Keysym) ctrl_map;
SLIST_HEAD(, Keysym) vtXXX_map;
SLIST_HEAD(, Keysym) xterm_map;
SLIST_HEAD(, Keysym) screen_map;
SLIST_HEAD(, Keysym) gnome_terminal_map;

struct Keysym *
alloc_keysym(const char *seq, int code)
{
	struct Keysym *sym;

	XMALLOC(sym, sizeof(struct Keysym));
	memset(sym, 0, sizeof(struct Keysym));

	if (seq != NULL) {
		XSTRDUP(sym->seq, seq);
	}

	sym->code = code;

	return (sym);
}

void
free_keymap(struct Keysym *map)
{
	struct Keysym *sym;

	while (map != NULL) {
		sym = SLIST_NEXT(map, next);
		XFREE(map->seq);
		XFREE(map);
		map = sym;
	}
}

void
define_keymap(struct Keysym *map)
{
	struct Keysym *sym;

	while (map != NULL) {
		sym = SLIST_NEXT(map, next);
		define_key(map->seq, map->code);
		map = sym;
	}
}

void
init_keymaps()
{
	int c;
	char seq[30];
	int basecode;

	/* ALT map */
	SLIST_INIT(&alt_map);

	for (c = 'a', basecode = KEY_ALT_BASE; c <= 'z'; c++) {
		sprintf(seq, "\033%c", c);
		basecode += 1;

		KEYMAP_INSERT(&alt_map, seq, basecode);
	}

	/* CTRL map */
	SLIST_INIT(&ctrl_map);

	for (c = 'a', basecode = KEY_CTRL_BASE; c <= 'z'; c++) {
		if (c == 'm') {
			/* Skip ^M which is defined later and
			 * mapped to KEY_ENTER */
			continue;
		}

		sprintf(seq, "%c", (c - 'a') + 1);
		basecode += 1;

		KEYMAP_INSERT(&ctrl_map, seq, basecode);
	}

	/* vtXXX map */
	SLIST_INIT(&vtXXX_map);

	KEYMAP_INSERT(&vtXXX_map, "\033[A", KEY_UP);
	KEYMAP_INSERT(&vtXXX_map, "\033OA", KEY_UP);
	KEYMAP_INSERT(&vtXXX_map, "\033[B", KEY_DOWN);
	KEYMAP_INSERT(&vtXXX_map, "\033OB", KEY_DOWN);
	KEYMAP_INSERT(&vtXXX_map, "\033[C", KEY_RIGHT);
	KEYMAP_INSERT(&vtXXX_map, "\033OC", KEY_RIGHT);
	KEYMAP_INSERT(&vtXXX_map, "\033[D", KEY_LEFT);
	KEYMAP_INSERT(&vtXXX_map, "\033OD", KEY_LEFT);
	KEYMAP_INSERT(&vtXXX_map, "\033[2~", KEY_IC);
	KEYMAP_INSERT(&vtXXX_map, "\033[3~", KEY_DC);
	KEYMAP_INSERT(&vtXXX_map, "\033[5~", KEY_PPAGE);
	KEYMAP_INSERT(&vtXXX_map, "\033[6~", KEY_NPAGE);
	KEYMAP_INSERT(&vtXXX_map, "\033[7~", KEY_HOME);
	KEYMAP_INSERT(&vtXXX_map, "\033[8~", KEY_END);
	KEYMAP_INSERT(&vtXXX_map, "\033[11~", KEY_F(1));
	KEYMAP_INSERT(&vtXXX_map, "\033[12~", KEY_F(2));
	KEYMAP_INSERT(&vtXXX_map, "\033[13~", KEY_F(3));
	KEYMAP_INSERT(&vtXXX_map, "\033[14~", KEY_F(4));
	KEYMAP_INSERT(&vtXXX_map, "\033[15~", KEY_F(5));
	KEYMAP_INSERT(&vtXXX_map, "\033[17~", KEY_F(6));
	KEYMAP_INSERT(&vtXXX_map, "\033[18~", KEY_F(7));
	KEYMAP_INSERT(&vtXXX_map, "\033[19~", KEY_F(8));
	KEYMAP_INSERT(&vtXXX_map, "\033[20~", KEY_F(9));
	KEYMAP_INSERT(&vtXXX_map, "\033[21~", KEY_F(10));
	KEYMAP_INSERT(&vtXXX_map, "\033[23~", KEY_F(11));
	KEYMAP_INSERT(&vtXXX_map, "\033[24~", KEY_F(12));

	KEYMAP_INSERT(&vtXXX_map, "\015", KEY_ENTER);
	KEYMAP_INSERT(&vtXXX_map, "\177", KEY_BACKSPACE);

	/* xterm map */
	SLIST_INIT(&xterm_map);

	KEYMAP_INSERT(&xterm_map, "\033[H", KEY_HOME);
	KEYMAP_INSERT(&xterm_map, "\033[F", KEY_END);
	KEYMAP_INSERT(&xterm_map, "\033[OP", KEY_F(1));
	KEYMAP_INSERT(&xterm_map, "\033[OQ", KEY_F(2));
	KEYMAP_INSERT(&xterm_map, "\033[OR", KEY_F(3));
	KEYMAP_INSERT(&xterm_map, "\033[OS", KEY_F(4));

	/* GNU screen map */
	SLIST_INIT(&screen_map);

	KEYMAP_INSERT(&screen_map, "\033[1~", KEY_HOME);
	KEYMAP_INSERT(&screen_map, "\033[4~", KEY_END);

	/* GNOME terminal map */
	SLIST_INIT(&gnome_terminal_map);

	KEYMAP_INSERT(&gnome_terminal_map, "\033[OH", KEY_HOME);
	KEYMAP_INSERT(&gnome_terminal_map, "\033[OF", KEY_END);

	define_keymap(SLIST_FIRST(&alt_map));
	define_keymap(SLIST_FIRST(&ctrl_map));
	define_keymap(SLIST_FIRST(&vtXXX_map));
	define_keymap(SLIST_FIRST(&xterm_map));
	define_keymap(SLIST_FIRST(&screen_map));
	define_keymap(SLIST_FIRST(&gnome_terminal_map));
}

void
free_keymaps()
{
	free_keymap(SLIST_FIRST(&alt_map));
	free_keymap(SLIST_FIRST(&ctrl_map));
	free_keymap(SLIST_FIRST(&vtXXX_map));
	free_keymap(SLIST_FIRST(&xterm_map));
	free_keymap(SLIST_FIRST(&screen_map));
	free_keymap(SLIST_FIRST(&gnome_terminal_map));
}
