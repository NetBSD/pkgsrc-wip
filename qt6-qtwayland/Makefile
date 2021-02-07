# $NetBSD$

DISTNAME=	qtwayland-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtwayland-${QTVERSION}
COMMENT=	Qt6 wayland
CATEGORIES=	x11

.include "../../wip/qt6-qtbase/Makefile.common"

.include "../../devel/wayland/buildlink3.mk"
.include "../../wip/qt6-qtbase/buildlink3.mk"
.include "../../wip/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
