/*-
 * Copyright (c) 2003 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Ben Collver <collver1@attbi.com>.
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
 *        This product includes software developed by the NetBSD
 *        Foundation, Inc. and its contributors.
 * 4. Neither the name of The NetBSD Foundation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * This utility allows you to generate from an ISO10646-1 encoded
 * BDF font other BDF fonts in any possible encoding. This way, you can
 * derive from a single ISO10646-1 master font a whole set of 8-bit
 * fonts in all ISO 8859 and various other encodings. (Hopefully
 * a future XFree86 release will have a similar facility built into
 * the server, which can reencode ISO10646-1 on the fly, because
 * storing the same fonts in many different encodings is clearly
 * a waste of storage capacity).
*/

#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <regex.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* global variable for argv[0] */
char *my_name = NULL;

static char *basename(char *pathname)
{
	char	*ptr;

	ptr = strrchr(pathname, '/');
	return ((ptr == NULL) ? pathname : &ptr[1]);
}

/* "CLASS" "z" string and memory manipulation */

void *zmalloc(size_t size)
{
	void *r;
	r = malloc(size);
	if (r == NULL) {
		perror(my_name);
		exit(errno);
	}
	memset(r, 0, size);
	return r;
}

void *zrealloc(void *ptr, size_t size)
{
	void *temp;
	temp = realloc(ptr, size);
	if (temp == NULL) {
		perror(my_name);
		exit(errno);
	}
	return temp;
}

char *zstrdup(const char *str)
{
	char *retval;

	if (str == NULL) {
		fprintf(stderr, "%s: zstrdup(NULL)\n", my_name);
		exit(1);
	}
	retval = strdup(str);
	if (retval == NULL) {
		perror(my_name);
		exit(errno);
	}
	return retval;
}

void zstrcpy(char **dest, const char *source)
{
	if (*dest != NULL)
		free(*dest);
	*dest = zstrdup(source);
}

void zstrcat(char **dest, const char *source)
{
	int dest_size = 1;
	int source_size;

	if (*dest != NULL)
		dest_size = strlen(*dest) + 1;
	source_size = strlen(source);
	*dest = zrealloc(*dest, dest_size + source_size);
	(*dest)[dest_size - 1] = '\000';
	strcat(*dest, source);
}

void zstrtoupper(char *s)
{
	char *t;

	for (t = s; *t != '\000'; t++)
		*t = toupper(*t);
}

char *zitoa(int value)
{
	static char zitoa_buf[23];
	char *p = zitoa_buf;
	int n = value;
	int i = 10;

	if (n < 0) {
		*p++ = '-';
		n *= -1;
	}
	while (n / i)
		i *= 10;
	while (i > 9) {
		i /= 10;
		*p++ = '0' + n / i;
		n -= n / i * i;
	}
	*p = '\000';
	return zitoa_buf;
}

#define zs_true(x)	(x != NULL && strcmp(x, "0") != 0)
#define zi_true(x)	(x == 1)

/* "CLASS" regular expression cache */

typedef struct {
	char *name;
	int size;
	char **keys;
	void **values;
} rc_t;

rc_t *rc_new(char *name)
{
	rc_t *rc;

	rc = zmalloc(sizeof(rc_t));
	rc->size = 0;
	rc->keys = NULL;
	rc->values = NULL;
	rc->name = NULL;
	zstrcpy(&(rc->name), name);
	return rc;
}

int rc_find(rc_t *rc, const char *key)
{
	int i = rc->size;
	int r = -1;

	while (i-- > 0)
		if (key == rc->keys[i])
			r = i;
	return r;
}

void *rc_fetch(rc_t *rc, const char *key)
{
	int i;
	void *r = NULL;

	i = rc_find(rc, key);
	if (i != -1)
		r = rc->values[i];
	return r;
}

void rc_add(rc_t *rc, const char *key, void *value)
{
	int i;
	i = rc_find(rc, key);
	if (i == -1) {
		i = rc->size;
		rc->size++;
		rc->keys = zrealloc(rc->keys, rc->size * sizeof(char *));
		rc->keys[i] = (char *)key;
		rc->values = zrealloc(rc->values, rc->size * sizeof(void *));
		rc->values[i] = value;
	} else {
		free(rc->values[i]);
		rc->values[i] = value;
	}
}

#define rc_size(rc) (rc->size)

/* "CLASS" "dynamic array" */

typedef struct {
	char *name;
	int size;
	int count;
	void **values;
	void *nv;
} da_t;

da_t *da_new(char *name)
{
	da_t *da;

	da = zmalloc(sizeof(da_t));
	da->size = 0;
	da->count = 0;
	da->values = NULL;
	da->nv = NULL;
	da->name = NULL;
	zstrcpy(&(da->name), name);
	return da;
}

void *da_fetch(da_t *da, int key)
{
	void *r = NULL;

	if (key >= 0 && key < da->size && da->values[key] != NULL)
		r = da->values[key];
	else
		if (key == -1 && da->nv != NULL)
			r = da->nv;

	return r;
}

int da_fetch_int(da_t *da, int key)
{
	int *t;
	int r = -1;
	t = da_fetch(da, key);
	if (t != NULL)
		r = *t;
	return r;
}

#define da_fetch_str(a,k)	\
	(char *)da_fetch(a,k)

void da_add(da_t *da, int key, void *value)
{
	int i = da->size;
	if (key >= 0) {
		if (key >= da->size) {
			da->size = key + 1;
			da->values = zrealloc(da->values,
				da->size * sizeof(void *));
			for (; i < da->size; i++)
				da->values[i] = NULL;
		}
		if (da->values[key] != NULL) {
			free(da->values[key]);
		} else {
			if (value == NULL) {
				if (da->count > 0)
					da->count--;
			} else {
				da->count++;
			}
		}
		da->values[key] = value;
	} else if (key == -1) {
		if (da->nv != NULL)
			free(da->nv);
		da->nv = value;
	}
}

void da_add_str(da_t *da, int key, char *value)
{
	da_add(da, key, zstrdup(value));
}

void da_add_int(da_t *da, int key, int value)
{
	int *v;

	v = zmalloc(sizeof(int));
	*v = value;
	da_add(da, key, v);
}

#define da_count(da) (da->count)
#define da_size(da) (da->size)

void da_clear(da_t *da)
{
	int i;

	for (i = da->size; i; i--)
		free(da->values[i]);
	if (da->values != NULL)
		free(da->values);
	da->size = 0;
	da->count = 0;
	da->values = NULL;
}

/* "CLASS" regular expression support */

#define err_buffer_size 2048
void comp_regex(regex_t *rx, char *expression, int cflags)
{
	int retval;
	char err_buffer[err_buffer_size];

	retval = regcomp(rx, expression, cflags);
	if (retval != 0) {
		regerror(retval, rx, err_buffer, err_buffer_size);
		fprintf(stderr, "%s: %s", my_name, err_buffer);
		exit(retval);
	}
}

rc_t *regex_cache = NULL;
#define regmatch_size 20
regmatch_t rm[regmatch_size];

int do_regex(char *buffer, char *expression, int cflags)
{
	regex_t *rx;
	int r;

	rx = rc_fetch(regex_cache, expression);
	if (rx == NULL) {
		rx = zmalloc(sizeof(regex_t));
		comp_regex(rx, expression, cflags);
		rc_add(regex_cache, expression, rx);
	}

	r = regexec(rx, buffer, regmatch_size, rm, 0);

	return !r;
}

#define regex(b,e) do_regex(b,e,REG_EXTENDED)
#define regexm(b,e) do_regex(b,e,REG_EXTENDED|REG_NEWLINE)
#define regexi(b,e) do_regex(b,e,REG_EXTENDED|REG_ICASE)

char *rmbuf = NULL;
char *match(char *buffer, int n)
{
	int length;

	length = rm[n].rm_eo - rm[n].rm_so;
	if (rmbuf != NULL)
		free(rmbuf);
	rmbuf = zmalloc(length + 1);
	memcpy(rmbuf, &buffer[rm[n].rm_so], length);
	return rmbuf;
}

int xmatch(char *buffer, int n)
{
	int r;
	char *t = NULL;

	zstrcpy(&t, "0x");
	zstrcat(&t, match(buffer, n));
	r = strtol(t, NULL, 16);
	free(t);
	return r;
}

char *srbuf = NULL;

char *search_replace_sub(char *buffer, char *expression, char *replacement,
	int cflags)
{
	zstrcpy(&srbuf, buffer);
	if (do_regex(buffer, expression, cflags)) {
		srbuf[rm[0].rm_so] = '\000';
		zstrcat(&srbuf, replacement);
		zstrcat(&srbuf, &buffer[rm[0].rm_eo]);
	}
	return srbuf;
}

#define search_replace(b,e,r) \
	search_replace_sub(b,e,r,REG_EXTENDED)

#define search_replacem(b,e,r) \
	search_replace_sub(b,e,r,REG_EXTENDED|REG_NEWLINE)

/* "CLASS" file input */

int read_line(FILE *fp, char **buffer)
{
	int buffer_size = 1;
	int eof = 0;
	signed char c;

	zstrcpy(buffer, "");

	c = fgetc(fp);
	if (c == EOF && (feof(fp) || ferror(fp)))
		eof = 1;

	while (c != '\n' && !eof) {
		buffer_size++;
		*buffer = zrealloc(*buffer, buffer_size);
		strncat(*buffer, &c, 1);
		(*buffer)[buffer_size - 1] = 0;
		c = fgetc(fp);
		if (c == EOF && (feof(fp) || ferror(fp)))
			eof = 1;
	}

	if (eof) {
		free(*buffer);
		*buffer = NULL;
		return 0;
	}

	return 1;
}

/* BEGIN */

/*
DEC VT100 graphics characters in the range 1-31 (as expected by
some old xterm versions and a few other applications)
*/
#define decmap_size 31
int decmap[decmap_size] = {
	0x25C6, /* BLACK DIAMOND */
	0x2592, /* MEDIUM SHADE */
	0x2409, /* SYMBOL FOR HORIZONTAL TABULATION */
	0x240C, /* SYMBOL FOR FORM FEED */
	0x240D, /* SYMBOL FOR CARRIAGE RETURN */
	0x240A, /* SYMBOL FOR LINE FEED */
	0x00B0, /* DEGREE SIGN */
	0x00B1, /* PLUS-MINUS SIGN */
	0x2424, /* SYMBOL FOR NEWLINE */
	0x240B, /* SYMBOL FOR VERTICAL TABULATION */
	0x2518, /* BOX DRAWINGS LIGHT UP AND LEFT */
	0x2510, /* BOX DRAWINGS LIGHT DOWN AND LEFT */
	0x250C, /* BOX DRAWINGS LIGHT DOWN AND RIGHT */
	0x2514, /* BOX DRAWINGS LIGHT UP AND RIGHT */
	0x253C, /* BOX DRAWINGS LIGHT VERTICAL AND HORIZONTAL */
	0x23BA, /* HORIZONTAL SCAN LINE-1 (Unicode 3.2 draft) */
	0x23BB, /* HORIZONTAL SCAN LINE-3 (Unicode 3.2 draft) */
	0x2500, /* BOX DRAWINGS LIGHT HORIZONTAL */
	0x23BC, /* HORIZONTAL SCAN LINE-7 (Unicode 3.2 draft) */
	0x23BD, /* HORIZONTAL SCAN LINE-9 (Unicode 3.2 draft) */
	0x251C, /* BOX DRAWINGS LIGHT VERTICAL AND RIGHT */
	0x2524, /* BOX DRAWINGS LIGHT VERTICAL AND LEFT */
	0x2534, /* BOX DRAWINGS LIGHT UP AND HORIZONTAL */
	0x252C, /* BOX DRAWINGS LIGHT DOWN AND HORIZONTAL */
	0x2502, /* BOX DRAWINGS LIGHT VERTICAL */
	0x2264, /* LESS-THAN OR EQUAL TO */
	0x2265, /* GREATER-THAN OR EQUAL TO */
	0x03C0, /* GREEK SMALL LETTER PI */
	0x2260, /* NOT EQUAL TO */
	0x00A3, /* POUND SIGN */
	0x00B7  /* MIDDLE DOT */
};

int is_control(int ucs)
{
	return ((ucs >= 0x00 && ucs <= 0x1f) ||
		(ucs >= 0x7f && ucs <= 0x9f));
}

int is_blockgraphics(int ucs)
{
	return ucs >= 0x2500 && ucs <= 0x25FF;
}

/* calculate the bounding box that covers both provided bounding boxes */
typedef struct {
	int cwidth;
	int cheight;
	int cxoff;
	int cyoff;
} bbx_t;

bbx_t *combine_bbx(int awidth, int aheight, int axoff, int ayoff,
	int cwidth, int cheight, int cxoff, int cyoff, bbx_t *r)
{
	r->cwidth = cwidth;
	r->cheight = cheight;
	r->cxoff = cxoff;
	r->cyoff = cyoff;

	if (axoff < r->cxoff) {
		r->cwidth += r->cxoff - axoff;
		r->cxoff = axoff;
	}
	if (ayoff < r->cyoff) {
		r->cheight += r->cyoff - ayoff;
		r->cyoff = ayoff;
	}
	if (awidth + axoff > r->cwidth + r->cxoff) {
		r->cwidth = awidth + axoff - r->cxoff;
	}
	if (aheight + ayoff > r->cheight + r->cyoff) {
		r->cheight = aheight + ayoff - r->cyoff;
	}

	return r;
}

void usage(void) {
	printf("%s", "\n"
"Usage: ucs2any [+d|-d] <source-name> { <mapping-file> <registry-encoding> }\n"
"\n"
"where\n"
"\n"
"   +d                   put DEC VT100 graphics characters in the C0 range\n"
"                        (default for upright charcell fonts)\n"
"\n"
"   -d                   do not put DEC VT100 graphics characters in the\n"
"                        C0 range (default for all other font types)\n"
"\n"
"   <source-name>        is the name of an ISO10646-1 encoded BDF file\n"
"\n"
"   <mapping-file>       is the name of a character set table like those on\n"
"                        <ftp://ftp.unicode.org/Public/MAPPINGS/>\n"
"\n"
"   <registry-encoding>  are the CHARSET_REGISTRY and CHARSET_ENCODING\n"
"                        field values for the font name (XLFD) of the\n"
"                        target font, separated by a hyphen\n"
"\n"
"Example:\n"
"\n"
"   ucs2any 6x13.bdf 8859-1.TXT iso8859-1 8859-2.TXT iso8859-2\n"
"\n"
"will generate the files 6x13-iso8859-1.bdf and 6x13-iso8859-2.bdf\n"
"\n");
}

int chars_compare(const void *aa, const void *bb)
{
	int a = *(int *)aa;
	int b = *(int *)bb;

	return a - b;
}

int main(int argc, char *argv[])
{
	int ai = 1;
	int dec_chars = -1;
	char *fsource = NULL;
	FILE *fsource_fp;
	int properties;
	int default_char;
	char *l = NULL;
	char *t = NULL;
	char *startfont = NULL;
	char *header = NULL;
	char *slant = NULL;
	char *spacing = NULL;
	char *sc = NULL;
	int code;
	da_t *startchar;
	da_t *my_char;
	char *fmap = NULL;
	char *registry = NULL;
	char *encoding = NULL;
	FILE *fmap_fp;
	da_t *map;
	int target;
	int ucs;
	int i;
	int j;
	int *chars = NULL;
	bbx_t bbx;
	char *fout = NULL;
	FILE *fout_fp;
	char *newheader = NULL;
	int k;
	char *registry_encoding = NULL;

	zstrcpy(&my_name, argv[0]);

	regex_cache = rc_new("regex_cache");
	startchar = da_new("startchar");
	my_char = da_new("my_char");
	map = da_new("map");

	if (argc < 2) {
		usage();
		exit(0);
	}

	/* check options */
	if (strcmp(argv[ai], "+d") == 0) {
		ai++;
		dec_chars = 1;
	} else if (strcmp(argv[ai], "-d") == 0) {
		ai++;
		dec_chars = 0;
	}

	/* open and read source file */
	zstrcpy(&fsource, argv[ai]);
	fsource_fp = fopen(fsource, "r");
	if (fsource_fp == NULL) {
		fprintf(stderr, "%s: Can't read file '%s': %s!\n", my_name,
			fsource, strerror(errno));
		exit(1);
	}

	/* read header */
	properties = 0;
	default_char = 0;
	while (read_line(fsource_fp, &l)) {
		if (regex(l, "^CHARS[ \t]"))
			break;
		if (regex(l, "^STARTFONT")) {
			zstrcpy(&startfont, l);
		} else if (regex(l, "^_XMBDFED_INFO[[:space:]]") ||
			regex(l, "^_XFREE86_GLYPH_RANGES[ \t]"))
		{
			properties--;
		} else if (regex(l, "DEFAULT_CHAR[[:space:]]+([[:digit:]]+)[[:space:]]*$"))
		{
			default_char = atoi(match(l, 1));
			zstrcat(&header, "DEFAULT_CHAR 0\n");
		} else {
			if (regex(l, "^STARTPROPERTIES[[:space:]]+([[:digit:]]+)"))
			{
				properties = atoi(match(l, 1));
			} else if (regex(l, "^FONT[[:space:]]+(.*-([^-]*-[^[:space:]]*))[[:space:]]*$"))
			{
				if (strcmp(match(l, 2), "ISO10646-1") != 0) {
					fprintf(stderr,
						"%s: FONT name in '%s' is '%s' and not '*-ISO10646-1'!\n",
						my_name, fsource, match(l, 1));
					exit(1);
				}
			} else if (regex(l, "CHARSET_REGISTRY[[:space:]]+\"(.*)\"[[:space:]]*$"))
			{
				if (strcmp(match(l, 1), "ISO10646") != 0) {
					fprintf(stderr,
						"%s: CHARSET_REGISTRY in '%s' is '%s' and not 'ISO10646'!\n",
						my_name, fsource, match(l, 1));
					exit(1);
				}
			} else if (regex(l, "^CHARSET_ENCODING[[:space:]]+\"(.*)\"[[:space:]]*$"))
			{
				if (strcmp(match(l, 1), "1") != 0) {
					fprintf(stderr,
						"%s: CHARSET_ENCODING in '%s' is '%s' and not '1'!\n",
						my_name, fsource, match(l, 1));
					exit(1);
				}
			} else if (regex(l, "^SLANT[[:space:]]+\"(.*)\"[[:space:]]*$"))
			{
				zstrcpy(&slant, match(l, 1));
				zstrtoupper(slant);
			} else if (regex(l, "^SPACING[[:space:]]+\"(.*)\"[[:space:]]*$"))
			{
				zstrcpy(&spacing, match(l, 1));
				zstrtoupper(spacing);
			}
			if (regex(l, "^COMMENT[[:space:]]+\"(.*)\"$")) {
				zstrcat(&header, "COMMENT ");
				zstrcat(&header, match(l, 1));
				zstrcat(&header, "\n");
			} else if (regex(l, "^COMMENT[[:space:]]+$Id: ucs2any.c,v 1.2 2003/08/08 14:03:22 xtraeme Exp $[[:space:]]*$"))
			{
				zstrcat(&header, "COMMENT Derived from ");
				zstrcat(&header, match(l, 1));
				zstrcat(&header, "\n");
			} else {
				zstrcat(&header, l);
				zstrcat(&header, "\n");
			}
		}
	}

	if (startfont == NULL) {
		fprintf(stderr, "%s: No STARTFONT line found in '%s'!\n",
			my_name, fsource);
		exit(1);
	}

	zstrcpy(&t, "\nSTARTPROPERTIES ");
	zstrcat(&t, zitoa(properties));
	zstrcat(&t, "\n");
	zstrcpy(&header, search_replace(header,
		"\nSTARTPROPERTIES[[:space:]]+([[:digit:]]+)\n", t));


	/* read characters */
	while (read_line(fsource_fp, &l)) {
		if (regex(l, "^STARTCHAR")) {
			zstrcpy(&sc, l);
			zstrcat(&sc, "\n");
			code = -1;
		} else if (regex(l, "^ENCODING[[:space:]]+(-?[[:digit:]]+)")) {
			code = atoi(match(l, 1));
			da_add_str(startchar, code, sc);
			da_add_str(my_char, code, "");
		} else if (regex(l, "^ENDFONT$")) {
			code = -1;
			zstrcpy(&sc, "STARTCHAR ???\n");
		} else {
			zstrcpy(&t, da_fetch_str(my_char, code));
			zstrcat(&t, l);
			zstrcat(&t, "\n");
			da_add_str(my_char, code, t);
			if (regex(l, "^ENDCHAR$")) {
				code = -1;
				zstrcpy(&sc, "STARTCHAR ???\n");
			}
		}
	}

	fclose(fsource_fp);

	ai++;
	while (ai < argc) {
		zstrcpy(&fmap, argv[ai]);
		i = ai + 1;
		if (i < argc && regex(argv[i], "^([^-]+)-([^-]+)$")) {
			zstrcpy(&registry, match(argv[i], 1));
			zstrcpy(&encoding, match(argv[i], 2));
		} else {
			fprintf(stderr,
				"%s: Argument registry-encoding '%s' not in expected format!\n",
				my_name, i < argc ? fmap : "");
			exit(1);
		}

		ai++;
		ai++;

		/* open and read source file */
		fmap_fp = fopen(fmap, "r");
		if (fmap_fp == NULL) {
			fprintf(stderr,
				"%s: Can't read mapping file '%s': %s!\n",
				my_name, fmap, strerror(errno));
			exit(1);
		}

		da_clear(map);

		while (read_line(fmap_fp, &l)) {
			if (regex(l, "^[[:space:]]*(#.*)?$"))
				continue;
			if (regex(l, "^[[:space:]]*(0[xX])?([[:xdigit:]]{2})[[:space:]]+(0[xX]|U\\+|U-)?([[:xdigit:]]{4})"))
			{
				target = xmatch(l, 2);
				ucs = xmatch(l, 4);
				if (!is_control(ucs)) {
					if (zs_true(da_fetch_str(startchar,
						ucs)))
					{
						da_add_int(map, target, ucs);
					} else {
						if (!((is_blockgraphics(ucs) &&
							strcmp(slant, "R") != 0) ||
							(ucs >= 0x200e &&
							ucs <= 0x200f)))							{
							fprintf(stderr,
								"No glyph for character U+%04X (0x%02x) available.\n",
								ucs, target);
						}
					}
				}
			} else {
				fprintf(stderr,
					"Unrecognized line in '%s':\n%s\n",
					fmap, l);
			}
		}
		fclose(fmap_fp);

		/* add default character */
		if (!zi_true(da_fetch_int(map, 0))) {
			if (zs_true(da_fetch_str(startchar, default_char))) {
				da_add_int(map, 0, default_char);
				da_add_str(startchar, default_char,
					"STARTCHAR defaultchar\n");
			} else {
				fprintf(stderr, "%s",
					"No default character defined.\n");
			}
		}

		if (dec_chars == 1 ||
			(dec_chars == -1 && strcmp(slant, "R") == 0 &&
			strcmp(spacing, "C") == 0))
		{
			/* add DEC VT100 graphics characters in the range 1-31
			   (as expected by some old xterm versions) */
			for (i = 0; i < decmap_size; i++) {
				if (zs_true(da_fetch_str(startchar, decmap[i])))
				{
					da_add_int(map, i + 1, decmap[i]);
				}
			}
		}

		/* list of characters that will be written out */
		j = da_count(map);
		if (j < 0) {
			fprintf(stderr,
				"No characters found for %s-%s.\n",
				registry, encoding);
			continue;
		}
		if (chars != NULL)
			free(chars);
		chars = zmalloc(j * sizeof(int));
		memset(chars, 0, j * sizeof(int));
		for (k = 0, i = 0; k < da_count(map) && i < da_size(map); i++) {
			if (da_fetch(map, i) != NULL)
				chars[k++] = i;
		}
		qsort(chars, j, sizeof(int), chars_compare);

		/* find overall font bounding box */
		bbx.cwidth = -1;
		for (i = 0; i < j; i++) {
			ucs = da_fetch_int(map, chars[i]);
			zstrcpy(&t, da_fetch_str(my_char, ucs));
			if (regexm(t,
				"^BBX[[:space:]]+([[:digit:]]+)[[:space:]]+([[:digit:]]+)[[:space:]]+(-?[[:digit:]]+)[[:space:]]+(-?[[:digit:]]+)[[:space:]]*$"))
			{
				if (bbx.cwidth == -1) {
					bbx.cwidth = atoi(match(t, 1));
					bbx.cheight = atoi(match(t, 2));
					bbx.cxoff = atoi(match(t, 3));
					bbx.cyoff = atoi(match(t, 4));
				} else {
					combine_bbx(bbx.cwidth, bbx.cheight,
						bbx.cxoff, bbx.cyoff,
						atoi(match(t, 1)),
						atoi(match(t, 2)),
						atoi(match(t, 3)),
						atoi(match(t, 4)),
						&bbx);
				}
			} else {
				fprintf(stderr,
					"Warning: No BBX found for U+%04X!\n",
					ucs);
			}
		}

		/* generate output file name */
		zstrcpy(&registry_encoding, "-");
		zstrcat(&registry_encoding, registry);
		zstrcat(&registry_encoding, "-");
		zstrcat(&registry_encoding, encoding);

		if (regexi(fsource, "^(.*).bdf$")) {
			zstrcpy(&fout, match(fsource, 1));
			zstrcat(&fout, registry_encoding);
			zstrcat(&fout, ".bdf");
		} else {
			zstrcpy(&fout, match(fsource, 1));
			zstrcat(&fout, registry_encoding);
		}

		/* remove path prefix */
		zstrcpy(&t, basename(fout));
		zstrcpy(&fout, t);

		/* write new BDF file */
		fprintf(stderr, "Writing %d characters into file '%s'.\n",
			j, fout);
		fout_fp = fopen(fout, "w");
		if (fout_fp == NULL) {
			fprintf(stderr, "%s: Can't write file '%s': %s!\n",
				my_name, fout, strerror(errno));
			exit(1);
		}

		fprintf(fout_fp, "%s\n", startfont);
		fprintf(fout_fp, "%s",
			"COMMENT AUTOMATICALLY GENERATED FILE. DO NOT EDIT!\n");
		fprintf(fout_fp,
			"COMMENT Generated with 'ucs2any %s %s %s-%s'\n",
			fsource, fmap, registry, encoding);
		fprintf(fout_fp, "%s",
			"COMMENT from an ISO10646-1 encoded source BDF font.\n");
		fprintf(fout_fp, "%s",
			"COMMENT ucs2any by Ben Collver <collver1@attbi.com>, 2003.\n");
		fprintf(fout_fp, "%s",
			"COMMENT based on ucs2any.pl by Markus Kuhn <mkuhn@acm.org>, 2000.\n");
		zstrcpy(&newheader, header);

		zstrcpy(&t, "FONTBOUNDINGBOX ");
		zstrcat(&t, zitoa(bbx.cwidth));
		zstrcat(&t, " ");
		zstrcat(&t, zitoa(bbx.cheight));
		zstrcat(&t, " ");
		zstrcat(&t, zitoa(bbx.cxoff));
		zstrcat(&t, " ");
		zstrcat(&t, zitoa(bbx.cyoff));

		zstrcpy(&newheader, search_replacem(newheader,
			"^FONTBOUNDINGBOX[[:space:]]+.*$", t));

		if (regexm(newheader,
			"^(FONT[[:space:]]+(.*)-[[:alnum:]_]+-[[:alnum:]_]+[[:space:]]*)$"))
		{
			zstrcpy(&t, "FONT ");
			zstrcat(&t, match(newheader, 2));
			zstrcat(&t, registry_encoding);
			zstrcpy(&newheader, search_replacem(newheader,
				"^(FONT[[:space:]]+(.*)-[[:alnum:]_]+-[[:alnum:]_]+[[:space:]]*)$",
				t));
		}

		zstrcpy(&t, "CHARSET_REGISTRY \"");
		zstrcat(&t, registry);
		zstrcat(&t, "\"");
		zstrcpy(&newheader,
			search_replacem(newheader,
				"^CHARSET_REGISTRY[[:space:]]+.*$",
				t));

		zstrcpy(&t, "CHARSET_ENCODING \"");
		zstrcat(&t, encoding);
		zstrcat(&t, "\"");
		zstrcpy(&newheader,
			search_replacem(newheader,
				"^CHARSET_ENCODING[[:space:]]+.*$",
				t));

		fprintf(fout_fp, "%s", newheader);
		fprintf(fout_fp, "CHARS %d\n", j);

		/* Write characters */
		for (i = 0; i < j; i++) {
			ucs = da_fetch_int(map, chars[i]);
			fprintf(fout_fp, "%s", da_fetch_str(startchar,
				ucs));
			fprintf(fout_fp, "ENCODING %d\n", chars[i]);
			fprintf(fout_fp, "%s", da_fetch_str(my_char,
				ucs));
		}
		fprintf(fout_fp, "%s", "ENDFONT\n");
		fclose(fout_fp);
	}

	exit(0);
}
