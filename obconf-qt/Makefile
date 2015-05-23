# $NetBSD: Makefile,v 1.1 2015/05/23 00:57:50 krytarowski Exp $

DISTNAME=	obconf-qt-0.1.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxde/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=lxde/obconf-qt/}
COMMENT=	Qt based configurator of OpenBox window manager
LICENSE=	gnu-lgpl-v2.1 # next version (after 0.1.0) switched to gnu-gpl-v2

WRKSRC=		${WRKDIR}/obconf-qt-0.1.0
USE_TOOLS=	pkg-config
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ENV=	USE_QT5=ON

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../wm/openbox/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
