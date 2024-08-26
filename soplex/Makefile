# $NetBSD$

DISTNAME=	soplex-7.1.0.0
CATEGORIES=	math
MASTER_SITES=	https://soplex.zib.de/download/release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://soplex.zib.de/download/release/
COMMENT=	Optimization package for solving linear programming problems (LPs)
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

CXXFLAGS+=	-fpermissive

.include "../../math/mpfr/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
