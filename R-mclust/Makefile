# $NetBSD: Makefile,v 1.9 2013/03/19 01:22:55 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	https://www.stat.washington.edu/mclust/
COMMENT=	Model-based clustering and normal mixture modeling
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	mclust
R_PKGVER=	4.0
PKGREVISION=	1

USE_LANGUAGES=	c fortran

BUILDLINK_API_DEPENDS.R+=	R>=2.13.0

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
