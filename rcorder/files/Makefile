# $NetBSD: Makefile,v 1.1.1.1 2003/04/28 16:16:41 jeremy-c-reed Exp $

INSTALL?= /usr/bin/install -c

all:	rcorder

rcorder: ealloc.o hash.o rcorder.o
	$(CC) $(CFLAGS) -o $@ $> -lnbcompat

.c.o:
	$(CC) $(CFLAGS) -I${PREFIX}/include/libnbcompat -c $< -o $@

install:
	${INSTALL} rcorder ${PREFIX}/sbin
	${INSTALL} -m 444 rcorder.8 ${PREFIX}/man/man8
