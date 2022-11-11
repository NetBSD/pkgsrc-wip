# $NetBSD$

GITHUB_PROJECT=	cddlib
DISTNAME=	cddlib-0.94m
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=cddlib/}
GITHUB_RELEASE=	0.94m

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/cddlib/cddlib
COMMENT=	C-library implementation of the Double Description Method
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	cddlib.pc.in

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
