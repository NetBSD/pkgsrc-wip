# $NetBSD$

DISTNAME=	yabar-0.4.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=geommer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/geommer/yabar/
COMMENT=	Modern and lightweight status bar for X window managers
LICENSE=	mit

USE_TOOLS+=	gmake

MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
# Package tries to run git to detect its version
MAKE_FLAGS+=	VERSION=${PKGVERSION_NOREV}

.include "../../devel/libconfig/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
