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
 * $Id: conf.c,v 1.1 2005/03/15 17:14:25 imilh Exp $ 
 */

#include "pkg_select.h"

static struct cf *file;

void
loadconf()
{
	char *rep;

	conf.elements = 12; /* <---------------------------------
			     * UPDATE ME WHEN ADDING A CONF VALUE
			     * <--------------------------------- 
			     */

	if ((file = loadcf(conf.confpath, NULL)) == NULL) {
		conf.pkgsrcdir = NULL;
		conf.pkg_dbdir = NULL;
		conf.cvs_mirror = NULL;
		conf.ftp_mirror = NULL;
		conf.pkg_path = NULL;
		conf.cvs_branch = NULL;
		conf.live_ftp_pkgsrc = NULL;
		conf.live_ftp_read_makefiles = T_TRUE;
		conf.shell_output = T_FALSE;

		return;
	}

	conf.pkgsrcdir = getval(file, "pkgsrcdir");
	conf.pkg_dbdir = getval(file, "pkg_dbdir");
	conf.cvs_mirror = getval(file, "cvs_mirror");
	conf.ftp_mirror = getval(file, "ftp_mirror");
	conf.pkg_path = getval(file, "pkg_path");
	conf.cvs_branch = getval(file, "cvs_branch");
	conf.live_ftp_pkgsrc = getval(file, "live_ftp_pkgsrc");
	if ((rep = getval(file, "shell_output")) != NULL) {
		if (*rep == 'y' || *rep == 'Y')
			conf.shell_output = T_TRUE;
		else
			conf.shell_output = T_FALSE;
	}
	if ((rep = getval(file, "live_ftp_read_makefiles")) != NULL) {
		if (*rep == 'y' || *rep == 'Y')
			conf.live_ftp_read_makefiles = T_TRUE;
		else
			conf.live_ftp_read_makefiles = T_FALSE;
	}
}

void
freeconf()
{
	XFREE(conf.live_ftp);
	freecf(file);
}
