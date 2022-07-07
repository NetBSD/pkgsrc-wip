# $NetBSD$

DISTNAME=	v1.8
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=jcs/}
GITHUB_PROJECT=	xbanish
GITHUB_TAG=	v1.8
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	vms@retrobsd.ddns.net
HOMEPAGE=	https://github.com/jcs/xbanish/
COMMENT=	Hide cursor based on window activity
LICENSE=	isc

USE_TOOLS+=	pkg-config

MAKE_FLAGS+=	PREFIX=${PREFIX}

WRKSRC=	${WRKDIR}/${PKGNAME_NOREV}

.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
