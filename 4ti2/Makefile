# $NetBSD$

GITHUB_PROJECT=	4ti2
DISTNAME=	4ti2-1.6.9
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=4ti2/}
GITHUB_RELEASE=	Release_1_6_9

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://4ti2.github.io/
COMMENT=	Solve algebraic, geometric, combinatorial problems on linear spaces
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++ fortran

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/glpk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
