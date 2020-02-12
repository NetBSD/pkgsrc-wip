# $NetBSD$

DISTNAME=	lxqt-config-0.14.1
CATEGORIES=	x11
MASTER_SITES=	https://downloads.lxqt.org/downloads/lxqt-config/0.14.1/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	voidpin@protonmail.com
COMMENT=	System configuration (control center)
HOMEPAGE=	https://downloads.lxqt.org/
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CMAKE_ARGS+=	-DWITH_INPUT=OFF

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/lxqt-config \
		-L${PREFIX}/lib/lxqt-config/

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	lxqt-build-tools-[0-9]*:../../wip/lxqt-build-tools
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools
DEPENDS+=	lxqt-themes-[0-9]*:../../wip/lxqt-themes

.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/liblxqt/buildlink3.mk"
.include "../../wip/libkscreen/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
