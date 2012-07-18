# $NetBSD: Makefile,v 1.6 2012/07/18 13:06:35 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.stat.washington.edu/mclust/
COMMENT=	Model-based clustering and normal mixture modeling

R_PKGNAME=	mclust
R_PKGVER=	3.4.8

BUILDLINK_API_DEPENDS.R+=	R>=2.2.0

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
