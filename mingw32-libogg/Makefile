# $NetBSD: Makefile,v 1.1.1.1 2003/12/08 17:51:33 mpasternak Exp $

DISTNAME=	libogg-1.0
PKGNAME=	${MINGW_PKG_PREFIX}libogg-1.0.0.8
CATEGORIES=	devel audio
MASTER_SITES=	http://www.vorbis.com/files/1.0/unix/

MAINTAINER=	dotz@irc.pl
HOMEPAGE=	http://www.xiph.org/ogg/
COMMENT=	Ogg project codecs library

NO_CONFIGURE=	# defined

do-build:
	${CC} -c -I ${WRKSRC}/include ${WRKSRC}/src/framing.c -o ${WRKSRC}/src/framing.o
	${CC} -c -I ${WRKSRC}/include ${WRKSRC}/src/bitwise.c -o ${WRKSRC}/src/bitwise.o
	${CC} -shared -o ${WRKSRC}/libogg-1.0.dll -Wl,--out-implib=${WRKSRC}/libogg.a ${WRKSRC}/src/framing.o ${WRKSRC}/src/bitwise.o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libogg-1.0.dll ${PREFIX}/${MINGWTARGET}/lib/libogg-1.0.dll
	${INSTALL_DATA} ${WRKSRC}/libogg.a ${PREFIX}/${MINGWTARGET}/lib/libogg.a
	${INSTALL_DATA_DIR} ${PREFIX}/${MINGWTARGET}/include/ogg/
	for a in config_types.h os_types.h ogg.h; do \
		${INSTALL_DATA} ${WRKSRC}/include/ogg/$$a ${PREFIX}/${MINGWTARGET}/include/ogg/$$a; \
	done

.include "../../wip/mk/win32.pkg.mk"
