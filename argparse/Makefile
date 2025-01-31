# $NetBSD$

DISTNAME=	argparse-3.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=p-ranav/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/p-ranav/argparse/
COMMENT=	Argument Parser for Modern C++
LICENSE=	mit

USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++17

PKGCONFIG_OVERRIDE+=	packaging/pkgconfig.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
