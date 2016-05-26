# $NetBSD: Makefile,v 1.4 2015/05/30 02:01:35 krytarowski Exp $

.include "../../wip/liblxqt/Makefile.common"

DISTNAME=	pcmanfm-qt-0.9.0
CATEGORIES=	wip

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	file manager + desktop manager
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libfm-qt/libfm-qt.pc.in

.include "../../sysutils/menu-cache/buildlink3.mk"
.include "../../sysutils/libfm/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
