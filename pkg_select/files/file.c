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
 * $Id: file.c,v 1.4 2005/03/18 10:50:04 imilh Exp $ 
 */

/*
 * loadcf() : loads a simple configuretion file following this style :
 * keyword:<tabs or spaces>value
 * comments and blank lines are ignored
 *
 * freecf() : free the list containing the key / value pairs
 * MUST be called at the end of program
 *
 * getval() : returns the value associated to key
 *
 * see file.h for struct cf * details
 *
 */

#include "tools.h"
#include "file.h"

struct cf *
list_to_cf(char **list, struct cf *append)
{
	int i;
	struct cf *chain, *ap;

	SLIST_HEAD(, cf) top;
	SLIST_INIT(&top);

	if (append != NULL) {
		while (append != NULL) {
			ap = SLIST_NEXT(append, next);
			SLIST_INSERT_HEAD(&top, append, next);
			append = ap;
		}
	}

	for (i = 0; list[i] != NULL; i++) {
		char *k, *v, *value;
		int len;
 
		value = list[i];
		
		if (*value=='\n' || *value=='#' || 
		    *value == ' ' || *value == '\t')
			continue;

		k=value;
		v=k;
		while (*v != '\0' && *v != ' ' && *v != '\t')
			v++;

		if (*v == '\0')
			continue;
		*(v++) = '\0';

		while (*v == ' ' || *v == '\t')
			v++;

		len = strlen (v);
		v[--len] = '\0';

		XMALLOC(chain, sizeof(struct cf));
		XSTRDUP(chain->key, k);
		XSTRDUP(chain->value, v);

		SLIST_INSERT_HEAD(&top, chain, next);
	} /* for list[i] */

	return(SLIST_FIRST(&top));
}

struct cf *
loadcf(const char *confpath, struct cf *append)
{
	char **file;
	struct cf *chain;

	if ((file = loadfile(confpath)) == NULL)
		return(NULL);

	chain = list_to_cf(file, append);
	freefile(file);

	return(chain);
}


void
freecf(struct cf *p)
{
	struct cf *sp;

	while (p != NULL) {
			sp = SLIST_NEXT(p, next);
			XFREE(p->key);
			XFREE(p->value);
			XFREE(p);
			p = sp;
	}
}

char *
getval(struct cf *p, const char *key)
{
	while (p != NULL) {
		if ((p->key != NULL) && 
		    (strncmp(p->key, key, strlen(p->key)) == 0))
			return (p->value);

		p = SLIST_NEXT(p, next);
	}

	return (NULL);
}

char **
loadfile(const char *path)
{
	int i, len;
	FILE *fp;
	char **lfile, buf[MAXLEN];

	len = filelines(path);
	if (len == 0)
		return(NULL);

	XMALLOC(lfile, ++len * sizeof(char *));

	for (i = 0; i < len; i++)
		lfile[i] = NULL;

	if ((fp = fopen(path, "r")) == NULL)
		err(1, "fopen");

	for (i = 0; fgets(buf, MAXLEN, fp) && (i < len); i++)
		XSTRDUP(lfile[i], buf);

	lfile[i] = NULL;

	fclose(fp);

	return(lfile);
}

void
freefile(char **lfile)
{
	int i;

	if (lfile == NULL)
		return;
	for (i = 0;lfile[i] != NULL; i++)
		XFREE(lfile[i]);

	XFREE(lfile);
}

int
file_exists(const char *path)
{
	struct stat sb;

	if (stat(path, &sb) < 0)
		return(0);
	else
		return(1);
}

int
filelines(const char *path)
{
	int i;
	FILE *fp;
	char line[MAXLEN];

	fp = fopen(path, "r");
	if (fp == NULL)
		return(0);

	for (i = 0; fgets(line, MAXLEN, fp) != NULL; i++);
	fclose(fp);

	return(i);
}
