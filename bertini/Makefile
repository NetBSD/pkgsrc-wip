# $NetBSD: Makefile,v 1.1 2015/08/14 23:43:38 jihbed Exp $

DISTNAME=	BertiniSource_v1.4
PKGNAME=	bertini-1.4
CATEGORIES=	math
MASTER_SITES=	http://www3.nd.edu/~sommese/bertini/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www3.nd.edu/~sommese/bertini/
COMMENT=	Software for Numerical Algebraic Geometry
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=	${WRKDIR}/${DISTNAME}/src

MAKE_JOBS_SAFE=	NO

USE_TOOLS+=	bison flex

INSTALLATION_DIRS=	 bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bertini ${DESTDIR}${PREFIX}/bin

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
