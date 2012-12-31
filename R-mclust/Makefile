# $NetBSD: Makefile,v 1.8 2012/12/31 20:23:22 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.stat.washington.edu/mclust/
COMMENT=	Model-based clustering and normal mixture modeling

R_PKGNAME=	mclust
R_PKGVER=	4.0

LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

USE_LANGUAGES=	c fortran

BUILDLINK_API_DEPENDS.R+=	R>=2.13.0

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
