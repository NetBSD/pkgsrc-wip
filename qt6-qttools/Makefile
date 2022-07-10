# $NetBSD$

DISTNAME=	qttools-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qttools-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt6 tools
CATEGORIES=	x11
LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2 OR gnu-gpl-v3

.include "../../wip/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Designer.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Help.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6UiTools.pc

.include "../../lang/clang/buildlink3.mk"
.include "../../wip/litehtml/buildlink3.mk"
.include "../../wip/qt6-qtbase/buildlink3.mk"
.include "../../wip/qt6-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
