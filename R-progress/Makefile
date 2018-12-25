# $NetBSD$

CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/progress/
COMMENT=	Configurable terminal-based progress bars
# TODO: LICENSE=	MIT + file LICENSE

R_PKGNAME=	progress
R_PKGVER=	1.2.0

DEPENDS+=	R-hms>=0.4.2:../../wip/R-hms
DEPENDS+=	R-prettyunits>=1.0.2:../../math/R-prettyunits
DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
