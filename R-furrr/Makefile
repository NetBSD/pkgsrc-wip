# $NetBSD$

R_PKGNAME=	furrr
R_PKGVER=	0.3.1
CATEGORIES=	parallel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Apply mapping functions in parallel using futures
LICENSE=	mit

DEPENDS+=	R-globals>=0.14.0:../../devel/R-globals
DEPENDS+=	R-lifecycle>=1.0.1:../../devel/R-lifecycle
DEPENDS+=	R-purrr>=0.3.4:../../devel/R-purrr
DEPENDS+=	R-rlang>=1.0.2:../../devel/R-rlang
DEPENDS+=	R-vctrs>=0.4.1:../../math/R-vctrs
DEPENDS+=	R-future>=1.25.0:../../wip/R-future

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
