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
 * $Id: install_many.c,v 1.2 2005/03/18 10:50:04 imilh Exp $ 
 */

#include "pkg_select.h"

struct pkg_list {
	char *pkg;
	SLIST_ENTRY(pkg_list) next;
};

static char **build_list_from_slist(void);
static void del_pkg(const char *);

static SLIST_HEAD(, pkg_list) top = SLIST_HEAD_INITIALIZER(top);
static int count = 0;

static char **
build_list_from_slist()
{
	int i;
	char *p, **list;
	struct pkg_list *plist;

	XMALLOC(list, (count + 1) * sizeof(char *));
	list[count] = NULL;
	i = count;
	i--;
	SLIST_FOREACH(plist, &top, next) {
		if ((p = strrchr(plist->pkg, '/')) != NULL)
			p++;
		else
			p = plist->pkg;

		XSTRDUP(list[i], p);
		i--;
	}

	return(list);
}

void
free_tbi_pkgs()
{
	struct pkg_list *plist;

	while (!SLIST_EMPTY(&top)) {
		plist = SLIST_FIRST(&top);
		SLIST_REMOVE_HEAD(&top, next);
		XFREE(plist->pkg);
		XFREE(plist);
	}
	count = 0;
}

int
tb_installed(const char *pkg)
{
	char *p;
	struct pkg_list *plist;

	if (SLIST_EMPTY(&top))
		return(T_FALSE);

	SLIST_FOREACH(plist, &top, next) {
		/* add_pkg check, based on full path */
		if (strchr(pkg, '/') != NULL) {
			if (strcmp(pkg, plist->pkg) == 0)
				return(T_TRUE);
			else
				continue;
		}
		/* combo select check, based on pkg name */
		if ((p = strrchr(plist->pkg, '/')) != NULL) {
			p++;
			if (strcmp(pkg, p) == 0)
				return(T_TRUE);
		}
	}
	return(T_FALSE);
}

void
del_pkg(const char *pkg)
{
	int len1, len2;
	struct pkg_list *plist;
	char *p;

	if (pkg == NULL)
		return;

	SLIST_FOREACH(plist, &top, next) {
		if (plist != NULL && plist->pkg != NULL) {
			/* full path size */
			len1 = strlen(plist->pkg);
			/* pkg size */
			len2 = strlen(pkg);
			if (len1 < len2)
				continue;
			/* point to pkg name if char *pkg is a full path */
			p = &(plist->pkg)[len1 - len2];

			if (strcmp(p, pkg) == 0) {
				SLIST_REMOVE(&top, plist, pkg_list, next);
				XFREE(plist->pkg);
				XFREE(plist);

				count--;
				return;
			}
		}
	}
}

void
add_pkg(const char *pkg)
{
	struct pkg_list *p;

	/* 1st, insert the >> Next item */
	if (SLIST_EMPTY(&top)) {
		XMALLOC(p, sizeof(struct pkg_list));
		XSTRDUP(p->pkg, NEXT);
		SLIST_INSERT_HEAD(&top, p, next);
		count++;
	}

	if (tb_installed(pkg)) {
		/* already marked, remove */
		del_pkg(pkg);
		return;
	}

	XMALLOC(p, sizeof(struct pkg_list));
	XSTRDUP(p->pkg, pkg);
	SLIST_INSERT_HEAD(&top, p, next);
	count++;
}

void
process_many(int action)
{
	char c, *p, *resp, **list, txt[MIDLEN], flags[5];
	const char *msg;
	int h, w, y, x;
	Etree **etree;
	struct pkg_list *plist;

	if (SLIST_EMPTY(&top))
		return;

	h = LINES - 4;
	w = COLS / 1.5;
	y = 0;
	x = (COLS - w) / 2;

	snprintf(txt, MIDLEN, "[ %s ]", NEXT);
	print_kb(txt, "proceed", LINES - 2, x);
	refresh();

	resp = NULL;
	do {
		/* map SLIST to a simple char ** list */
		if ((list = build_list_from_slist()) == NULL)
			goto out;
		if ((etree = build_tree_from_list(list)) == NULL)
			goto out;

		XFREE(resp);
		if (action == COMBO_INST)
			msg = PKG_TB_INST;
		else
			msg = PKG_TB_DEINST;

		resp = combo_select(etree, msg, 
				    h, w, y, x, 1);
		if (resp == NULL)
			return;
/* they said "counter-intuitive" :) let it there, we may find a use..
		if (strcmp(resp, NEXT) != 0)
			del_pkg(resp);
*/
	} while (strcmp(resp, NEXT) != 0);

	XFREE(resp);
	clear(); refresh();

	if (action == COMBO_INST)
		c = mid_getch_popup("install type", 
				    "(b)inaries / (s)ources ?");

	if (action == COMBO_DEINST) {
		c = mid_getch_popup("confirmation", 
				    REALLY_MASS_DELETE);
		if (c == 'n') /* default is Y */
			goto out;
		XSTRCPY(flags, "-v");
		if (c == 'r')
			XSTRCAT(flags, "r");
	}

	SLIST_FOREACH(plist, &top, next) {
		if ((p = strrchr(plist->pkg, '/')) == NULL)
			goto out;
		p++; /* p now points to pkg name */

		if (action == COMBO_DEINST)
			pkg_tool("delete", p, flags, DONT_WAIT);
		else { /* install: bins or sources ? */
			if (c == 'b') {
				set_pkg_path(conf.pkg_path);
				pkg_tool("add", p, "-v", DONT_WAIT);
			}
			if (c == 's') {
				pkgsrc_make("install", plist->pkg, DONT_WAIT);
			}
		} /* COMBO_INST */
	}
	
out:
	free_nodir_tree(&etree);
	free_list(&list);
	free_tbi_pkgs();
}

