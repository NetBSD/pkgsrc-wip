# $NetBSD: Makefile,v 1.1 2013/09/02 21:05:56 jihbed Exp $

DISTNAME=	getdp-2.4.1-source
PKGNAME=	getdp-2.4.1
CATEGORIES=	math
MASTER_SITES=	http://www.geuz.org/getdp/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.geuz.org/getdp/src/
COMMENT=	General environment for the treatment of discrete problems
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++ fortran

SUBST_CLASSES+=		setup
SUBST_STAGE.setup=	pre-configure
SUBST_MESSAGE.setup=	Fixing ${PYSETUP}
SUBST_FILES.setup=	CMakeLists.txt
SUBST_SED.setup+=	-e 's,share/man/,${PKGMANDIR}/,g'

.include "../../math/blas/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
