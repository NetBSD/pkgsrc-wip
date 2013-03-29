# $NetBSD: Makefile,v 1.11 2013/03/29 13:12:00 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.bnlearn.com/
COMMENT=	Bayesian network structure learning, parameter learning and inference
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	bnlearn
R_PKGVER=	3.3

USE_LANGUAGES=	c fortran

BUILDLINK_API_DEPENDS.R+=	R>=2.13.2

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
