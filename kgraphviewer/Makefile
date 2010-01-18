# $NetBSD: Makefile,v 1.3 2010/01/18 09:38:26 thomasklausner Exp $
#

DISTNAME=	kgraphviewer-2.0.2-kde4.3.3
PKGNAME=	${DISTNAME:S/-kde/./}
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_KDE:=4.3.3/src/extragear/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://extragear.kde.org/
COMMENT=	GraphViz dot graph viewer for KDE4
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4

PKG_DESTDIR_SUPPORT=	user-destdir
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

USE_CMAKE=	yes
USE_TOOLS+=	msgfmt pkg-config

.include "../../graphics/graphviz/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../mk/bsd.pkg.mk"
