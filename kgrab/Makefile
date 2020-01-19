# $NetBSD: Makefile,v 1.7 2012/11/13 20:09:32 othyro Exp $
#

DISTNAME=	kgrab-0.1.1-kde4.4.0
PKGNAME=	${DISTNAME:S/-kde/./}
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_KDE:=4.4.0/src/extragear/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://extragear.kde.org/
COMMENT=	Screen Grabbing Program (KDE4)
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

USE_CMAKE=	yes
USE_TOOLS+=	msgfmt


.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../mk/bsd.pkg.mk"
