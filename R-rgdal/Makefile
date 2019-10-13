# $NetBSD: Makefile,v 1.7 2006/10/29 08:32:37 shattered Exp $
#

CATEGORIES=		databases math
MASTER_SITES=		${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=		mchittur@cs.nmsu.edu
COMMENT=		Provides bindings to GDAL and R

R_PKGNAME=		rgdal
R_PKGVER=		0.2-7

DEPENDS+=		gdal-lib>=1.1.9:../../geography/gdal-lib
DEPENDS+=		R-abind>=1.1.0:../../math/R-abind
DEPENDS+=		R-pixmap>=0.4.1:../../math/R-pixmap

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
