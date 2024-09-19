# $NetBSD$

R_PKGNAME=	rgbif
R_PKGVER=	3.6.0
CATEGORIES=	biology

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Interface to the Global Biodiversity Information Facility API
LICENSE=	mit

DEPENDS+=	R-lazyeval>=0.2.2:../../devel/R-lazyeval
DEPENDS+=	R-magrittr>=2.0.1:../../devel/R-magrittr
DEPENDS+=	R-whisker>=0.4:../../devel/R-whisker
DEPENDS+=	R-ggplot2>=3.3.3:../../graphics/R-ggplot2
DEPENDS+=	R-tibble>=3.1.2:../../math/R-tibble
DEPENDS+=	R-data.table>=1.14.0:../../textproc/R-data.table
DEPENDS+=	R-jsonlite>=1.6:../../textproc/R-jsonlite
DEPENDS+=	R-xml2>=1.3.2:../../textproc/R-xml2

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
