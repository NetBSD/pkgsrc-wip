# $NetBSD$

DISTNAME=	libqtxdg-3.4.0
CATEGORIES=	x11
MASTER_SITES=	https://downloads.lxqt.org/downloads/libqtxdg/3.4.0/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lxqt.org/
COMMENT=	Qt implementation of freedesktop.org xdg specs
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

INSTALLATION_DIRS+=	lib

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

DEPENDS+=	lxqt-build-tools-[0-9]*:../../wip/lxqt-build-tools

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
