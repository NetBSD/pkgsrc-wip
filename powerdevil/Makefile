# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	powerdevil-${PLASMAVER}
CATEGORIES=	x11

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	Manages the power consumption settings of a Plasma Shell
LICENSE=	gnu-lgpl-v2

.include "../../wip/kde5/plasma.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

CMAKE_ARGS+=	-DKAUTH_DBUS_DIR=${PREFIX}/share/examples/powerdevil

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/autostart/powerdevil.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/powerdevil.desktop
CONF_FILES+=	${PREFIX}/share/examples/powerdevil/org.kde.powerdevil.backlighthelper.conf \
		${PKG_SYSCONFDIR}/dbus-1/system.d/org.kde.powerdevil.backlighthelper.conf
CONF_FILES+=	${PREFIX}/share/examples/powerdevil/org.kde.powerdevil.discretegpuhelper.conf \
		${PKG_SYSCONFDIR}/dbus-1/system.d/org.kde.powerdevil.discretegpuhelper.conf

MAKE_DIRS+=		${PKG_SYSCONFDIR}/dbus-1/system.d
INSTALLATION_DIRS+=	share/examples/powerdevil

.include "../../devel/kidletime/buildlink3.mk"
.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../wip/libkscreen/buildlink3.mk"
.include "../../wip/plasma-workspace/buildlink3.mk"
.include "../../x11/kactivities5/buildlink3.mk"
.include "../../x11/kdelibs4support/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
