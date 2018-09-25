# $NetBSD$

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://cran.r-project.org/web/packages/gmp/
COMMENT=	Import excel files into R
LICENSE=	gnu-gpl-v2

R_PKGNAME=	readxl
R_PKGVER=	1.1.0

USE_LANGUAGES=	c c++

DEPENDS+=	R-tibble>=1.4.2:../../math/R-tibble
DEPENDS+=	R-cellranger>=1.1.0:../../wip/R-cellranger

.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
