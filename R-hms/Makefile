# $NetBSD$

CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/hms/
COMMENT=	Pretty Time of Day
LICENSE=	gnu-gpl-v3

R_PKGNAME=	hms
R_PKGVER=	0.4.2

DEPENDS+=	R-pkgconfig>=2.0.1:../../devel/R-pkgconfig
DEPENDS+=	R-rlang>=0.2.1:../../devel/R-rlang

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
