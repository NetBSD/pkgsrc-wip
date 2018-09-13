# $NetBSD$

BUILD_DIRS=	gb.qt5
GB_DEPENDS=	gambas3-gb-image
.include "../../wip/gambas3/Makefile.common"

PKGNAME=	gambas3-gb-qt5-${GB_VERSION}
MAINTAINER=	bastiangermann@fishpost.de
COMMENT=	Qt5 toolkit implementation for Gambas

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
