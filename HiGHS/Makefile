# $NetBSD$

GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}
DISTNAME=	HiGHS-1.7.2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=ERGO-Code/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ERGO-Code/HiGHS/
COMMENT=	Solver for large scale sparse linear programming (LP) problems
LICENSE=	mit

USE_TOOLS+=	cmake
USE_LANGUAGES=	c c++

CXXFLAGS+=	-fpermissive

GCC_REQD+=	10

PKGCONFIG_OVERRIDE+=	highs.pc.in

WRKSRC=		${WRKDIR}/${DISTNAME}

.include "../../devel/cmake/build.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
