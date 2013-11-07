# $NetBSD: Makefile,v 1.1 2013/11/07 18:42:17 nros Exp $

DISTNAME=	FreeImage3154
PKGNAME=	freeimage-3.15.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freeimage/}
EXTRACT_SUFX=	.zip

MAINTAINER=	nros@users.sourceforge.net
HOMEPAGE=	http://freeimage.sourceforge.net/
COMMENT=	Image reading library
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGBASE}
USE_TOOLS+=	gmake
USE_LANGUAGES+= c c++

.include "../../mk/bsd.prefs.mk"

do-build:
.if defined(MAKE_JOBS)
	cd ${WRKSRC} && \
	${MAKE_PROGRAM} -j ${MAKE_JOBS} -f Makefile.gnu && \
	${MAKE_PROGRAM} -j ${MAKE_JOBS} -f Makefile.fip
.else
	cd ${WRKSRC} && \
	${MAKE_PROGRAM} -f Makefile.gnu && \
	${MAKE_PROGRAM} -f Makefile.fip
.endif


INSTALLATION_DIRS+= include
INSTALLATION_DIRS+= lib
do-install:
	cd ${WRKSRC} && \
	${INSTALL_DATA} Source/${PKGBASE}.h ${DESTDIR}${PREFIX}/include && \
	${INSTALL_DATA} Wrapper/${PKGBASE}Plus/${PKGBASE}Plus.h ${DESTDIR}${PREFIX}/include && \
	${INSTALL_DATA} libfreeimage.a ${DESTDIR}${PREFIX}/lib && \
	${INSTALL_DATA} libfreeimageplus.a ${DESTDIR}${PREFIX}/lib && \
	${INSTALL_LIB} libfreeimage-${PKGVERSION}.so ${DESTDIR}${PREFIX}/lib && \
	${INSTALL_LIB} libfreeimageplus-${PKGVERSION}.so ${DESTDIR}${PREFIX}/lib && \
	ln -sf libfreeimage-${PKGVERSION}.so ${DESTDIR}${PREFIX}/lib/libfreeimage.so.3 && \
	ln -sf libfreeimage.so.3 ${DESTDIR}${PREFIX}/lib/libfreeimage.so && \
	ln -sf libfreeimageplus-${PKGVERSION}.so ${DESTDIR}${PREFIX}/lib/libfreeimageplus.so.3 && \
        ln -sf libfreeimageplus.so.3 ${DESTDIR}${PREFIX}/lib/libfreeimageplus.so

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
