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
 * $Id: tools.c,v 1.4 2005/03/18 10:50:04 imilh Exp $ 
 */

#include "tools.h"

__inline int
trimcr(char *str)
{
	uint16_t len;
	
	if (str == NULL)
		return (-1);
	
	len = strlen(str);
	
	while (len--)
		if ((str[len] == '\r') || (str[len] == '\n'))
			str[len] = '\0';
	
	return (0);
}

char **
splitstr(char *str, const char *sep)
{
	int i, size;
	char *p, *tmp, **split;
	
	for (i = 0, size = 0; str[i] != '\0'; i++)
		if (str[i] == *sep)
			size++;

	/* size = number of separators + 1 member + NULL */
	size += 2;
	XMALLOC(split, size * sizeof(char *));

	i = 0;
	for (p = str; p != NULL;)
		while ((tmp = strsep(&p, sep)) != NULL) {
			if (*tmp != '\0') {
				while (*tmp == ' ' || *tmp == '\t')
					tmp++;
				XSTRDUP(split[i], tmp);
				i++;
			}
		}

	split[i] = NULL;

	return(split);
}

void
free_list(char ***list)
{
	int i;
	char **plist;

	if (*list != NULL) {
		plist = *list;
		for (i = 0; plist[i] != NULL; i++)
			XFREE(plist[i]);
		XFREE(*list);
	}
}

void
cut_str(char *str, int maxlen)
{
	int len, i, j;

	if (str == NULL)
		return;

	len = strlen(str);

	if (len > maxlen) {
		j = 0;
		/* step back */
		for (i = maxlen - j; j < 3; j++)
			str[i + j] = '.';
		str[i + j] = '\0';
	}
}

int verbose = 10;

/* debug printf, show info if global verbose >= verbosity */
void
d_printf(uint8_t verbosity, char *fmt, ...) {
        char buffer[MAXLEN];
	
        if (verbose >= verbosity ) {
                va_list args;
                va_start(args, fmt);
                vsnprintf(buffer, MAXLEN, fmt, args);
                fprintf(stderr, "%s", buffer);
                va_end(args);
        }
}

__inline int
max(int a, int b)
{
        return (a > b ? a : b);
}
__inline int
min(int a, int b)
{
        return (a < b ? a : b);
}

int
tcpclient(char *host, int port) {
	int s;
	struct sockaddr_in sa;
	struct hostent *he;

	if ((s = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
		warn("socket");
		return (-1);
	}
  
	bzero(&sa, sizeof sa);

	sa.sin_family = AF_INET;
	sa.sin_port = htons(port);

	if ((he = gethostbyname(host)) == NULL) {
		herror(host);
		return (-1);
	}
  
	bcopy(he->h_addr_list[0],&sa.sin_addr, he->h_length);

	if (connect(s, (struct sockaddr *)&sa, sizeof sa) < 0) {
		warn("connect");
		close(s);
		return (-1);
	}

	return (s);
}

/* CAUTION, this function assume you know how long your line is ! */
void
line_padding(char *line, char fill, int len)
{
	int i;
	char *p;

	if (line == NULL || fill == 0 || len == 0)
		return;

	i = strlen(line);
	p = &line[i];
	for (; i < len; i++)
		p[i] = fill;

	p[i] = '\0';
}

char *
strreplace(char *str, const char *from, const char *to)
{
	int fromlen, tolen, i;
	char *p, *ret, buf[MAXLEN];

	memset(buf, 0, MAXLEN);

	fromlen = strlen(from);
	/* keep space for \0's strcat */
	tolen = strlen(to) + 1;

	for (i = 0, p = str; *p != 0;) {
		if (strncmp(p, from, fromlen) == 0) {
			strncat(buf, to, tolen);
			p += fromlen;
			i += tolen;
		} else {
			buf[i] = *p;
			p++;
			i++;
		}
	}
	buf[i] = '\0';

	XSTRDUP(ret, buf);
	return(ret);
}

int
listlen(const char **list)
{
	int i;

	for (i = 0; list[i] != NULL; i++);
	return(i);
}

/* execute a command and receive result on a char ** */
char **
exec_list(const char *cmd, const char *match)
{
	FILE *fp;
	int size;
	char **res, *rawlist, buf[MAXLEN];

	if ((fp = popen(cmd, "r")) == NULL)
		return(NULL);

	rawlist = NULL;
	size = 0;

	while (fgets(buf, MAXLEN, fp) != NULL) {
		if (match == NULL || strstr(buf, match) != NULL) {
			size += (strlen(buf) + 1) * sizeof(char);
			
			XREALLOC(rawlist,  size);
			strcat(rawlist, buf);
		}
	}
	pclose(fp);

	if (rawlist == NULL)
		return(NULL);

	res = splitstr(rawlist, "\n");
	XFREE(rawlist);

	return(res);
}

T_Bool
is_listed(const char **list, const char *item)
{
	for (; *list != NULL; list++)
		if (strcmp(item, *list) == 0)
			return(T_TRUE);

	return(T_FALSE);
}
