# $NetBSD: Makefile,v 1.19 2020/01/21 20:25:36 adam Exp $

DISTNAME=	qt6-${QTVERSION}

COMMENT=	"meta-package" for version 6 of the QT GUI C++ toolkit

CATEGORIES=	meta-pkgs

META_PACKAGE=	yes

.include "Makefile.common"

DEPENDS+=	qt6-qtbase-${QTVERSION}{,nb[0-9]*}:../../wip/qt6-qtbase
DEPENDS+=	qt6-odbc-${QTVERSION}{,nb[0-9]*}:../../wip/qt6-odbc
DEPENDS+=	qt6-psql-${QTVERSION}{,nb[0-9]*}:../../wip/qt6-psql
DEPENDS+=	qt6-qtdeclarative-${QTVERSION}{,nb[0-9]*}:../../wip/qt6-qtdeclarative
DEPENDS+=	qt6-qtimageformats-${QTVERSION}{,nb[0-9]*}:../../wip/qt6-qtimageformats
DEPENDS+=	qt6-qtnetworkauth-${QTVERSION}{,nb[0-9]*}:../../wip/qt6-qtnetworkauth
DEPENDS+=	qt6-qtquick3d-${QTVERSION}{,nb[0-9]*}:../../wip/qt6-qtquick3d
DEPENDS+=	qt6-qtquickcontrols2-${QTVERSION}{,nb[0-9]*}:../../wip/qt6-qtquickcontrols2
DEPENDS+=	qt6-qtquicktimeline-${QTVERSION}{,nb[0-9]*}:../../wip/qt6-qtquicktimeline
DEPENDS+=	qt6-qtshadertools-${QTVERSION}{,nb[0-9]*}:../../wip/qt6-qtshadertools
DEPENDS+=	qt6-qtsvg-${QTVERSION}{,nb[0-9]*}:../../wip/qt6-qtsvg
DEPENDS+=	qt6-qttools-${QTVERSION}{,nb[0-9]*}:../../wip/qt6-qttools
DEPENDS+=	qt6-qtwayland-${QTVERSION}{,nb[0-9]*}:../../wip/qt6-qtwayland
DEPENDS+=	qt6-qt3d-${QTVERSION}{,nb[0-9]*}:../../wip/qt6-qt3d
DEPENDS+=	qt6-qt5compat-${QTVERSION}{,nb[0-9]*}:../../wip/qt6-qt5compat

.include "../../mk/bsd.pkg.mk"
