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
 * $Id: tools.h,v 1.2 2005/02/22 09:52:41 imilh Exp $ 
 */

#ifndef _TOOLS_H
#define _TOOLS_H

#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <limits.h>
#include <sys/queue.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#include <string.h>
#include <err.h>

#define MAXLEN LINE_MAX
#define D_WARN 5
#define D_INFO 10
#define T_FALSE 0
#define T_TRUE 1

#define R_READ(fd, buf, len)						\
	if (read(fd, buf, len) < 0) {					\
		warn("read()");						\
	        pthread_exit(NULL);					\
	}

#define R_CLOSE(fd)							\
	do {								\
		close(fd);						\
		pthread_exit(NULL);					\
	} while (/* CONSTCOND */ 0)

#define XMALLOC(elm, size)						\
	do {								\
		elm = malloc(size);					\
		if (elm == NULL)					\
			err(1, "can't allocate memory\n");		\
	} while (/* CONSTCOND */ 0)

#define XSTRDUP(dest, src)						\
	do {								\
		if (src == NULL)					\
			dest = NULL;					\
		else {							\
			dest = strdup(src);				\
			if (dest == NULL)				\
				err(1, "can't strdup %s\n", src);	\
		}							\
	} while (/* CONSTCOND */ 0)

#define XFREE(elm)							\
	do {								\
		if (elm != NULL) {					\
			free(elm);					\
			elm = NULL;					\
		}							\
	} while (/* CONSTCOND */ 0)

extern int trimcr(char *);
extern char **splitstr(char *, const char *);
extern void free_list(char ***);
extern char *strreplace(char *, const char *, const char *);
extern void cut_str(char *, int);
extern void d_printf(uint8_t, char *, ...);
extern int min(int, int);
extern int max(int, int);
extern void line_padding(char *, char, int);
/* host, port*/
extern int tcpclient(char *, int);

#endif
