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
 * $Id: extern.h,v 1.3 2005/03/15 17:14:25 imilh Exp $ 
 */

#ifndef _EXTERN_H_
#define _EXTERN_H_

#include "pkg_adm.h"

extern Etree **main_loop(Etree **, char **, const char *, const int);
extern void nodir_loop(const char *, char **);
extern int toplevel(const char *);

extern Etree **get_tree(const char *, int);
extern Etree **get_nodir_tree(const char *, char **);
extern void free_tree(Etree ***);
extern void free_nodir_tree(Etree ***);
extern int entry_search(Etree **, int);

/* list mgt */
extern int find_value(Etree **, char *);
extern char **pkgfind(const char *, const char *, int);
extern Etree **build_tree_from_list(char **);

extern int info_win(WINDOW *, char *, char *);
extern int more_file(WINDOW *, char *, int, int, int, int);
extern int more_list(WINDOW *, char **, int, int, int, int);

extern struct cf *load_makefile(char *, int);
extern char *getcomment(struct cf *);

extern char *list_mirrors(const char *);
extern int pkgsrc_chk(const char *);
extern int cvs_up(const char *);

/* install_many */
extern int tb_installed(const char *);
extern void add_pkg(const char *);
extern void free_tbi_pkgs(void);
extern void process_many(int);

/* conf */
extern void loadconf(void);
extern void freeconf(void);

/* prefs screen */
extern void prefs_screen(void);

/* globals */

const char *pkg_dbdir;
const char *pkgsrcbase;
Conf conf;

#endif
