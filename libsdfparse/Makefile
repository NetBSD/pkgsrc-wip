# $NetBSD$

DISTNAME=	libsdfparse-0.0.0.44
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	cad devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=kmurray/}
GITHUB_PROJECT=	libsdfparse
GITHUB_TAG=	97218ddf4c4a30479838844440c28c99d6265862
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kmurray/libsdfparse/
COMMENT=	Simple C++ SDF (Standard Delay Format) parser
LICENSE=	mit

WRKSRC=		${WRKDIR}/libsdfparse-97218ddf4c4a30479838844440c28c99d6265862
USE_LANGUAGES=	c c++

INSTALL_HEADERS=	sdf_data.hpp sdf_data_fwd.hpp sdf_loader.hpp sdfparse.hpp

INSTALLATION_DIRS=	lib include bin
INSTALL_TARGET=		preinstall

post-install:
	${INSTALL_DATA} ${INSTALL_HEADERS:S,^,${WRKSRC}/src/libsdfparse/,} ${DESTDIR}${PREFIX}/include; \
	${INSTALL_LIB} ${WRKSRC}/${CMAKE_BUILD_DIR}/src/libsdfparse.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/${CMAKE_BUILD_DIR}/src/sdfparse_demo ${DESTDIR}${PREFIX}/bin

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
