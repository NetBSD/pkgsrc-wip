# $NetBSD: Makefile,v 1.1.1.1 2004/01/12 06:13:30 marttikuparinen Exp $

dvdbackup.o: dvdbackup.c
	${LIBTOOL} --mode=compile ${CC} -c -I${BUILDLINK_DIR}/include	\
		dvdbackup.c

all dvdbackup: dvdbackup.o
	${LIBTOOL} --mode=link ${CC} -o dvdbackup			\
	       -L${BUILDLINK_DIR}/lib					\
	       -ldvdread dvdbackup.o
