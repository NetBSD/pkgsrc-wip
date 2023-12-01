# $NetBSD$

R_PKGNAME=	elevatr
R_PKGVER=	0.99.0
CATEGORIES=	geography R

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Access elevation data from various APIs
LICENSE=	mit

DEPENDS+=	R-purrr>=1.0.1:../../devel/R-purrr
DEPENDS+=	R-raster>=3.4.13:../../geography/R-raster
DEPENDS+=	R-terra>=1.7.39:../../geography/R-terra
DEPENDS+=	R-units>=0.8.2:../../math/R-units
DEPENDS+=	R-jsonlite>=1.8.7:../../textproc/R-jsonlite
DEPENDS+=	R-future>=1.33.0:../../wip/R-future
DEPENDS+=	R-progressr>=0.11.0:../../wip/R-progressr
DEPENDS+=	R-curl>=5.0.0:../../www/R-curl
DEPENDS+=	R-httr>=1.4.6:../../www/R-httr
DEPENDS+=	R-slippymath>=0.3.1:../../wip/R-slippymath

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../geography/R-sf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
