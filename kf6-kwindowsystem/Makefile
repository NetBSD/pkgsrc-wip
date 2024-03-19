# $NetBSD: Makefile,v 1.68 2024/02/06 10:46:35 markd Exp $

DISTNAME=	kwindowsystem-${KF6VER}
PKGNAME=	kf6-${DISTNAME}
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Access to the windowing system
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

USE_TOOLS+=	pkg-config

#.include "../../mk/bsd.prefs.mk"

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../devel/qt6-qtwayland/buildlink3.mk"
#PLIST_VARS+=	mac x11
#.if ${OPSYS} == "Darwin"
#PLIST.mac=	yes
#.  include "../../x11/qt6-qtmacextras/buildlink3.mk"
#.else
#PLIST.x11=	yes
#.  include "../../x11/qt6-qtx11extras/buildlink3.mk"
#.endif
BUILDLINK_DEPMETHOD.qt6-qttools= build
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
