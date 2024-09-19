# $NetBSD$

DISTNAME=	newt-r${PKGVERSION_NOREV:S/./-/g}
PKGNAME=	newt-0.52.21
CATEGORIES=	devel
MASTER_SITES=	https://pagure.io/newt/archive/r${PKGVERSION_NOREV:S/./-/g}/

MAINTAINER=	tpaul@NetBSD.org
HOMEPAGE=	https://pagure.io/newt
COMMENT=	Programming library for color text mode user interaces
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	automake gmake

pre-configure:
	cd ${WRKSRC} && sh ./autogen.sh

.include "../../devel/libslang2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
