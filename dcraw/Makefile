# $NetBSD: Makefile,v 1.3 2004/10/23 23:47:05 lexort Exp $

DISTNAME=	dcraw-1.212
CATEGORIES=	graphics
MASTER_SITES=	http://www.cybercom.net/~dcoffin/dcraw/
DISTFILES=	dcraw.c dcraw.1

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://www.cybercom.net/~dcoffin/dcraw/HOMEPAGE=
COMMENT=	Program to convert digital camera "raw" files to ppm

USE_BUILDLINK3=	yes

DIST_SUBDIR=	dcraw

WRKSRC=		${WRKDIR}

do-extract:
	for f in ${DISTFILES}; do					\
		${CP} ${_DISTDIR}//$$f ${WRKDIR};			\
	done

do-build:
	cd ${WRKDIR} && ${CC} ${CPPFLAGS} ${CFLAGS} -c dcraw.c
	cd ${WRKDIR} && ${CC} ${LDFLAGS} -o dcraw dcraw.o -ljpeg -lm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dcraw ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dcraw.1 ${PREFIX}/man/man1

.include "../../mk/bsd.prefs.mk"

.include "../../graphics/jpeg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
