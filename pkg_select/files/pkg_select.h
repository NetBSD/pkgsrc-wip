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
 * $Id: pkg_select.h,v 1.4 2005/03/18 10:50:04 imilh Exp $ 
 */

#ifndef _PKG_SELECT_H_
#define _PKG_SELECT_H_

#include <curses.h>
#include <dirent.h>
#include <sys/stat.h>
#include <ctype.h>
#include "tools.h"
#include "file.h"
#include "curses_helpers.h"
#include "texts.h"
#include "live.h"

#define IN_PKGSRC 1
#define IN_PKGDB 0
#define IN_DEPENDS 2
#define IN_DESCR 3
#define IN_FTP 4
#define IN_QUIT -1
#define FULL 2
#define PARTIAL 1
#define ONE_LEVEL 0
#define NOCOMMENT "no comment."
#define COMBO_INST 0
#define COMBO_DEINST 1

 /* sub top line and bottom menu */
#define MAINWIN_LINES LINES - 6
/* borders */
#define MAINWIN_COLS COLS - 2

/* 4 lines from bottom */
#define BOTTOM_KB 4

#include "extern.h"

#endif /* _PKG_SELECT_H_ */
