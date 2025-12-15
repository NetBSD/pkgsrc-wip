# $NetBSD$

DISTNAME=	cppsimpleuri-2.2.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=salzaverde/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/salzaverde/cppsimpleuri/
COMMENT=	C++ uri & query parser
LICENSE=	mit

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c c++
USE_TOOLS=	pax

CMAKE_CONFIGURE_ARGS+=	-DSIMPLEURI_LIB_BUILD_TESTS=OFF

INSTALL_TARGET=	preinstall

INSTALLATION_DIRS+=	include lib

do-install:
	cd ${WRKSRC}/include && ${PAX} -rw * ${DESTDIR}${PREFIX}/include
	cd ${WRKSRC}/${CMAKE_BUILD_DIR} && ${PAX} -rw libcppsimpleuri.a ${DESTDIR}${PREFIX}/lib

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
