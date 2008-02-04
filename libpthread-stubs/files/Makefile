# $NetBSD: Makefile,v 1.4 2008/02/04 20:58:54 tnn2 Exp $

all: libpthread-stubs.la

libpthread-stubs.la: pthread-stubs.lo
	${LIBTOOL} --mode=link ${CC} -o $@ $? \
	-export-symbols pth.sym -rpath ${PREFIX}/lib

pthread-stubs.lo: pthread-stubs.c
	${LIBTOOL} --mode=compile ${CC} -c -o $@ $?


install:
	${BSD_INSTALL_LIB_DIR} ${PREFIX}/lib
	${LIBTOOL} --mode=install ${BSD_INSTALL_LIB} libpthread-stubs.la \
		${PREFIX}/lib
	${BSD_INSTALL_DATA_DIR} ${PREFIX}/lib/pkgconfig
	${BSD_INSTALL_DATA} pthread-stubs.pc ${PREFIX}/lib/pkgconfig
