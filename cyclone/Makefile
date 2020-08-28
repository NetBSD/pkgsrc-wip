# $NetBSD$

GITHUB_PROJECT=	cyclone-bootstrap
GITHUB_TAG=	v0.20
DISTNAME=	${GITHUB_TAG}
PKGNAME=	cyclone-${DISTNAME:S,^v,,}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=justinethier/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://justinethier.github.io/cyclone/
COMMENT=	Scheme-to-C compiler
LICENSE=	mit

WRKSRC=		${WRKDIR}/cyclone-bootstrap-${DISTNAME:S,^v,,}
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	third-party/libtommath-1.2.0/libtommath.pc.in

.include "../../devel/concurrencykit/buildlink3.mk"
.include "../../math/ltm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
