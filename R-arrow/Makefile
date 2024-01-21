# $NetBSD$

R_PKGNAME=	arrow
R_PKGVER=	14.0.0.2
CATEGORIES=	wip

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Integration to 'Apache' 'Arrow'
LICENSE=	Apache License (>= 2.0)

DEPENDS+=	R-assertthat>=0.2.1:../../devel/R-assertthat
DEPENDS+=	R-bit64>=0.9.7:../../devel/R-bit64
DEPENDS+=	R-glue>=1.7.0:../../devel/R-glue
DEPENDS+=	R-purrr>=1.0.1:../../devel/R-purrr
DEPENDS+=	R-rlang>=1.0.0:../../devel/R-rlang
DEPENDS+=	R-tidyselect>=1.0.0:../../devel/R-tidyselect
DEPENDS+=	R-vctrs>=0.6.3:../../math/R-vctrs

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
