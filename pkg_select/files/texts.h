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
 *
 * $Id: texts.h,v 1.2 2005/02/22 09:52:41 imilh Exp $ 
 */

#ifndef _TEXTS_H_
#define _TEXTS_H_

/* ui phrases */

#define PKG_ADMIN_INFO "Package administration and informations"
#define PLEASE_WAIT_CALC "please wait while calculating"
#define INST_PKGS "installed packages"
#define SEARCH_INFOS "searching infos..."

/* shortcuts */

typedef struct Shortcut {
	const char *icon;
	const char *descr;
} Shortcut;

static const Shortcut ps_enter = { "[ret]", "enter" };
static const Shortcut ps_back = { "[<-]", "back" };
static const Shortcut ps_search = { "[/]", "search" };
static const Shortcut ps_next = { "[n]", "next" };
static const Shortcut ps_quit = { "[q]", "quit" };
static const Shortcut ps_installed = { "[l]", INST_PKGS };
static const Shortcut ps_up = { "[up]", "scroll up" };
static const Shortcut ps_down = { "[down]", "scroll down" };
static const Shortcut ps_find = { "[f]", "pkgfind" };

#endif /* _TEXTS_H_ */
