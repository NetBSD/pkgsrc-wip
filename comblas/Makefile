# $NetBSD$

DISTNAME=	CombBLAS_beta_16_2
PKGNAME=	comblas-16.2-beta
CATEGORIES=	math
MASTER_SITES=	http://eecs.berkeley.edu/~aydin/CombBLAS_FILES/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://people.eecs.berkeley.edu/~aydin/CombBLAS/html/
COMMENT=	Combinatorial BLAS library: an extensible parallel graph library
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

post-extract:
	cd ${WRKSRC}/include && ${RM} .DS_Store ._.DS_Store CombBLAS/._CombBLAS.h

.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
