# $NetBSD: Makefile,v 1.4 2004/10/24 00:09:44 lexort Exp $

DISTNAME=	dcraw-1.212
CATEGORIES=	graphics
MASTER_SITES=	http://www.cybercom.net/~dcoffin/dcraw/
DISTFILES=	dcraw.c dcraw.1
#Perhaps we should extract the version of interest from the RCS file.
#DISTFILES+=	dcraw.c,v

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://www.cybercom.net/~dcoffin/dcraw/HOMEPAGE=
COMMENT=	Program to convert digital camera raw files to ppm

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	dcraw
USE_BUILDLINK3=	yes

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	bin man/man1

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

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
