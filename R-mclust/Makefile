# $NetBSD: Makefile,v 1.3 2012/07/17 23:43:44 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.stat.washington.edu/mclust/
COMMENT=	Model-based clustering and normal mixture modeling

R_PKGNAME=	mclust
R_PKGVER=	3.4.8

USE_LANGUAGES=	fortran77

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../math/blas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
