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

DEPENDS+=	R-Rcpp>=0.12.17:../../devel/R-Rcpp
DEPENDS+=	R-tibble>=1.4.2:../../math/R-tibble

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
