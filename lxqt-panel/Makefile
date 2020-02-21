# $NetBSD$

DISTNAME=	lxqt-panel-0.14.1
CATEGORIES=	x11
MASTER_SITES=	https://downloads.lxqt.org/downloads/lxqt-panel/0.14.1/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lxqt.org/
COMMENT=	Desktop panel
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
CMAKE_ARGS+=	-DCPULOAD_PLUGIN=No
CMAKE_ARGS+=	-DKBINDICATOR_PLUGIN=No
CMAKE_ARGS+=	-DMOUNT_PLUGIN=No
CMAKE_ARGS+=	-DSENSORS_PLUGIN=No
CMAKE_ARGS+=	-DNETWORKMONITOR_PLUGIN=No
CMAKE_ARGS+=	-DSYSSTAT_PLUGIN=No
CMAKE_ARGS+=	-DVOLUME_USE_ALSA=No
.endif

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	lxqt-build-tools-[0-9]*:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools
DEPENDS+=	lxmenu-data-[0-9]*:../../sysutils/lxmenu-data

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../devel/libdbusmenu-qt5/buildlink3.mk"
.include "../../wip/lxqt-globalkeys/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../sysutils/solid/buildlink3.mk"
.include "../../x11/kwindowsystem/buildlink3.mk"
.include "../../x11/kguiaddons/buildlink3.mk"
.include "../../sysutils/menu-cache/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
