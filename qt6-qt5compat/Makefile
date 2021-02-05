# $NetBSD$

DISTNAME=	qt5compat-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qt5compat-${QTVERSION}
COMMENT=	Qt6 module for qt5 portability
CATEGORIES=	x11

CONFIGURE_ARGS+=-cmake-use-default-generator
CONFIGURE_ARGS+=-- -DCMAKE_SKIP_RPATH:BOOL=TRUE

.include "../../wip/qt6-qtbase/Makefile.common"

.include "../../wip/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
