# $NetBSD: Makefile,v 1.9 2014/09/08 21:24:08 thomasklausner Exp $
#

DISTNAME=	kuickshow-0.9.1-kde4.4.0
PKGNAME=	${DISTNAME:S/-kde/./}
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_KDE:=extragear/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://extragear.kde.org/
COMMENT=	Very fast and comfortable imageviewer (KDE4)
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

USE_CMAKE=	yes
USE_TOOLS+=	msgfmt pkg-config

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../mk/bsd.pkg.mk"
