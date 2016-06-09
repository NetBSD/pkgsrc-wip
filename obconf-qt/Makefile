# $NetBSD: Makefile,v 1.3 2015/05/30 01:49:34 krytarowski Exp $

.include "../../wip/liblxqt/Makefile.common"

DISTNAME=	obconf-qt-0.1.0
CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxde/obconf-qt/
COMMENT=	Qt based configurator of OpenBox window manager
LICENSE=	gnu-gpl-v2

USE_TOOLS=	pkg-config

# pkgsrc does not support qt4 variant
CONFIGURE_ENV=	USE_QT5=ON

.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../wm/openbox/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
