# $NetBSD$

VERSION=	1.1.4
DISTNAME=	${VERSION}
PKGNAME=	ZMusic-${VERSION}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=coelckers/}
GITHUB_TAG=	${DISTNAME}
DIST_SUBDIR=	ZMusic

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://github.com/coelckers/ZMusic/
COMMENT=	GZDoom's music system as a standalone library
LICENSE=	gnu-gpl-v3

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
USE_CMAKE=	yes
#CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Debug
CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

pre-configure:
	cd ${WRKSRC}; mkdir build

BUILDLINK_API_DEPENDS.zlib+=		zlib>=1.2.3
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
