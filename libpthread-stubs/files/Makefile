# $NetBSD: Makefile,v 1.3 2007/05/10 18:09:24 bsadewitz Exp $

all: libpthread-stubs.la

libpthread-stubs.la: pthread-stubs.lo
	${LIBTOOL} --mode=link ${CC} -o $@ $? \
	-export-symbols pth.sym -rpath ${PREFIX}/lib

pthread-stubs.lo: pthread-stubs.c
	${LIBTOOL} --mode=compile ${CC} -c -o $@ $?


install:
	${LIBTOOL} --mode=install ${BSD_INSTALL_LIB} libpthread-stubs.la \
		${PREFIX}/lib
	${BSD_INSTALL_DATA_DIR} ${PREFIX}/lib/pkgconfig
	${BSD_INSTALL_DATA} pthread-stubs.pc ${PREFIX}/lib/pkgconfig
