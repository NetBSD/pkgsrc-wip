# $NetBSD: Makefile,v 1.1.1.1 2005/07/19 16:52:50 h2m Exp $

PROG=	typespeed
SRCS=	file.c menu.c misc.c network.c typespeed.c
MAN=	typespeed.6

.include <bsd.prog.mk>

CFLAGS=-I${PREFIX}/include -D_GNU_SOURCE -O -Wall
LDFLAGS+=-L${PREFIX}/lib
LDADD=-lncurses
