# $NetBSD: Makefile,v 1.8 2012/11/13 20:09:33 othyro Exp $
#

DISTNAME=	kgraphviewer-2.0.2-kde4.4.0
PKGNAME=	${DISTNAME:S/-kde/./}
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_KDE:=4.4.0/src/extragear/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://extragear.kde.org/
COMMENT=	GraphViz dot graph viewer for KDE4
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

USE_CMAKE=	yes
USE_TOOLS+=	msgfmt pkg-config


.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../mk/bsd.pkg.mk"
