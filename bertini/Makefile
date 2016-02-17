# $NetBSD$

DISTNAME=	BertiniSource_v1.5
PKGNAME=	bertini-1.5
CATEGORIES=	math
MASTER_SITES=	http://bertini.nd.edu/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://bertini.nd.edu/
COMMENT=	Software for Numerical Algebraic Geometry
LICENSE=	modified-bsd

MAKE_JOBS_SAFE=	NO

GNU_CONFIGURE=	yes
USE_TOOLS+=	bison flex

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
