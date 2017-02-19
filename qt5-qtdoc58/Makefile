# $NetBSD: Makefile,v 1.23 2017/01/21 20:06:55 ryoon Exp $

DISTNAME=	qtdoc-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtdoc-${QTVERSION}
COMMENT=	Qt5 documentations

MAKE_ENV+=		QTDIR=${QTDIR}

BUILD_TARGET=		docs
INSTALL_TARGET=		install_docs

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../wip/qt5-qtbase58/Makefile.common"

.include "../../wip/qt5-qttools58/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
