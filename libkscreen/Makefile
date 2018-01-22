# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	libkscreen-${PLASMAVER}
CATEGORIES=	x11

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	KDE screen management software
LICENSE=	gnu-gpl-v2

.include "../../wip/kde5/plasma.mk"

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	src/kscreen2.pc.in

BUILDLINK_TRANSFORM+=	rm:-fvisibility=hidden

.include "../../wip/kwayland/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
#.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
