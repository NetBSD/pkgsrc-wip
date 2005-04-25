# $NetBSD: Makefile,v 1.4 2005/04/25 20:37:13 daprice Exp $
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
DEPENDS+=		R-pixmap>=0.4.1:../../wip/R-pixmap

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
