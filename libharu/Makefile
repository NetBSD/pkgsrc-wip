# $NetBSD: Makefile,v 1.2 2021/12/28 19:22:04 adam Exp $

DISTNAME=	libharu-2.4.3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=libharu/}
GITHUB_TAG=	v2.4.3
DIST_SUBDIR=	libharu

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libharu/libharu/
COMMENT=	Software library for generating PDF
LICENSE=	zlib

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DLIBHPDF_STATIC=OFF

INSTALLATION_DIRS=	include lib
do-install:
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/src/libhpdf.* ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
post-install: fix-darwin-install-name
fix-darwin-install-name:
	install_name_tool -id ${PREFIX}/lib/libhpdf.dylib \
	    ${DESTDIR}${PREFIX}/lib/libhpdf.dylib
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
