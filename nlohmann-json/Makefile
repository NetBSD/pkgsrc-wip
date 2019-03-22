# $NetBSD$

GITHUB_PROJECT=	json
DISTNAME=	v3.6.1
PKGNAME=	nlohmann-${GITHUB_PROJECT}-${DISTNAME:S/v//}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=nlohmann/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://nlohmann.github.io/json/
COMMENT=	JSON library for Modern C++
LICENSE=	mit

WRKSRC=		${WRKDIR}/json-3.6.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	benchmarks/thirdparty/benchmark/cmake/benchmark.pc.in

.include "../../mk/bsd.pkg.mk"
