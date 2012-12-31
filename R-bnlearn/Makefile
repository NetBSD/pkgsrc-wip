# $NetBSD: Makefile,v 1.9 2012/12/31 20:03:09 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.bnlearn.com/
COMMENT=	Bayesian network structure learning, parameter learning and inference

R_PKGNAME=	bnlearn
R_PKGVER=	3.2

LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

USE_LANGUAGES=	c fortran

BUILDLINK_API_DEPENDS.R+=	R>=2.13.2

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/R-graph/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
