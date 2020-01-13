# $NetBSD$

DISTNAME=	lxqt-config-0.14.1
CATEGORIES=	x11
MASTER_SITES=	https://downloads.lxqt.org/downloads/lxqt-config/0.14.1/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	System configuration (control center)
HOMEPAGE=	https://downloads.lxqt.org/
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

INSTALLATION_DIRS+=	bin lib

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	lxqt-build-tools-[0-9]*:../../wip/lxqt-build-tools
DEPENDS+=	lxqt-themes-[0-9]*:../../wip/lxqt-themes

post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/etc/xdg/menus/lxqt-config.menu

.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/liblxqt/buildlink3.mk"
.include "../../wip/libkscreen/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
