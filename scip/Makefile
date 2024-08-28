# $NetBSD$

DISTNAME=	scip-9.1.0
CATEGORIES=	math
MASTER_SITES=	https://www.scipopt.org/download.php?fname=scip-9.1.0.tgz
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.scipopt.org/
COMMENT=	Solver for mixed integer, mixed integer nonlinear programming
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

GCC_REQD+=		12

CMAKE_CONFIGURE_ARGS+=	-DPAPILO=off -DZIMPL=off

CXXFLAGS+=	-fpermissive

.include "../../wip/soplex/buildlink3.mk"
.include "../../math/ipopt/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
