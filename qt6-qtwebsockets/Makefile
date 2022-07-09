# $NetBSD$

DISTNAME=	qtwebsockets-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtwebsockets-${QTVERSION}
COMMENT=	Qt6 module for websockets communication
CATEGORIES=	net
LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2 OR gnu-gpl-v3

.include "../../wip/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6WebSockets.pc

.include "../../wip/qt6-qtbase/buildlink3.mk"
.include "../../wip/qt6-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
