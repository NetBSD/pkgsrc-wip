# $NetBSD: Makefile,v 1.3 2013/03/19 01:22:55 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://cran.r-project.org/web/packages/gmp/
COMMENT=	Multiple Precision Floating Point Arithmetic for R
LICENSE=	gnu-gpl-v2

R_PKGNAME=	Rmpfr
R_PKGVER=	0.7-1

USE_LANGUAGES=	c c++

DEPENDS+=	R-gmp>=0.5.13.2:../../wip/R-gmp
BUILDLINK_API_DEPENDS.mpfr+=	mpfr>=4.0.1

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
