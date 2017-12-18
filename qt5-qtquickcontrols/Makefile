# $NetBSD$

DISTNAME=	qtquickcontrols-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtquickcontrols-${QTVERSION}
COMMENT=	Qt5 module for QuickControls

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../wip/qt5-qtbase/Makefile.common"

.include "../../wip/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
