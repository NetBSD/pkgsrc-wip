# $NetBSD$

DISTNAME=	onetbb-2021.5.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=oneapi-src/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://oneapi-src.github.io/oneTBB/
COMMENT=	oneAPI Threading Building Blocks
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/oneTBB-${PKGVERSION_NOREV}

USE_LANGUAGES+=	c c++

USE_CMAKE=	yes

CMAKE_ARGS+=	-DTBB_EXAMPLES:BOOL=OFF
CMAKE_ARGS+=	-DTBB_TEST:BOOL=OFF

.include "../../mk/bsd.pkg.mk"
