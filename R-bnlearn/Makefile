# $NetBSD: Makefile,v 1.13 2015/03/02 14:31:25 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	https://www.bnlearn.com/
COMMENT=	Bayesian network structure learning, parameter learning and inference
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	bnlearn
R_PKGVER=	4.0

USE_LANGUAGES=	c fortran

BUILDLINK_API_DEPENDS.R+=	R>=2.14.0

.include "../../math/R/Makefile.extension"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
