# $NetBSD: Makefile,v 1.27 2017/04/22 21:04:05 adam Exp $

DISTNAME=	qtdoc-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtdoc-${QTVERSION}
COMMENT=	Qt5 documentations

MAKE_ENV+=		QTDIR=${QTDIR}

BUILD_TARGET=		docs
INSTALL_TARGET=		install_docs

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../wip/qt5-qtbase/Makefile.common"

.include "../../wip/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
