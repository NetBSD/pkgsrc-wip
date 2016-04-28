# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kactivities-stats-${KF5VER}
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Core components for the KDE's Activities
LICENSE=	gnu-lgpl-v2 AND gnu-lgpl-v2.1 AND gnu-lgpl-v3

.include "../../wip/kf5/Makefile.common"

PKGCONFIG_OVERRIDE+=	src/libKActivitiesStats.pc.cmake

.include "../../wip/kactivities5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
