# $NetBSD$

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Nonparametric Kernel Smoothing Methods for Mixed Data Types
# TODO: LICENSE=	GPL

R_PKGNAME=	np
R_PKGVER=	0.60-9

DEPENDS+=	R-cubature>=1.4:../../wip/R-cubature
DEPENDS+=	R-quadprog>=1.5.5:../../math/R-quadprog
DEPENDS+=	R-quantreg>=5.34:../../math/R-quantreg

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
