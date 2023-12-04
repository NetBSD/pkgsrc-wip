# $NetBSD$

R_PKGNAME=	marmap
R_PKGVER=	1.0.10
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Import, plot and analyze bathymetric and topographic data
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-geosphere>=1.5.14:../../geography/R-geosphere
DEPENDS+=	R-raster>=3.4.13:../../geography/R-raster
DEPENDS+=	R-ggplot2>=3.4.2:../../graphics/R-ggplot2
DEPENDS+=	R-DBI>=1.1.3:../../math/R-DBI
DEPENDS+=	R-ncdf4>=1.21:../../math/R-ncdf4
DEPENDS+=	R-reshape2>=1.4.4:../../math/R-reshape2

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../math/R-sp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
