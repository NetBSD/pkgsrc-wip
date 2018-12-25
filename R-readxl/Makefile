# $NetBSD$

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/readxl/
COMMENT=	Read excel files into R tables
LICENSE=	gnu-gpl-v3

R_PKGNAME=	readxl
R_PKGVER=	1.2.0

USE_LANGUAGES+=	c c++

DEPENDS+=	R-cellranger>=1.1.0:../../wip/R-cellranger
DEPENDS+=	R-tibble>=1.3.1:../../math/R-tibble	# XXX - found R-tibble-1.4.2 (../../math/R-tibble)

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../wip/R-progress/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
