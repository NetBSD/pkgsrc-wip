# $NetBSD$

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/quantreg/
COMMENT=	Quantile Regression
LICENSE=	gnu-gpl-v2

R_PKGNAME=	quantreg
R_PKGVER=	5.36

DEPENDS+=	R-SparseM>=1.77:../../math/R-SparseM
DEPENDS+=	R-MatrixModels>=0.4:../../math/R-MatrixModels

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
