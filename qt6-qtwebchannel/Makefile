# $NetBSD$

DISTNAME=	qtwebchannel-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtwebchannel-${QTVERSION}
COMMENT=	Qt6 webchannel module
CATEGORIES=	www
LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2 OR gnu-gpl-v3

.include "../../wip/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6WebChannel.pc

.include "../../wip/qt6-qtbase/buildlink3.mk"
.include "../../wip/qt6-qtdeclarative/buildlink3.mk"
.include "../../wip/qt6-qtwebsockets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
