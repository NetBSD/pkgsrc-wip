# $NetBSD$

VERSION=	5.6.0
GITHUB_PROJECT=	cinnamon-menus
GITHUB_TAG=	refs/tags/master.lmde5
DISTNAME=	master.lmde5
PKGNAME=	${GITHUB_PROJECT}-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=linuxmint/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/linuxmint/cinnamon-menus
COMMENT=	Additional UI API for cinnamon
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

WRKSRC=	${WRKDIR}/cinnamon-menus-master.lmde5

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
