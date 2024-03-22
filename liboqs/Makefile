# $NetBSD$

GITHUB_PROJECT=	liboqs
GITHUB_TAG=	refs/tags/0.9.2
DISTNAME=	0.9.2
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=open-quantum-safe/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	logan@cyberstorm.mu
HOMEPAGE=	https://github.com/open-quantum-safe/liboqs/
COMMENT=	Post quantum crypto library
LICENSE=	mit

WRKSRC=		${WRKDIR}/liboqs-0.9.2
#USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	src/liboqs.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
