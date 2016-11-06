# $NetBSD$
#

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/ncdf/
COMMENT=	High-level R interface to Unidata's netCDF data files
LICENSE=	gnu-gpl-v2

R_PKGNAME=	RNetCDF
R_PKGVER=	1.8-2


.include "../../math/R/Makefile.extension"
.include "../../devel/netcdf/buildlink3.mk"
.include "../../math/udunits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
