# $NetBSD: Makefile,v 1.1.1.1 2005/02/25 00:08:48 daprice Exp $
#

CATEGORIES=             math
MASTER_SITES=           ${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=             mchittur@cs.nmsu.edu
HOMEPAGE=               ${MASTER_SITE_R_CRAN:=contrib/Descriptions/Rcmdr.html}
COMMENT=		Platform-independent basic-statistics GUI for R

R_PKGNAME=              Rcmdr
R_PKGVER=               0.9-11

DEPENDS+=		tcl>=8.3:../../lang/tcl

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
