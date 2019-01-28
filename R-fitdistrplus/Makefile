# $NetBSD$

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	https://lbbe.univ-lyon1.fr/fitdistrplus.html
COMMENT=	Fit a Parametric Distribution to Non-Censored or Censored Data
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	fitdistrplus
R_PKGVER=	1.0-14

DEPENDS+=	R-npsurv>=0.4.0:../../wip/R-npsurv

BUILDLINK_API_DEPENDS.R+=	R>=3.2.0

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
