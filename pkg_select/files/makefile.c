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
 * $Id: makefile.c,v 1.4 2005/03/18 10:50:04 imilh Exp $ 
 */

#include "pkg_select.h"

static void var_subst(struct cf *);
static char *do_subst(struct cf *, char *, char *);

static char *
do_subst(struct cf *subst, char *varname, char *value)
{
	char *out, *tmp, bufvar[MAXLEN], bufval[MAXLEN];
	
	out = NULL;
	snprintf(bufvar, MAXLEN, "${%s", varname);

	/* parse Makefile tree till we find suitable varname */
	while (subst != NULL && out == NULL) {
		snprintf(bufval, MAXLEN, "%s=", varname);
		/* found variable value */
		if (strncmp(subst->key, bufval, strlen(bufval)) == 0) {
			
			XSTRDUP(tmp, value);
			out = strreplace(tmp, bufvar, subst->value);
			XFREE(tmp);

		}
		subst = SLIST_NEXT(subst, next);
	} /* while subst */

	if (out == NULL) {
		XSTRDUP(tmp, value);
		out = strreplace(tmp, bufvar, "");
		XFREE(tmp);
	}

	return(out);
}

static void
var_subst(struct cf *file)
{
	struct cf *search;
	int len;
	char *varname, *p, *tend, *tmp;

	search = file;

	while (search != NULL) {
		while ((varname = strstr(search->value, "${")) != NULL) {
			varname += 2;
			tend = strchr(varname, '}');
			if (tend != NULL && *tend != 0) {
				*tend = '\0';
				/* 'line' now has variable name */
				/* search for variable in Makefile struct */

				p = do_subst(file, varname, search->value);

				if (p != NULL) {
					tend++;
					
					len = strlen(p) + strlen(tend) + 1;
					XMALLOC(tmp, len * sizeof(char));
					snprintf(tmp, len, "%s%s", p, tend);

					XFREE(p);
					XFREE(search->value);
					search->value = tmp;
				} /* do_subst returned something */
			} /* if } */
		} /* while there is variables on line */
		search = SLIST_NEXT(search, next);
	} /* while search */
}

struct cf *
load_makefile(char *path, int deepness)
{
	int i;
	struct cf *ret, *tmp;
	char buf[MAXLEN], **list, *inc, *p;
	
	snprintf(buf, MAXLEN, "%s/Makefile", path);

	ret = loadcf(buf, NULL);

	if (deepness < PARTIAL)
		return(ret);

	list = loadfile(buf);

	if (list != NULL) {
		for (i = 0; list[i] != NULL; i++) {
			/* uh oh.. inclusions */
			if ((strstr(list[i], "Makefile.common") != NULL &&
			     strstr(list[i], ".include") != NULL) 
#if 0
/* deep recursion into Makefiles includes takes way to much CPU / time 
   better do a make show-var. This code is here only to show i've been through
   this idea */
			     ||
/* go on every include "*.mk" */
			    ((deepness == FULL && 
			     strstr(list[i], ".mk") != NULL) &&
			     strstr(list[i], ".include") != NULL)
#endif
				) {

				/* build path so we load inclusion */
				inc = strchr(list[i], '"');
				/* point to "Makefile"*/
				if (inc++ != NULL &&
				    (p = strrchr(inc, '"')) != NULL) {
					/* maintener used .CURDIR as 
					   reference */
					if (strstr(inc, "${.CURDIR}/")) {
						inc = strchr(inc, '/');
						*(--inc) = '.';
					}
					*p = '\0';
					snprintf(buf, MAXLEN, "%s/%s", 
						 path, inc);
					
					/* append to main Makefile */
					if ((tmp = loadcf(buf, ret)) != NULL)
						ret = tmp;
				} /* inc != NULL */
			} /* there was a .include "Makefile" */
		} /* for list[i]*/
		freefile(list);
	} /* if list != NULL */

	var_subst(ret);

	return(ret);
}

char *
getcomment(struct cf *file)
{
	int len;
	char *ret, *comment, *subcomment;

	ret = NULL;

	comment = getval(file, "COMMENT=");
	if (comment != NULL)
		XSTRDUP(ret, comment);

	subcomment = getval(file, "COMMENT+=");
	if (comment != NULL && subcomment != NULL) {
		XFREE(ret);
		len = strlen(comment) + strlen(subcomment) + 3;
		XMALLOC(ret, len * sizeof(char));
		snprintf(ret, len, "%s %s", comment, subcomment);
	}

	if (ret == NULL)
		XSTRDUP(ret, NOCOMMENT);

	return(ret);
}
