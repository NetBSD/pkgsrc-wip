# $NetBSD$

DISTNAME=	xorgxrdp-0.2.0
CATEGORIES=	wip x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=neutrinolabs/}
GITHUB_RELEASE=	v0.2.0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/neutrinolabs/xorgxrdp/
COMMENT=	X.org modules for RDP server
LICENSE=	x11

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	pkg-config

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
