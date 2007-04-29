# $NetBSD: Makefile,v 1.2 2007/04/29 20:37:28 bsadewitz Exp $

all: libpthread-stubs.la

libpthread-stubs.la: pthread-stubs.lo
	${LIBTOOL} --mode=link ${CC} -o $@ $? -rpath ${PREFIX}/lib

pthread-stubs.lo: pthread-stubs.c
	${LIBTOOL} --mode=compile ${CC} -c -o $@ $?

install:
	${LIBTOOL} --mode=install ${BSD_INSTALL_LIB} libpthread-stubs.la \
		${PREFIX}/lib
	${BSD_INSTALL_DATA_DIR} ${PREFIX}/lib/pkgconfig
	${BSD_INSTALL_DATA} pthread-stubs.pc ${PREFIX}/lib/pkgconfig
