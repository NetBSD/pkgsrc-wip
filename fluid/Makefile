# $NetBSD$

DISTNAME=	fluid-1.2.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=lirios/fluid/releases/download/v1.2.0/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://liri.io/
COMMENT=	Collection of QtQuick components for building fluid
LICENSE=	mpl-2.0

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CMAKE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}
CMAKE_ARGS+=	-DMSK_PREFIX=${PREFIX:Q}
CMAKE_ARGS+=	-DMSK_INSTALL_PREFIX=${PREFIX:Q}
CMAKE_ARGS+=	-DMSK_INSTALL_LIBS=/lib
CMAKE_ARGS+=	-DMSK_INSTALL_INCLUDES=/include
CMAKE_ARGS+=	-DMSK_INSTALL_DOCS=/share/doc/fluid
#CMAKE_ARGS+=	-DFLUID_USE_SYSTEM_LCS:BOOL=ON
#CMAKE_ARGS+=	-DFLUID_WITH_DOCUMENTATION:BOOL=OFF
CMAKE_ARGS+=	-DFLUID_WITH_DEMO:BOOL=OFF
#CMAKE_ARGS+=	-DFLUID_WITH_QML_MODULES:BOOL=OFF
CMAKE_ARGS+=	-DFLUID_INSTALL_ICONS:BOOL=OFF

ICON_THEME=	yes

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

DEPENDS+=	qt5-qtgraphicaleffects-[0-9]*:../../x11/qt5-qtgraphicaleffects
DEPENDS+=	qt5-qtdoc-[0-9]*:../../x11/qt5-qtdoc

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtquickcontrols2/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtwayland/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
