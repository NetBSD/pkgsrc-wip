# $NetBSD$

DISTNAME=	inflatelib-0.3.0
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=microsoft/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/microsoft/inflatelib/
COMMENT=	Deflate/Deflate64 decompression library written in C
LICENSE=	mit

#WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c c++

#CMAKE_CONFIGURE_ARGS+=	-DINFLATELIB_TEST=OFF

# upstream uses a vcpkg-specific header file
# https://github.com/microsoft/inflatelib/issues/34
pre-build:
	echo '#include <catch2/catch_all.hpp>' > ${BUILDLINK_DIR}/include/catch.hpp

.include "../../devel/cmake/build.mk"
.include "../../devel/catch2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
