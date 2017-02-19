# $NetBSD: Makefile,v 1.16 2016/12/04 05:17:16 ryoon Exp $

DISTNAME=	qtquickcontrols-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtquickcontrols-${QTVERSION}
COMMENT=	Qt5 module for QuickControls

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../wip/qt5-qtbase58/Makefile.common"

.include "../../wip/qt5-qtdeclarative58/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
