# $NetBSD$

DISTNAME=	gecode-6.2.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=Gecode/}
GITHUB_PROJECT=	gecode
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Gecode/gecode/
COMMENT=	Generic Constraint Development Environment
LICENSE=	mit

WRKSRC=		${WRKDIR}/gecode-release-6.2.0
USE_LANGUAGES=	c c++

# unused
CHECK_PORTABILITY_SKIP=	configure

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
