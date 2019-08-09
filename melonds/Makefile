# $NetBSD$

DISTNAME=	melonDS-0.8.2
PKGNAME=	${DISTNAME:S/DS/ds/}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=Arisotura/}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	http://melonds.kuribo64.net/
COMMENT=	Nintendo DS emulator, sorta
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++11

# C++11
GCC_REQD+=	4.8

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_ARGS+=	-DENABLE_LTO=OFF

.include "../../devel/SDL2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
