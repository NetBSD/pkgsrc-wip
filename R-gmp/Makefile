# $NetBSD: Makefile,v 1.3 2013/03/19 01:22:55 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://cran.r-project.org/web/packages/gmp/
COMMENT=	Multiple Precision Arithmetic for R
LICENSE=	gnu-gpl-v2

R_PKGNAME=	gmp
R_PKGVER=	0.5-13.2

USE_LANGUAGES=	c c++

BUILDLINK_API_DEPENDS.gmp+=	gmp>=4.2.3

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
