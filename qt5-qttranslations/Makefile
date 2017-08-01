# $NetBSD: Makefile,v 1.27 2017/04/22 21:04:05 adam Exp $

DISTNAME=	qttranslations-opensource-src-${QTVERSION}
PKGNAME=	qt5-qttranslations-${QTVERSION}
COMMENT=	Qt5 translations

MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../wip/qt5-qtbase/Makefile.common"

.include "../../wip/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
