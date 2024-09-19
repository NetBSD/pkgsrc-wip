# $NetBSD$

R_PKGNAME=	oai
R_PKGVER=	0.3.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	General purpose 'Oai-PMH' services client
LICENSE=	mit

DEPENDS+=	R-plyr>=1.8.4:../../math/R-plyr
DEPENDS+=	R-tibble>=1.2:../../math/R-tibble
DEPENDS+=	R-stringr>=1.1.0:../../textproc/R-stringr
DEPENDS+=	R-xml2>=1.0.0:../../textproc/R-xml2
DEPENDS+=	R-httr>=1.2.0:../../www/R-httr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
