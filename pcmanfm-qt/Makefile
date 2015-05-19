# $NetBSD: Makefile,v 1.2 2015/05/19 23:02:58 krytarowski Exp $

DISTNAME=	pcmanfm-qt-0.9.0
CATEGORIES=	wip
MASTER_SITES=	http://downloads.lxqt.org/lxqt/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxqt.org/
COMMENT=	file manager + desktop manager
LICENSE=	gnu-lgpl-v2.1

EXTRACT_USING=	gtar

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libfm-qt/libfm-qt.pc.in

.include "../../sysutils/menu-cache/buildlink3.mk"
.include "../../wip/libfm/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
