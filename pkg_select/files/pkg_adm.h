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
 * $Id: pkg_adm.h,v 1.1.1.1 2005/02/21 10:38:07 imilh Exp $ 
 */

extern void free_pkgdb(void);
extern void load_pkgdb(void);
extern void reload_pkgdb(void);
extern char **show_var(char *, const char *, int);
extern char *show_first_var(char *, const char *);
extern void build_pkg_path(char *);
extern char *getpkginfo(char *, int);

/* this is where you may want to port to another port framework */

#define DEFAULT_PKG_PATH "ftp://ftp.netbsd.org/pub/NetBSD/packages"
#define PKGTOOLS_PATH "/usr/sbin"
#define MAKE "/usr/bin/make"

#define PKG_VERSION 0
#define PKG_CATEGORY 1

#define PKGSRC_MAKE(action, path)	       			\
	do {							\
		(void) cmd_spawn("cd %s && %s %s %s",       	\
			  path, MAKE, action, "clean");		\
		reload_pkgdb();					\
	} while (/* CONSTCOND*/ 0)

#define PKG_TOOL(action, pkg, option)			       	\
	do {							\
		(void) cmd_spawn("%s/pkg_%s %s %s",		\
			  PKGTOOLS_PATH, action, option, pkg); 	\
		reload_pkgdb();					\
	} while (/* CONSTCOND*/ 0)
