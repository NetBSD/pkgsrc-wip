# $NetBSD$

DISTNAME=	lxqt-qtplugin-0.14.0
CATEGORIES=	x11
MASTER_SITES=	https://downloads.lxqt.org/downloads/lxqt-qtplugin/0.14.0/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lxqt.org/
COMMENT=	LxQt platform integration plugin for Qt5
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

INSTALLATION_DIRS+=	qt5

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

DEPENDS+=	lxqt-build-tools-[0-9]*:../../wip/lxqt-build-tools

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../devel/libdbusmenu-qt5/buildlink3.mk"
.include "../../wip/liblxqt/buildlink3.mk"
.include "../../wip/libfm-qt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
