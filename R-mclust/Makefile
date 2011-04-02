# $NetBSD: Makefile,v 1.1.1.1 2011/04/02 19:09:30 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.stat.washington.edu/mclust/
COMMENT=	Model-based clustering and normal mixture modeling

R_PKGNAME=	mclust
R_PKGVER=	3.4.8

USE_LANGUAGES=	fortran77

.include "../../math/R/Makefile.extension"
.include "../../math/blas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
