# $NetBSD$

DISTNAME=	xbanish-1.8
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=jcs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	vms@retrobsd.ddns.net
HOMEPAGE=	https://github.com/jcs/xbanish/
COMMENT=	Hide cursor based on window activity
LICENSE=	isc

USE_TOOLS+=	pkg-config

MAKE_FLAGS+=	PREFIX=${PREFIX}

.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
