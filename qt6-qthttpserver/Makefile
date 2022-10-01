# $NetBSD$

DISTNAME=	qthttpserver-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qthttpserver-${QTVERSION}
COMMENT=	Qt6 classes for creating http servers
CATEGORIES=	www
LICENSE=	gnu-gpl-v3

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6HttpServer.pc

.include "../../wip/qt6-qtbase/Makefile.common"

.include "../../wip/qt6-qtbase/buildlink3.mk"
.include "../../wip/qt6-qtwebsockets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
