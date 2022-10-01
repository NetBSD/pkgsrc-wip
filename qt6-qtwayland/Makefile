# $NetBSD$

DISTNAME=	qtwayland-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtwayland-${QTVERSION}
COMMENT=	Qt6 wayland
CATEGORIES=	x11
LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2 OR gnu-gpl-v3

.include "../../wip/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6WaylandClient.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6WaylandCompositor.pc

.include "../../devel/wayland/buildlink3.mk"
.include "../../wip/qt6-qtbase/buildlink3.mk"
.include "../../wip/qt6-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
