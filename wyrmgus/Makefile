# $NetBSD$

DISTNAME=	wyrmgus-5.3.5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=Andrettin/}
GITHUB_PROJECT=	Wyrmgus
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://andrettin.github.io/
COMMENT=	Game engine for Wyrmsun
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

CMAKE_CONFIGURE_ARGS+=	-DENABLE_TOUCHSCREEN=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_METASERVER=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_DOC=OFF

# C++20
GCC_REQD+=	9.3

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtlocation/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../wip/tolua++/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
