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
 * $Id: pkg_adm.h,v 1.4 2005/03/18 10:50:04 imilh Exp $ 
 */

extern void free_pkgdb(void);
extern void load_pkgdb(void);
extern void reload_pkgdb(void);
extern char **show_var(char *, const char *, int);
extern char *show_first_var(char *, const char *);
extern void build_pkg_path(char *, char *);
extern char *getpkginfo(char *, int);
extern void set_pkg_path(const char *);

/* this is where you may want to port to another port framework */

#define PKGTOOLS_PATH "/usr/sbin"
#ifndef MAKE
#define MAKE "/usr/bin/make"
#endif

#define PKG_VERSION 0
#define PKG_CATEGORY 1
#define WAIT_KEY 1
#define DONT_WAIT 0

#define MAKE_INST	"Checksum",			       	\
			"Extracting",				\
			"Patching",				\
			"Applying",				\
			"Overriding",				\
			"Creating toolchain wrappers",		\
			"Building",				\
			"Unwrapping",				\
			"Installing",				\
			"Creating installation directories",	\
			"Registering installation",		\
			"Cleaning for"

#define MAKE_INST_PROGRESS { MAKE_INST, NULL }

#define MAKE_UPDT_PROGRESS { "Deinstalling",			\
				MAKE_INST,			\
				NULL }

#define MAKE_DEINST_PROGRESS { "Deinstalling",			\
				"Cleaning",			\
				NULL }
#define PKG_ADD_PROGRESS { "ftp -detv",				\
			"ftp> nlist",				\
			"ftp> get",				\
			"unpackURL",				\
			"ftp> close",				\
			"extract:",				\
			"Running mtree",			\
			"Attempting to record",			\
			"registered in ",			\
			NULL }

#define PKG_DEL_PROGRESS { "Change working",			\
			"Delete",				\
			NULL }

#define PKGSRC_PROGRESS { \
	"/archivers/", \
		"/audio/", \
		"/benchmarks/", \
		"/biology/", \
		"/bootstrap/", \
		"/cad/", \
		"/chat/", \
		"/comms/", \
		"/converters/", \
		"/cross/", \
		"/databases/", \
		"/devel/", \
		"/distfiles/", \
		"/doc/", \
		"/editors/", \
		"/emulators/", \
		"/finance/", \
		"/fonts/", \
		"/games/", \
		"/geography/", \
		"/graphics/", \
		"/ham/", \
		"/inputmethod/", \
		"/lang/", \
		"/licenses/", \
		"/mail/", \
		"/math/", \
		"/mbone/", \
		"/meta-pkgs/", \
		"/misc/", \
		"/mk/", \
		"/multimedia/", \
		"/net/", \
		"/news/", \
		"/packages/", \
		"/parallel/", \
		"/pkgtools/", \
		"/print/", \
		"/regress/", \
		"/security/", \
		"/shells/", \
		"/sysutils/", \
		"/templates/", \
		"/textproc/", \
		"/time/", \
		"/wm/", \
		"/www/", \
		"/x11/", \
		NULL }

extern void pkgsrc_make(const char *, const char *, int);
extern void pkg_tool(const char *, const char *, const char *, int);
