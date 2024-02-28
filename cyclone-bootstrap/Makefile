# $NetBSD$

DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=justinethier/}
GITHUB_PROJECT=	cyclone-bootstrap
GITHUB_TAG=	v0.36.0
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	yhardy@NetBSD.org
HOMEPAGE=	https://justinethier.github.io/cyclone-bootstrap/
COMMENT=	Bootstrap for the Cyclone scheme-to-C compiler
LICENSE=	mit

WRKSRC=		${WRKDIR}/cyclone-bootstrap-${DISTNAME:S,^v,,}
USE_TOOLS+=	gmake pkg-config
MAKE_FLAGS+=	COMP_INCDIRS="-I${PREFIX}/include/cyclone-bootstrap -I${PREFIX}/include"
MAKE_FLAGS+=	DATADIR=${PREFIX}/share/cyclone-bootstrap
MAKE_FLAGS+=	INCDIR=${PREFIX}/include/cyclone-bootstrap/cyclone
MAKE_FLAGS+=	LIBDIR=${PREFIX}/lib/cyclone-bootstrap
MAKE_FLAGS+=	PKGSRC_INCDIR=${PREFIX}/include
MAKE_FLAGS+=	PKGSRC_LIBDIR=${PREFIX}/lib
TEST_TARGET=	test

PKGCONFIG_OVERRIDE+=	third-party/libtommath-1.2.0/libtommath.pc.in

.include "../../devel/concurrencykit/buildlink3.mk"
.include "../../math/ltm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
