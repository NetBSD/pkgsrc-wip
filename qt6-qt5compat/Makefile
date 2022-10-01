# $NetBSD$

DISTNAME=	qt5compat-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qt5compat-${QTVERSION}
COMMENT=	Qt6 module for Qt5 portability
CATEGORIES=	x11

LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2 OR gnu-gpl-v3

.include "../../wip/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Core5Compat.pc

.include "../../wip/qt6-qtbase/buildlink3.mk"
.include "../../wip/qt6-qtdeclarative/buildlink3.mk"
.include "../../wip/qt6-qtshadertools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
