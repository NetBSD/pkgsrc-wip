# $NetBSD: Makefile,v 1.3 2005/03/31 20:37:29 daprice Exp $
#

CATEGORIES=             databases math
MASTER_SITES=           ${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=             mchittur@cs.nmsu.edu
HOMEPAGE=               ${MASTER_SITE_R_CRAN:=contrib/Descriptions/rgdal.html}
COMMENT=		Provides bindings to GDAL and R

R_PKGNAME=              rgdal
R_PKGVER=               0.2-7

DEPENDS+=		gdal>=1.1.9:../../wip/gdal
DEPENDS+=		R-abind>=1.1.0:../../wip/R-abind
DEPENDS+=		R-pixmap>=1.1.0:../../wip/R-pixmap

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
