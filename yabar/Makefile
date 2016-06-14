# $NetBSD$

DISTNAME=	0.4.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=geommer/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/geommer/yabar/
COMMENT=	Modern and lightweight status bar for X window managers
LICENSE=	mit

GITHUB_PROJECT=	yabar

WRKSRC=	${WRKDIR}/yabar-0.4.0

USE_TOOLS+=	gmake

MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

.include "../../devel/libconfig/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
