# $NetBSD: Makefile,v 1.3 2014/04/02 18:23:01 nros Exp $

DISTNAME=	FreeImage3160
PKGNAME=	freeimage-3.16.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freeimage/}
EXTRACT_SUFX=	.zip

MAINTAINER=	nros@users.sourceforge.net
HOMEPAGE=	http://freeimage.sourceforge.net/
COMMENT=	Image reading library
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/FreeImage
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
	${INSTALL_DATA} Source/FreeImage.h ${DESTDIR}${PREFIX}/include && \
	${INSTALL_DATA} Wrapper/FreeImagePlus/FreeImagePlus.h ${DESTDIR}${PREFIX}/include && \
	${INSTALL_DATA} lib${PKGBASE}.a ${DESTDIR}${PREFIX}/lib && \
	${INSTALL_DATA} lib${PKGBASE}plus.a ${DESTDIR}${PREFIX}/lib && \
	${INSTALL_LIB} lib${PKGBASE}-${PKGVERSION}.so ${DESTDIR}${PREFIX}/lib && \
	${INSTALL_LIB} lib${PKGBASE}plus-${PKGVERSION}.so ${DESTDIR}${PREFIX}/lib && \
	ln -sf lib${PKGBASE}-${PKGVERSION}.so ${DESTDIR}${PREFIX}/lib/lib${PKGBASE}.so.3 && \
	ln -sf lib${PKGBASE}.so.3 ${DESTDIR}${PREFIX}/lib/lib${PKGBASE}.so && \
	ln -sf lib${PKGBASE}plus-${PKGVERSION}.so ${DESTDIR}${PREFIX}/lib/lib${PKGBASE}plus.so.3 && \
        ln -sf lib${PKGBASE}plus.so.3 ${DESTDIR}${PREFIX}/lib/lib${PKGBASE}plus.so

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
