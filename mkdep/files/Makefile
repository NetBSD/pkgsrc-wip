# $NetBSD: Makefile,v 1.1.1.1 2003/09/24 00:44:08 jeremy-c-reed Exp $

all:	mkdep

mkdep: findcc.o mkdep.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $> -lnbcompat

.c.o:
	$(CC) $(CFLAGS) -I${PREFIX}/include/libnbcompat -c $< -o $@
