# $NetBSD: Makefile,v 1.19 2020/01/21 20:25:36 adam Exp $

DISTNAME=	qt6-${QTVERSION}

COMMENT=	"meta-package" for version 6 of the QT GUI C++ toolkit

META_PACKAGE=	yes

.include "Makefile.common"

DEPENDS+=	qt6-qtbase-${QTVERSION}{,nb[0-9]*}:../../wip/qt6-qtbase

.include "../../mk/bsd.pkg.mk"
