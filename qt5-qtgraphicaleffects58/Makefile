# $NetBSD: Makefile,v 1.16 2016/12/04 05:17:46 ryoon Exp $

DISTNAME=	qtgraphicaleffects-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtgraphicaleffects-${QTVERSION}
COMMENT=	Qt5 module for Graphics effects

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../wip/qt5-qtbase58/Makefile.common"

.include "../../wip/qt5-qtdeclarative58/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
