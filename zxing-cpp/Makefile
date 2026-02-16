# $NetBSD: Makefile,v 1.15 2025/01/12 10:33:18 wiz Exp $

DISTNAME=	zxing-cpp-3.0.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=nu-book/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/nu-book/zxing-cpp/
COMMENT=	1D/2D barcode reader/writer library in C++
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_CONFIGURE_ARGS+=	-DZXING_EXAMPLES=OFF
# enable old (deprecated in 3.0) API, for libreoffice
CMAKE_CONFIGURE_ARGS+=	-DZXING_WRITERS=BOTH
# use pkgsrc zint
CMAKE_CONFIGURE_ARGS+=	-DZXING_USE_BUNDLED_ZINT=OFF

# users of the library are fine with c++17 as of 3.0.1
USE_CXX_FEATURES+=	c++20

PKGCONFIG_OVERRIDE+=	core/zxing.pc.in

# Install private header file to fix build failure of misc/libreoffice-7.3.4.2.
#post-install:
#	${INSTALL_DATA} ${WRKSRC}/core/src/BitArray.h \
#		${DESTDIR}${PREFIX}/include/ZXing

.include "../../devel/cmake/build.mk"
.include "../../graphics/zint/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
