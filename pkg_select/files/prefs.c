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
 * $Id: prefs.c,v 1.3 2005/03/18 10:50:04 imilh Exp $ 
 */

#include "pkg_select.h"

#define UNSET "unset"

static void save_prefs(Etree **);
static Etree *entry_fill(const char *, const char *);

static Etree *
entry_fill(const char *title, const char *value)
{
	Etree *etree;
	char buf[MIDLEN];

	XMALLOC(etree, sizeof(Etree));
	etree->dep_path = NULL;
	etree->entry = NULL;

	if (value == NULL) {
		snprintf(buf, MIDLEN, "%s: %s", title, UNSET);
		XSTRDUP(etree->comment, buf);
	} else {
		snprintf(buf, MIDLEN, "%s: %s", title, value);
		XSTRDUP(etree->comment, buf);
	}
	return(etree);
}

static void
save_prefs(Etree **etree)
{
	int i;
	FILE *fp;
	char buf[MAXLEN], *p;

	if ((fp = fopen(conf.confpath, "w")) == NULL) {
		warn("could not open %s for writing", conf.confpath);
		return;
	}
	for (i = 0; etree[i] != NULL; i++) {
		if (strstr(etree[i]->comment, UNSET) != NULL)
			continue;
		/* replace : with a space */
		if ((p = strchr(etree[i]->comment, ':')) != NULL)
			*p = ' ';
		snprintf(buf, MAXLEN, "%s\n", etree[i]->comment);
		fputs(buf, fp);
	}

	fclose(fp);
}

void
prefs_screen()
{
	int y, x, h, w, i, bottom;
	char *resp, *p, confpath[MAXLEN], buf[MIDLEN];
	Etree **etree;

	y = 1;
	x = 1;
	h = LINES - 5;
	w = COLS - 2;

	bottom = h + 3;
	clear();
	print_kb(ps_down.icon, ps_down.descr, bottom, 2);
	print_kb(ps_up.icon, ps_up.descr, bottom, 22);
	print_kb(ps_back.icon, ps_back.descr, bottom, 40);
	refresh();

	XSTRCPY(confpath, conf.confpath);

	XMALLOC(etree, (conf.elements + 1) * sizeof(Etree *));
	i = 0;

	etree[i++] = entry_fill("pkg_dbdir", conf.pkg_dbdir);
	etree[i++] = entry_fill("cvs_mirror", conf.cvs_mirror);
	etree[i++] = entry_fill("ftp_mirror", conf.ftp_mirror);
	etree[i++] = entry_fill("pkg_path", conf.pkg_path);
	etree[i++] = entry_fill("cvs_branch", conf.cvs_branch);
	etree[i++] = entry_fill("live_ftp_pkgsrc", conf.live_ftp_pkgsrc);

	if (conf.shell_output)
		etree[i++] = entry_fill("shell_output", "yes");
	else
		etree[i++] = entry_fill("shell_output", "no");

	if (conf.live_ftp_read_makefiles)
		etree[i++] = entry_fill("live_ftp_read_makefiles", "yes");
	else
		etree[i++] = entry_fill("live_ftp_read_makefiles", "no");

	etree[i] = NULL;

	/* enter combo list loop */
	resp = NULL;
	do {
		XFREE(resp);
		/* draw select box */
		resp = combo_select(etree, "preferences", h, w, y, x, 1);
		if (resp == NULL)
			break;

		/* point to value */
		if ((p = strchr(resp, ':')) != NULL ||
		    (p = strchr(resp, ' ')) != NULL ||
		    (p = strchr(resp, '\t')) != NULL) {
			*p = '\0';
		} else
			continue;

		/* give selected value index */
		i = find_value(etree, resp);
		XSTRCPY(buf, resp); /* remember key */

		XFREE(resp);
		/* ask new value */
		resp = mid_getstr_popup("change value");
		/* resp is free'd at loop's begining */
		if (resp == NULL || *resp == '\0') {
			XFREE(etree[i]->comment);
			snprintf(buf, MIDLEN, "%s: %s", buf, UNSET);
			XSTRDUP(etree[i]->comment, buf);
			continue;
		}

		/* replace */
		if (i > -1) {
			XFREE(etree[i]->comment);
			/* build line, buf has key value  */
			snprintf(buf, MIDLEN, "%s: %s", buf, resp);
			XSTRDUP(etree[i]->comment, buf);
		}
	} while(resp != NULL);

	save_prefs(etree);
	/* freeconf does not empty conf.confpath */
	freeconf();
	loadconf();

	XFREE(resp);
	free_nodir_tree(&etree);
}
