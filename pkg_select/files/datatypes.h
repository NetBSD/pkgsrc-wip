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
 * $Id: datatypes.h,v 1.2 2005/03/18 10:50:04 imilh Exp $ 
 */

typedef struct Etree {
	char *entry;
	char *comment;
	char *dep_path;
} Etree;

/* highlight / position informations */
typedef struct HL_datas {
	int nlines;
	int ncols;
	int top_line;
	int count; /* total items number */
	int hl_index; /* real highlight position */
	int old_index; /* last highlight position */
	char *hl_entry; /* highlighted item name */
	char *hl_comment;
} HL_datas;

/* conf file */
typedef struct Conf {
	unsigned int elements;
	const char *confpath;
	const char *pkgsrcdir;
	const char *pkg_dbdir;
	const char *cvs_mirror;
	const char *ftp_mirror;
	const char *pkg_path;
	const char *cvs_branch;
	char *live_ftp;
	const char *live_ftp_pkgsrc;
	unsigned int shell_output;
	unsigned int live_ftp_read_makefiles;
} Conf;
