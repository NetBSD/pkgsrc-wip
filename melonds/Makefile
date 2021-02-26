# $NetBSD: Makefile,v 1.6 2020/08/18 17:57:46 leot Exp $

DISTNAME=	melonDS-0.9.1
PKGNAME=	${DISTNAME:S/DS/ds/}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=Arisotura/}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	http://melonds.kuribo64.net/
COMMENT=	Nintendo DS emulator, sorta
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

# C++17
GCC_REQD+=	7

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_ARGS+=	-DENABLE_LTO=OFF

# TODO: Make src/ARMJIT_Memory.cpp PaX MPROTECT safe.
NOT_PAX_MPROTECT_SAFE+=	bin/melonDS

.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../net/libslirp/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
