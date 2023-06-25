# $NetBSD$

DISTNAME=	0.4.4
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=baskerville/}
GITHUB_PROJECT=	xtitle
GITHUB_TAG=	refs/tags/0.4.4
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	bsdprg@tuta.io
HOMEPAGE=	https://github.com/baskerville/xtitle/
COMMENT=	Outputs title of the active window
LICENSE=	unlicense

WRKSRC=	${WRKDIR}/xtitle-0.4.4

.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
