# $NetBSD$

DISTNAME=	qtscxml-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtscxml-${QTVERSION}
COMMENT=	Qt6 module for scxml support
CATEGORIES=	devel
LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v3

.include "../../wip/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Scxml.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6ScxmlQml.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6StateMachine.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6StateMachineQml.pc

.include "../../wip/qt6-qtbase/buildlink3.mk"
.include "../../wip/qt6-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
