# $NetBSD: Makefile,v 1.12 2012/11/28 21:43:05 outpaddling Exp $

DISTNAME=	SuiteSparse-7.7.0
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=DrTimothyAldenDavis/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cise.ufl.edu/research/sparse/SuiteSparse/
COMMENT=	Set of packages for sparse matrices calculation
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

USE_LANGUAGES=	c c++ fortran77

WRKSRC=		${WRKDIR}/${DISTNAME}

.include "../../devel/cmake/build.mk"
.include "../../mk/blas.buildlink3.mk"
.include "../../math/metis/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/openblas/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
# reported at: https://github.com/DrTimothyAldenDavis/SuiteSparse/issues/837
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../parallel/openmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
