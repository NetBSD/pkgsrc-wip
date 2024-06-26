# $NetBSD: Makefile,v 1.47 2024/05/29 16:35:07 adam Exp $

DISTNAME=	lxqt-panel-2.0.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-panel/
COMMENT=	Desktop panel
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++

# Requires libsensors, unavailable in pkgsrc
CMAKE_ARGS+=	-DSENSORS_PLUGIN=No

# Requires sysstat-qt6, unavailable in pkgsrc
CMAKE_ARGS+=	-DSYSSTAT_PLUGIN=No

# Appear non-functional on NetBSD currently.
CMAKE_ARGS+=	-DCPULOAD_PLUGIN=No
CMAKE_ARGS+=	-DMOUNT_PLUGIN=No

AUTOSTART_CONF=		share/examples/autostart
PANEL_CONF=		share/examples/lxqt
PKG_SYSCONFSUBDIR=	xdg
MAKE_DIRS+=		${PKG_SYSCONFDIR}/autostart
MAKE_DIRS+=		${PKG_SYSCONFDIR}/lxqt

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	plugin-directorymenu/directorymenuconfiguration.cpp
SUBST_FILES.prefix+=	plugin-mainmenu/lxqtmainmenuconfiguration.cpp
SUBST_FILES.prefix+=	plugin-kbindicator/src/x11/kbdlayout.cpp
SUBST_SED.prefix=	-e 's,/etc/xdg,${PKG_SYSCONFDIR},g'
SUBST_SED.prefix+=	-e 's,/usr/bin,${PREFIX}/bin,g'
SUBST_SED.prefix+=	-e 's,/usr/share,${PREFIX}/share,g'

CONF_FILES+=	${AUTOSTART_CONF}/lxqt-panel.desktop \
		${PKG_SYSCONFDIR}/autostart/lxqt-panel.desktop
CONF_FILES+=	${PANEL_CONF}/panel.conf \
		${PKG_SYSCONFDIR}/lxqt/panel.conf

DEPENDS+=	lxqt-menu-data-[0-9]*:../../wip/lxqt-menu-data
TOOL_DEPENDS+=	lxqt-build-tools>=2.0.0:../../wip/lxqt2-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "options.mk"
.include "../../wip/libdbusmenu-lxqt/buildlink3.mk"
.include "../../devel/libstatgrab/buildlink3.mk"
.include "../../sysutils/menu-cache/buildlink3.mk"
.include "../../sysutils/kf6-solid/buildlink3.mk"
.include "../../x11/kf6-kwindowsystem/buildlink3.mk"
.include "../../x11/kf6-kguiaddons/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../wip/lxqt-globalkeys/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../wip/layer-shell-qt6/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
