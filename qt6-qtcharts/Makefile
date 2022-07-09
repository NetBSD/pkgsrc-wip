# $NetBSD$

DISTNAME=	qtcharts-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtcharts-${QTVERSION}
COMMENT=	Qt6 module with charts controls
CATEGORIES=	x11

LICENSE=	gnu-gpl-v3

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Charts.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6ChartsQml.pc

.include "../../wip/qt6-qtbase/Makefile.common"

.include "../../wip/qt6-qtbase/buildlink3.mk"
.include "../../wip/qt6-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
