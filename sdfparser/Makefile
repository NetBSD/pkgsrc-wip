# $NetBSD$

PKGVER=		0.0.0.1
DISTNAME=	Sdf-${PKGVER}
PKGNAME=	sdfparser-${PKGVER}
CATEGORIES=	cad devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rochus-keller/}
GITHUB_PROJECT=	Sdf
GITHUB_TAG=	4c448dbffa3e9007f34532a0f2c7342e957ee38c
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rochus-keller/Sdf/
COMMENT=	Sdf (Standard Delay Format) parser that supports IEEE 1497-2001
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/Sdf
USE_LANGUAGES=	c++

OBJS=	SdfErrors.o SdfLexer.o SdfSynTree.o SdfTokenType.o SdfFileCache.o SdfParser.o SdfToken.o
HDRS=	SdfErrors.h SdfFileCache.h SdfLexer.h SdfParser.h SdfSynTree.h SdfToken.h SdfTokenType.h
LIBSDF=	libSdf.a

INSTALLATION_DIRS=	lib include/Sdf bin

post-extract:
	cd ${WRKDIR} && ${MV} Sdf-${GITHUB_TAG} Sdf

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake Sdf.pro

post-build:
	cd ${WRKSRC} && ${AR} ${ARFLAGS} ${LIBSDF} ${OBJS}

post-install:
	cd ${WRKSRC}; \
	${INSTALL_DATA} ${HDRS} ${DESTDIR}${PREFIX}/include/Sdf; \
	${INSTALL_LIB} ${LIBSDF} ${DESTDIR}${PREFIX}/lib; \
	${INSTALL_PROGRAM} Sdf ${DESTDIR}${PREFIX}/bin

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
