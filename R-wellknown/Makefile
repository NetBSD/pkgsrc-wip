# $NetBSD$

R_PKGNAME=	wellknown
R_PKGVER=	0.7.4
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Convert between 'WKT' and 'GeoJSON'
LICENSE=	mit

DEPENDS+=	R-jsonlite>=1.7.1:../../textproc/R-jsonlite

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
