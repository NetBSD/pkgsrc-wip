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
 * $Id: curses_input.h,v 1.1 2005/03/15 17:14:25 imilh Exp $ 
 */

#ifndef __CURSES_INPUT_H__
#define __CURSES_INPUT_H__

#include <curses.h>

#include "tools.h"

/* Constants */
#define KEY_ALT_BASE	(KEY_MAX + 0x0100)
#define KEY_CTRL_BASE	(KEY_MAX + 0x0200)

#define KEY_ALT_A	(KEY_ALT_BASE + 1)
#define KEY_ALT_B	(KEY_ALT_BASE + 2)
#define KEY_ALT_C	(KEY_ALT_BASE + 3)
#define KEY_ALT_D	(KEY_ALT_BASE + 4)
#define KEY_ALT_E	(KEY_ALT_BASE + 5)
#define KEY_ALT_F	(KEY_ALT_BASE + 6)
#define KEY_ALT_G	(KEY_ALT_BASE + 7)
#define KEY_ALT_H	(KEY_ALT_BASE + 8)
#define KEY_ALT_I	(KEY_ALT_BASE + 9)
#define KEY_ALT_J	(KEY_ALT_BASE + 10)
#define KEY_ALT_K	(KEY_ALT_BASE + 11)
#define KEY_ALT_L	(KEY_ALT_BASE + 12)
#define KEY_ALT_M	(KEY_ALT_BASE + 13)
#define KEY_ALT_N	(KEY_ALT_BASE + 14)
#define KEY_ALT_O	(KEY_ALT_BASE + 15)
#define KEY_ALT_P	(KEY_ALT_BASE + 16)
#define KEY_ALT_Q	(KEY_ALT_BASE + 17)
#define KEY_ALT_R	(KEY_ALT_BASE + 18)
#define KEY_ALT_S	(KEY_ALT_BASE + 19)
#define KEY_ALT_T	(KEY_ALT_BASE + 20)
#define KEY_ALT_U	(KEY_ALT_BASE + 21)
#define KEY_ALT_V	(KEY_ALT_BASE + 22)
#define KEY_ALT_W	(KEY_ALT_BASE + 23)
#define KEY_ALT_X	(KEY_ALT_BASE + 24)
#define KEY_ALT_Y	(KEY_ALT_BASE + 25)
#define KEY_ALT_Z	(KEY_ALT_BASE + 26)

#define KEY_CTRL_A	(KEY_CTRL_BASE + 1)
#define KEY_CTRL_B	(KEY_CTRL_BASE + 2)
#define KEY_CTRL_C	(KEY_CTRL_BASE + 3)
#define KEY_CTRL_D	(KEY_CTRL_BASE + 4)
#define KEY_CTRL_E	(KEY_CTRL_BASE + 5)
#define KEY_CTRL_F	(KEY_CTRL_BASE + 6)
#define KEY_CTRL_G	(KEY_CTRL_BASE + 7)
#define KEY_CTRL_H	(KEY_CTRL_BASE + 8)
#define KEY_CTRL_I	(KEY_CTRL_BASE + 9)
#define KEY_CTRL_J	(KEY_CTRL_BASE + 10)
#define KEY_CTRL_K	(KEY_CTRL_BASE + 11)
#define KEY_CTRL_L	(KEY_CTRL_BASE + 12)
#define KEY_CTRL_M	(KEY_CTRL_BASE + 13)
#define KEY_CTRL_N	(KEY_CTRL_BASE + 14)
#define KEY_CTRL_O	(KEY_CTRL_BASE + 15)
#define KEY_CTRL_P	(KEY_CTRL_BASE + 16)
#define KEY_CTRL_Q	(KEY_CTRL_BASE + 17)
#define KEY_CTRL_R	(KEY_CTRL_BASE + 18)
#define KEY_CTRL_S	(KEY_CTRL_BASE + 19)
#define KEY_CTRL_T	(KEY_CTRL_BASE + 20)
#define KEY_CTRL_U	(KEY_CTRL_BASE + 21)
#define KEY_CTRL_V	(KEY_CTRL_BASE + 22)
#define KEY_CTRL_W	(KEY_CTRL_BASE + 23)
#define KEY_CTRL_X	(KEY_CTRL_BASE + 24)
#define KEY_CTRL_Y	(KEY_CTRL_BASE + 25)
#define KEY_CTRL_Z	(KEY_CTRL_BASE + 26)

/* Datatypes */
struct Keysym {
	SLIST_ENTRY(Keysym) next;
	char *seq;
	int code;
};

/* Function prototypes */
struct Keysym * alloc_keysym(const char *, int);
void free_keysym(struct Keysym *);
void free_keymap(struct Keysym *);
void define_keymap(struct Keysym *);
void init_keymaps(void);
void free_keymaps(void);

/* Macros */
#define KEYMAP_INSERT(keymap, seq, code)			\
	do {							\
		struct Keysym *tsym;				\
		tsym = alloc_keysym((seq), (code));		\
		SLIST_INSERT_HEAD((keymap), tsym, next);	\
	} while (/*CONSTCOND*/0);

#endif /* __CURSES_INPUT_H__ */
